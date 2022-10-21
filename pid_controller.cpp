/**********************************************
 * Self-Driving Car Nano-degree - Udacity
 *  Created on: December 11, 2020
 *      Author: Mathilde Badoual
 **********************************************/

#include "pid_controller.h"
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kpi, double Kii, double Kdi, double output_lim_maxi, double output_lim_mini) {
   /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   **/
  Kp = Kpi;
  Ki = Kii;
  Kd = Kdi;
  output_lim_max = output_lim_maxi;
  output_lim_min = output_lim_mini;
  p_error=0;
  d_error=0;
  i_error=0;
  dt=0;
  dt1=0;
  dt2=0;
  cte1=0;
  cte2=0;
  cte3=0;
  saturated=0;
}


void PID::UpdateError(double cte) {
   /**
   * TODO: Update PID errors based on cte.
   **/
  double sum_dt;

  p_error = cte;
  sum_dt = dt+dt1+dt2;
  if (sum_dt > 0) {
    d_error = (cte - cte3) / sum_dt;
  } else {
    d_error = 0;
  }
  if (saturated == 0) {
  	i_error += cte*dt;
  }
  cte3 = cte2;
  cte2 = cte1;
  cte1 = cte;
}

double PID::TotalError() {
   /**
   * TODO: Calculate and return the total error
    * The code should return a value in the interval [output_lim_mini, output_lim_maxi]
   */
    double control = Kp*p_error + Ki*i_error + Kd*d_error;
    saturated=0;
    if (control < output_lim_min) {
      control = output_lim_min; 
      saturated=1;
    } else if (control > output_lim_max) {
      control = output_lim_max;
      saturated=1;
    }
    return control;
}

double PID::UpdateDeltaTime(double new_delta_time) {
   /**
   * TODO: Update the delta time with new value
   */
   dt2 = dt1;
   dt1 = dt;
   dt = new_delta_time;
   return dt;
}