#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {  
  i_error=0.0;
  d_error=0.0;
  p_error=0.0;}

PID::~PID() {
  i_error=0.0;
  d_error=0.0;
  p_error=0.0;}

void PID::Init(double kp, double ki, double kd) {
  Kp=kp;
  Ki=ki;
  Kd=kd;
  i_error=0.0;
  d_error=0.0;
  p_error=0.0;
}

void PID::UpdateError(double cte) {
  d_error=cte-p_error;
  p_error=cte;
  i_error=i_error+cte;
}

double PID::TotalError() {
  double total_error=-(Kp * p_error) - (Kd * d_error) - (Ki * i_error);
  return total_error;
}

