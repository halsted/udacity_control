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
  tau_p = Kpi;
  tau_i = Kii;
  tau_d = Kdi;
  output_lim_max = output_lim_maxi;
  output_lim_min = output_lim_mini;
  prev_cte=0;  
  int_cte=0;
  diff_cte=0;
}


void PID::UpdateError(double cte) {
   /**
   * TODO: Update PID errors based on cte.
   **/
  this->cte = cte;
  if (dt>0) {
    diff_cte = (cte - prev_cte) / dt;
  } else {
    diff_cte = 0;
  }
  int_cte += cte*dt;
  prev_cte = cte;  
}

double PID::TotalError() {
   /**
   * TODO: Calculate and return the total error
    * The code should return a value in the interval [output_lim_mini, output_lim_maxi]
   */
    double control = tau_p*cte + tau_i*int_cte + tau_d*diff_cte;
    if (control < output_lim_min) {
      control = output_lim_min; 
    } else if (control > output_lim_max) {
      control = output_lim_max;
    }
    return control;
}

double PID::UpdateDeltaTime(double new_delta_time) {
   /**
   * TODO: Update the delta time with new value
   */
   dt = new_delta_time;
   return dt;
}