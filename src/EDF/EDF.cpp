#include <Arduino.h>
#include <PID_v1.h>
#include <Servo.h>
#include <ESC.h>

#include "EDF.h"

class EDF
{
private:
  int id;
  int servoId;
  int currentSpeed = 0;

  double maxSpeed;
  double currentAngle;

  ESC esc;
  Servo servo;

public:
  EDF(int _id, double _maxSpeed, int _servoId)
  {
    id = _id;
    servoId = _servoId;
    maxSpeed = maxSpeed;

    esc.attach(id);
    servo.attach(servoId);
  }

  int GetSpeed()
  {
    return currentSpeed;
  }

  void SetAngle(int _angle)
  {
    currentAngle = _angle;
    servo.write(_angle);
  }

  void Stop()
  {
    currentSpeed = 0;
    esc.setSpeed(0);
  }

  void SetSpeed(int _speed)
  {
    if (_speed < maxSpeed)
    {
      currentSpeed = _speed;
      esc.setSpeed(_speed);
    }
    else
    {
      currentSpeed = maxSpeed;
      esc.setSpeed(maxSpeed);
    }
  }
};
