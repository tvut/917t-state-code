void setForDrive(double velocity)
{
    setM(Left1,velocity);
    setM(Left2,velocity);
    setM(Right1,velocity);
    setM(Right2,velocity);
 
}
void autoTurn(double velocity) //-velocity is clockwise 
{
    setM(Left1,velocity);
    setM(Left2,velocity);
    setM(Right1,velocity);
    setM(Right2,velocity);
 
}
void getAvgs() {
    avgLeft = pi*2*(Left1.rotation(vex::rotationUnits::rev) + Left2.rotation(vex::rotationUnits::rev)); //av number of revs, 2*r*pi 
    avgRight = pi*2*(Right1.rotation(vex::rotationUnits::rev) + Right2.rotation(vex::rotationUnits::rev));   
}
float fakeGyro(){
    //take averages and convert to inches 
    //900 ticks/rev for 200 rpm 
    //use rev: convers
    /*avgLeft = pi*2*(LeftBD.rotation(vex::rotationUnits::rev) + LeftFD.rotation(vex::rotationUnits::rev)); //av number of revs, 2*r*pi 
    avgRight = pi*2*(RightBD.rotation(vex::rotationUnits::rev) + RightBD.rotation(vex::rotationUnits::rev));  */
    getAvgs();
    theta = (avgLeft-avgRight)/diameter;
    return theta;
    //theta = (L-R)/(diameter)
}
void turnPID(float turnGoal, float forTime) {
  float initDeg = fakeGyro(); 
	float integral = 0; //initialize integral term, error, range for integral limiting, prevError, constants, derivative, speed
	float error = 0;
	float integRange = 1.00;
	float prevError = 0;
	float kP = 115; 
	float kD = 0;
	float kI = 0;
	float deriv = 0;
	float speed = 0;
  float direction = 1;
	int timer = 0;
    
	while (timer < forTime) {
		error = turnGoal - (fakeGyro()-initDeg);
		if (error == 0) {
			integral = 0;
		}
		if (fabs(error) > integRange) {
			integral = 0;
		}
		integral += error;
		deriv = error - prevError;
		speed = error*kP + integral*kI + deriv*kD;
		autoTurn(-speed);
		prevError = error;
		timer += 30;
		vex::task::sleep(30);
        // if (timer % 600 == 0)
        // {
        // Brain.Screen.clearScreen();
        // Brain.Screen.setCursor(1, 1);
        //     //convert error to degrees: error*180/pi, * 10 
        // Brain.Screen.print(error*100000);
        // Brain.Screen.newLine();
        // Brain.Screen.print(error*kP);
        // Brain.Screen.newLine(); 
        // Brain.Screen.print(deriv*kD);
        // }
        
	}
	autoTurn(0);
}
void turnCCPID(float turnGoal, float forTime) {
  float initDeg = fakeGyro(); 
	float integral = 0; //initialize integral term, error, range for integral limiting, prevError, constants, derivative, speed
	float error = 0;
	float integRange = 1.00;
	float prevError = 0;
	float kP = 115; 
	float kD = 0;
	float kI = 0;
	float deriv = 0;
	float speed = 0;
  float direction = 1;
	int timer = 0;
    
	while (timer < forTime) {
		error = turnGoal - (fakeGyro()-initDeg);
		if (error == 0) {
			integral = 0;
		}
		if (fabs(error) > integRange) {
			integral = 0;
		}
		integral += error;
		deriv = error - prevError;
		speed = error*kP + integral*kI + deriv*kD;
		autoTurn(-speed);
		prevError = error;
		timer += 30;
		vex::task::sleep(30);
        if (timer % 600 == 0)
        {
        Brain.Screen.clearScreen();
        Brain.Screen.setCursor(1, 1);
            //convert error to degrees: error*180/pi, * 10 
        Brain.Screen.print(error*100000);
        Brain.Screen.newLine();
        Brain.Screen.print(error*kP);
        Brain.Screen.newLine(); 
        Brain.Screen.print(deriv*kD);
        }
        
	}
	autoTurn(0);
}
void driveBackwardPID(int driveGoal, float forTime) {
	float integral = 0; //initialize integral term, error, range for integral limiting, prevError, constants, derivative, speed
	float error = 0;
	int integRange = 14;
	float prevError = 0;
    //19.5
	float kP = 24.83;
    //20.3
	float kD = 9.28;
	float kI = 0;
	float deriv = 0;
	float speed = 0;
	int timer = 0;
	float avg;
  float initAvg = (avgRight + avgLeft)/2.0000;
	while (timer < forTime) {
            getAvgs();
			avg = (avgRight + avgLeft)/2;
			error = driveGoal - (avg - initAvg);
			if (error == 0) {
				integral = 0;
			}
			if (fabs(error) > integRange) {
				integral = 0;
			}
			integral += error;
			deriv = error - prevError;
			speed = error*kP + integral*kI + deriv*kD;
			setForDrive(speed);
			prevError = error;
			timer += 30;
      //   if (timer % 600 == 0)
      //   {
      //   Brain.Screen.clearScreen();
      //   Brain.Screen.setCursor(1, 1);
      //       //convert error to degrees: error*180/pi, * 10 
      //   Brain.Screen.print(error*100000);
      //   Brain.Screen.newLine();
      //   //Brain.Screen.print(error*kP);
      //   Brain.Screen.newLine(); 
      //   //Brain.Screen.print(deriv*kD);
      //    Brain.Screen.newLine(); 
      //   //Brain.Screen.print( (avg-initAvg));
      //        Brain.Screen.newLine(); 
      //   }
			task::sleep(30);
	}
	setForDrive(0);
}
void driveForwardPID(int driveGoal, float forTime) {
	float integral = 0; //initialize integral term, error, range for integral limiting, prevError, constants, derivative, speed
	float error = 0;
	int integRange = 15;
	float prevError = 0;
    //24.83
	float kP = 24.83;
    //12.7
	float kD = 9.28;
	float kI = 0;
	float deriv = 0;
	float speed = 0;
	int timer = 0;
	float avg;
    float initAvg = (avgRight + avgLeft)/2.0000;
	while (timer < forTime) {
            getAvgs();
			avg = (avgRight + avgLeft)/2;
			error = driveGoal - (avg - initAvg);
			if (error == 0) {
				integral = 0;
			}
			if (fabs(error) > integRange) {
				integral = 0;
			}
			integral += error;
			deriv = error - prevError;
			speed = error*kP + integral*kI + deriv*kD;
			setForDrive(speed);
			prevError = error;
			timer += 30;
        if (timer % 600 == 0)
        {
        Brain.Screen.clearScreen();
        Brain.Screen.setCursor(1, 1);
            //convert error to degrees: error*180/pi, * 10 
        Brain.Screen.print(error*100000);
        //Brain.Screen.newLine();
        //Brain.Screen.print(error*kP);
        Brain.Screen.newLine(); 
        //Brain.Screen.print(deriv*kD);
         Brain.Screen.newLine(); 
        Brain.Screen.print( (avg-initAvg));
             Brain.Screen.newLine(); 
        }
			task::sleep(30);
	}
	setForDrive(0);
}