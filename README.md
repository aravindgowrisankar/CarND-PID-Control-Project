# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## SETUP

Please refer to the [SETUP](./SETUP.md) file for requirements & installation instructions.

## Implementation

The code [PID.cpp](./src/PID.cpp) contains a very simple implementation of the PID controller.

Each of the three components Proportional,Iintegral and Ddifferential play a role in the functioning of the controller.

The [UpdateError()](https://github.com/aravindgowrisankar/CarND-PID-Control-Project/blob/master/src/PID.cpp#L28) takes in the CTE(cross track error) provided by the Udacity simulation and computes the three types of errors.

The [TotalError()](https://github.com/aravindgowrisankar/CarND-PID-Control-Project/blob/master/src/PID.cpp#L34) computes the steering angle using the different errors by weighing them by the appropriate constant.


+ **P**roportional Error - This is the same as the CTE

The Proportional Error is the starting point, it relies on the CTE and provides a basic idea of how much the controller needs to be adjusted.

+ **D**ifferential Error - This is the difference between the current CTE and the previous CTE

The Differential error helps avoid overshoot and oscillations.

+ **I**ntegral Error - This is the sum of all CTEs since the beginning of the evaluation

The Integral error helps account for any biases that we have about the car(e.g. steering wheels are aligned perfectly)

## Reflection

### Values chosen
The parameters are set [here](https://github.com/aravindgowrisankar/CarND-PID-Control-Project/blob/master/src/main.cpp#L38)

* Proportional Factor Kp = 0.2
* Integral Factor Ki=   0.004
* Differential Factor Kd= 3.0

The first thing I tried was to use the defaults from the Udacity lesson on PID Controller. 

Surprisingly, this seems to result in a controller that can complete a lap without leaving the track.

### Area of improvement: 

+ Use of Twiddle

I haven't had a chance to play with the parameters that much. So, there is room for experimentation here.
There are portions of the lap where the controller/car oscillates a little bit. To me this suggests that the default Kd parameter is not optimal.
I think using something like co-ordinate ascent(twiddle) can help find a better set of parameters.

+ Steering Value normalization

Surprisingly, I didn't have to normalize the steering value to the -1 to 1 range as mentioned in the comments.

+ Adding another controller for the Speed

Setting up a separate controller for the speed seems like a really fun experiment to try.

