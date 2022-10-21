/**********************************************
 * Self-Driving Car Nano-degree - Udacity
 *  Created on: December 11, 2020
 *      Author: Mathilde Badoual
 **********************************************/

#ifndef PID_CONTROLLER_H
#define PID_CONTROLLER_H

class PID {
public:

   /**
   * TODO: Create the PID class
   **/
  
    /*
    * Errors
    */
   double p_error;	// cte at n
   double d_error;	// derivative error
   double i_error;	// integral error
   double cte1;		// cte at n-1
   double cte2;		// cte at n-2
   double cte3;		// cte at n-3
   bool saturated;	// flag if control output saturated
  
    /*
    * Coefficients
    */
   double Kp;
   double Ki;
   double Kd;

    /*
    * Output limits
    */
   double output_lim_max;
   double output_lim_min;
  
    /*
    * Delta time
    */
   double dt;		// current dt at n
   double dt1;		// dt at n-1
   double dt2;		// dt an n-2
    /*
    * Constructor
    */
    PID();

    /*
    * Destructor.
    */
    virtual ~PID();

    /*
    * Initialize PID.
    */
    void Init(double Kp, double Ki, double Kd, double output_lim_max, double output_lim_min);

    /*
    * Update the PID error variables given cross track error.
    */
    void UpdateError(double cte);

    /*
    * Calculate the total PID error.
    */
    double TotalError();
  
    /*
    * Update the delta time.
    */
    double UpdateDeltaTime(double new_delta_time);
};

#endif //PID_CONTROLLER_H


