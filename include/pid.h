void setForDrive(double velocity)
{
    setM(Left1,velocity);
    setM(Left2,velocity);
    setM(Right1,velocity);
    setM(Right2,velocity);
 
}
void autoTurn(double velocity) //-velocity is clockwise 
{
    setM(Left1,-velocity);
    setM(Left2,-velocity);
    setM(Right1,velocity);
    setM(Right2,velocity);
 
}
void getAvgs() {
    avgLeft = pi*2*(Left1.rotation(rev) + Left2.rotation(rev)); //av number of revs, 2*r*pi 
    avgRight = pi*2*(Right1.rotation(rev) + Right2.rotation(rev));   
}
float fakeGyro(){
    //take averages and convert to inches 
    //900 ticks/rev for 200 rpm 
    //use rev: convers
    /*avgLeft = pi*2*(LeftBD.rotation(rev) + LeftFD.rotation(rev)); //av number of revs, 2*r*pi 
    avgRight = pi*2*(RightBD.rotation(rev) + RightBD.rotation(rev));  */
    getAvgs();
    theta = (avgLeft-avgRight)/diameter;
    return theta;
    //theta = (L-R)/(diameter)
}
void turnPID(float turnGoal, float forTime) {
  float initDeg = fakeGyro(); 
	float integral = 0; //initialize integral term, error, range for integral limiting, prevError, constants, derivative, speed
	float error = 0;
	float integRange = 2.0;
	float prevError = 0;
	float kP = 80; 
	float kD = 40;
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
    if(fabs(error)<.03)integral=0;
		if (fabs(error) > integRange) {
			integral = integRange;
		}
		integral += error;
		deriv = error - prevError;
		speed = error*kP + integral*kI + deriv*kD;
		autoTurn(-speed);
		prevError = error;
		timer += 30;
		task::sleep(30);
        // Controller1.Screen.clearScreen();
        // Controller1.Screen.setCursor(1, 1);
        // Controller1.Screen.print(error);
        // Controller1.Screen.setCursor(2, 1);
        // Controller1.Screen.print(integral);
        // Controller1.Screen.setCursor(3, 1);
        // Controller1.Screen.print(deriv);
         
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
		task::sleep(30);
        if (timer % 600 == 0)
        {
        // Controller1.Screen.clearScreen();
        // Controller1.Screen.setCursor(1, 1);
        // Controller1.Screen.print(error);
        }
         
	}
	autoTurn(0);
}
void driveBackwardPID(double driveGoal, float forTime) {
	float integral = 0; //initialize integral term, error, range for integral limiting, prevError, constants, derivative, speed
	float error = 0;
	int integRange = 14;
	float prevError = 0;
  float kP = 6.85;
	float kD = 9.5;
	float kI = 0.0;
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
        // Controller1.Screen.clearScreen();
        // Controller1.Screen.setCursor(1, 1);
        // Controller1.Screen.print(error); 
        }
         
			task::sleep(30);
	}
	setForDrive(0);
}
void driveForwardPID(double driveGoal, float forTime) {
	float integral = 0; //initialize integral term, error, range for integral limiting, prevError, constants, derivative, speed
	float error = 0;
	int integRange = 15;
	float prevError = 0;
    //11.58
	float kP = 6.35;
    //12.7
	float kD = 6.5;
	float kI = 0.0020;
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
        // Controller1.Screen.clearScreen();
        // Controller1.Screen.setCursor(1, 1);
        // Controller1.Screen.print(error);
        }
       
			task::sleep(30);
	}
	setForDrive(0);
}