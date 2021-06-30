class EDF
{
private:
  int currentSpeed;
  double maxSpeed;
  int id;

public:
  EDF(double, int, int);

  // SetSpeed Will Set The EDF Speed
  void SetSpeed(double);

  // Stop will stop the EDF
  void Stop();

  // Servo Max Angle is 180
  void SetAngle(double);

  // GetSpeed Returns CurrentSpeed OF the EDF
  int GetSpeed();
};