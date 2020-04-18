//sets whole drive to a speed
void setForDrive(double velocity) {
  setM(Left1, velocity);
  setM(Left2, velocity);
  setM(Right1, velocity);
  setM(Right2, velocity);
}

//for turning, half of drive negative
void autoTurn(double velocity) //-velocity is clockwise
{
  setM(Left1, -velocity);
  setM(Left2, -velocity);
  setM(Right1, velocity);
  setM(Right2, velocity);
}

//averages each side of drive encoders
void getAvgs() {
  avgLeft =
      pi * 2 *
      (Left1.rotation(rev) + Left2.rotation(rev)); // av number of revs, 2*r*pi
  avgRight = pi * 2 * (Right1.rotation(rev) + Right2.rotation(rev));
}

//uses encoder values to get a theta
float fakeGyro() {
  // take averages and convert to inches
  // 900 ticks/rev for 200 rpm
  // use rev: convers
  /*avgLeft = pi*2*(LeftBD.rotation(rev) + LeftFD.rotation(rev)); //av number of
  revs, 2*r*pi
  avgRight = pi*2*(RightBD.rotation(rev) + RightBD.rotation(rev));  */
  getAvgs();
  theta = (avgLeft - avgRight) / diameter;
  return theta;
  // theta = (L-R)/(diameter)
}

//resets motor rotations
void resetMotors(){
  Left1.resetRotation();
  Left2.resetRotation();
  Right1.resetRotation();
  Right2.resetRotation();
}

//main turn function, takes all values
void turnPID(float turnGoal, float forTime, float maxSpeed, float kP, float kD, float kI,
             bool debug) {
  resetMotors();
  float initDeg = fakeGyro();
  float integral = 0; // initialize integral term, error, range for integral
                      // limiting, prevError, constants, derivative, speed
  float error = 0;
  float integRange = 15;
  float prevError = 0;
  float deriv = 0;
  float speed = 0;
  int timer = 0;
  int finaltime=0;

  while (timer < forTime) {
    error = turnGoal - (fakeGyro() - initDeg);
    if (error == 0) {
      integral = 0;
    }
    if (fabs(error) < .03)
      integral = 0;
    if (fabs(error) > integRange) {
      integral = integRange;
    }
    if(finaltime==0&&abs(error)<0.02)finaltime=timer;
    integral += error;
    deriv = error - prevError;
    speed = error * kP + integral * kI + deriv * kD;
    if(abs(speed)>maxSpeed){
      if(speed<0)speed=-maxSpeed;
      speed=maxSpeed;
    }
    autoTurn(-speed);
    prevError = error;
    timer += 30;
    task::sleep(30);
    //debug screen code
    if (debug && timer % 300 == 0) {
      if(finaltime==0){
      Controller1.Screen.clearScreen();
      Controller1.Screen.setCursor(1, 1);
      Controller1.Screen.print(error);
      Controller1.Screen.setCursor(2, 1);
      Controller1.Screen.print(integral);
      Controller1.Screen.setCursor(3, 1);
      Controller1.Screen.print(deriv);
      } else{
        Controller1.Screen.clearScreen();
        Controller1.Screen.setCursor(1, 1);
        Controller1.Screen.print(finaltime);
      }
    }
  }
  autoTurn(0);
  resetMotors();
}

//main drive forward function, takes all values
void drivePID(double driveGoal, float forTime, float maxSpeed, float kI, float kD, float kP,
              bool debug) {
  resetMotors();
  float integral = 0; // initialize integral term, error, range for integral
                      // limiting, prevError, constants, derivative, speed
  float error = 0;
  int integRange = 15;
  float prevError = 0;
  float deriv = 0;
  float speed = 0;
  int timer = 0;
  int finaltime=0;
  float avg;
  float initAvg = (avgRight + avgLeft) / 2.0000;
  while (timer < forTime) {
    getAvgs();
    avg = (avgRight + avgLeft) / 2;
    error = driveGoal - (avg - initAvg);
    if (error == 0) {
      integral = 0;
    }
    if (fabs(error) > integRange) {
      integral = 0;
    }
    if(finaltime==0&&abs(error)<0.05)finaltime=timer;
    integral += error;
    deriv = error - prevError;
    speed = error * kP + integral * kI + deriv * kD;
    if(abs(speed)>maxSpeed){
      if(speed<0)speed=-maxSpeed;
      else speed=maxSpeed;
    }
    setForDrive(speed);
    prevError = error;
    timer += 30;
    //debug screen code
    if (debug && timer % 300 == 0) {
      if(finaltime==0){
      Controller1.Screen.clearScreen();
      Controller1.Screen.setCursor(1, 1);
      Controller1.Screen.print(error);
      Controller1.Screen.setCursor(2, 1);
      Controller1.Screen.print(integral);
      Controller1.Screen.setCursor(3, 1);
      Controller1.Screen.print(deriv);
      } else{
        Controller1.Screen.clearScreen();
        Controller1.Screen.setCursor(1, 1);
        Controller1.Screen.print(finaltime);
      }
    }

    task::sleep(30);
  }
  setForDrive(0);
  resetMotors();
}


//tuned turn pid
void turnC(float turnGoal, float forTime, float maxSpeed) {
  float kP = 40;
  float kD = 11;
  float kI = 0;
  turnPID(turnGoal, forTime, maxSpeed, kP, kD, kI, true);
}

//tuned forward pid
void driveForward(float driveGoal, float forTime, float maxSpeed) {
  //10
  float kP = 10.0;
  //5
  float kD = 5.0;
  float kI = 0.000;
  drivePID(driveGoal, forTime, maxSpeed, kI, kD, kP, true);
}

//full speed turn overload function
void turnC(float turnGoal, float forTime) {
  turnC(turnGoal,forTime,100);
}

//full speed drive overload functionS
void driveForward(float driveGoal, float forTime) {
  driveForward(driveGoal,forTime,100);
}