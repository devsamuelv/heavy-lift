#include <Arduino.h>
#include <PID_v1.h>

#include "Controller.h"
#include "EDF.h"

/* ------------------------------------------------------------------------------- */
/*                 Notes: PID Input will be the y axis from the imu                */
/* ------------------------------------------------------------------------------- */

#define MAX_SPEED 10

#define THRUSTER_ONE_PIN 1
#define THRUSTER_TWO_PIN 2
#define THRUSTER_THREE_PIN 3

#define THRUSTER_FOUR_PIN 4
#define THRUSTER_FIVE_PIN 5
#define THRUSTER_SIX_PIN 6

#define THRUSTER_ANGLE_ONE_PIN 1
#define THRUSTER_ANGLE_TWO_PIN 2
#define THRUSTER_ANGLE_THREE_PIN 3

#define THRUSTER_ANGLE_FOUR_PIN 4
#define THRUSTER_ANGLE_FIVE_PIN 5
#define THRUSTER_ANGLE_SIX_PIN 6

bool TVC = true;

double input, output, setPoint;

//Define the aggressive and conservative Tuning Parameters
double aggKp = 4, aggKi = 0.2, aggKd = 1;
double consKp = 1, consKi = 0.05, consKd = 0.25;

EDF EDF_One(THRUSTER_ONE_PIN, THRUSTER_ANGLE_ONE_PIN, MAX_SPEED);
EDF EDF_Two(THRUSTER_TWO_PIN, THRUSTER_ANGLE_TWO_PIN, MAX_SPEED);
EDF EDF_Three(THRUSTER_THREE_PIN, THRUSTER_ANGLE_THREE_PIN, MAX_SPEED);

PID pid(&input, &output, &setPoint, consKp, consKi, consKd, DIRECT);
Controller controller;

void StopAll()
{
  EDF_One.Stop();
  EDF_Two.Stop();
  EDF_Three.Stop();
}

void StartAll(int _speed)
{
  EDF_One.SetSpeed(_speed);
  EDF_Two.SetSpeed(_speed);
  EDF_Three.SetSpeed(_speed);
}

void setup()
{
  // put your setup code here, to run once:
  StopAll();

  setPoint = 0;
}

void loop()
{
  // put your main code here, to run repeatedly:
  if (controller.isEnabled())
  {
    StartAll(5);
  }
}