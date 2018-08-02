#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd)
{
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
  i_error = 0.0;
  total_cte = 0.0;
  return;
}

void PID::UpdateError(double cte)
{
  d_error = cte - p_error;  // p_error holds previous cte
  p_error = cte;
  i_error += cte;
  total_cte += cte * cte;
  return;
}

double PID::TotalError()
{
  return(total_cte);
}

double PID::Calculate()
{
  return(-(Kp * p_error + Ki * i_error + Kd * d_error));
}
