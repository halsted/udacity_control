# udacity_control

## Step 1: Build the PID controller object

![image](https://user-images.githubusercontent.com/7365421/197010504-597dfd54-fcaf-48c3-8cdd-d6d448707005.png)

## Step 4: Tuning the PID controllers for steering and throttle and evaluating the PID efficiency
### P only 
I first tried using P control only for both sterring and throttle (as recommended by various tuning methods, such as Ziegler-Nichols). The best result I got was with Kp = 0.31 for steering and Kp = 0.21 for throttle. The result is shown below. The car was able to make it down to the end of the street without any collisions. The steering error was quite low and oscillated. The throttle error was high, but if I increased Kp for throttle it made the car crash. It is tricky trying to tune two PID controllers at once because they are not independent. The steering and speed control loops are interdependent.

![image](https://user-images.githubusercontent.com/7365421/197274771-a0bb7fab-d25a-4026-a00f-a80bd288dfff.png)
![image](https://user-images.githubusercontent.com/7365421/197274889-8662b376-cca0-4f1c-a812-543a4a8a9def.png)
![image](https://user-images.githubusercontent.com/7365421/197275034-69e3d898-fc33-4364-9681-6a601ad95a8d.png)

### PD

I next added D control (Kp = 0.31, Kd = 0.3 for steering, Kp = 0.21, Kd = 0.1 for throttle). I got an improvement in performance. The car made it to the end of the street and made a successful turn. I still have high errors in the speed control loop, but this is less critical than the steering control loop for safety and collision avoidance.

![image](https://user-images.githubusercontent.com/7365421/197277186-97190ec6-c2ee-4134-9363-6ac243d8365e.png)
![image](https://user-images.githubusercontent.com/7365421/197277245-1c7cf029-b1f7-49c0-a7e7-34f8a7a1e5f5.png)
![image](https://user-images.githubusercontent.com/7365421/197277330-5d570fc8-a001-496c-b533-24c08f9d16f2.png)

### PID 

I next added an I term to the steering and throttle control as shown in the commands below.
  pid_steer.Init(0.31, 0.0001, .3, 1.2, -1.2);
  
  pid_throttle.Init(0.21, 0.0001, .1, 1.0, -1.0);

I kept the I term small because the integral can degrade the system stability and cause oscillation, which I observed with higher values of Ki. The main benefit of the I term is to reduce steady-state error, and that was not a big problem with the controllers. The PID performance improved slightly over PD as shown in the car's position at the end of the street.

![image](https://user-images.githubusercontent.com/7365421/197279196-b03740c7-931a-4630-bc2a-3738e7157392.png)
![image](https://user-images.githubusercontent.com/7365421/197280289-e48aabf8-79ee-42d9-bf28-85bf06e80d2d.png)
![image](https://user-images.githubusercontent.com/7365421/197280344-5a077dd6-619d-4269-b166-016f69a73b71.png)

