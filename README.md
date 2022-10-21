# udacity_control

## Step 1: Build the PID controller object

![image](https://user-images.githubusercontent.com/7365421/197010504-597dfd54-fcaf-48c3-8cdd-d6d448707005.png)

## Step 2 and 3: Tuning the PID controllers for steering and throttle
### P only 
I first tried using P control only for both sterring and throttle (as recommended by various tuning methods, such as Ziegler-Nichols). The best result I got was with Kp = 0.31 for steering and Kp = 0.21 for throttle. The result is shown below. The car was able to make it down to the end of the street without any collisions. The steering error was quite low and oscillated. The throttle error was high, but if I increased Kp for throttle it made the car crash. It is tricky trying to tune two PID controllers at once because they are not independent. The steering and speed control loops are interdependent.

![image](https://user-images.githubusercontent.com/7365421/197274771-a0bb7fab-d25a-4026-a00f-a80bd288dfff.png)
![image](https://user-images.githubusercontent.com/7365421/197274889-8662b376-cca0-4f1c-a812-543a4a8a9def.png)
![image](https://user-images.githubusercontent.com/7365421/197275034-69e3d898-fc33-4364-9681-6a601ad95a8d.png)
