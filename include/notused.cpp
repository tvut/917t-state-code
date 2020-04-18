// Roller Toggle

// if (Lift.position(rev) < .25) {
//   if (Controller1.ButtonL2.pressing()) {
//     if (!rollerToggle)
//       rollerIn = !rollerIn;
//     rollerToggle = true;
//   } else if (Controller1.ButtonL1.pressing()) {
//     rollerToggle = false;
//   } else {
//     rollerToggle = false;
//   }
//   if (Controller1.ButtonL1.pressing()) {
//     roller(100);
//   } else if (rollerIn) {
//     roller(-100);
//   } else {
//     roller(0);
//   }
// } else {
//   if (Controller1.ButtonL2.pressing()) {
//     roller(-100);
//   } else if (Controller1.ButtonL1.pressing()) {
//     roller(50);
//   } else {
//     roller(0);
//   }
// }

// // 10 point red (incomplete)
  // Tray.setBrake(hold);
  // setM(Tray,-50);
  // wait(300,msec);
  // setM(Tray,0);
  // roller(-100);
  // driveForward(50, 2000, 50);
  // driveForward(-8, 600);
  // turnC(-.4,700);
  // driveForward(4, 600);
  // Left1.setBrake(hold);
  //  setM(Left1,-10);
  //  setM(Left2,0);
  //  setM(Right1,100);
  //  setM(Right2,100);
  //  wait(500,msec);
  //  setM(Left1,50);
  //  setM(Left2,50);
  //  wait(150,msec);
  //  setM(Left1,-40);
  //  setM(Left2,0);
  //  setM(Right1,100);
  //  setM(Right2,100);
  //  wait(1500,msec);
  //  Left1.setBrake(coast);
  //  drivePower(20);
  //  wait(2500,msec);
  //  turnC(-1, 1000);
  //  drivePower(100);
  //  wait(2000,msec);
  // // setM(Right1,100);
  // // setM(Right2,100);
  // // setM(Left1,-30);
  // // setM(Left2,-30);
  // // wait(300,msec);
  // // drivePower(100);
  // // wait(50,msec);
  // // setM(Left1,-40);
  // // setM(Left2,-40);
  // // wait(500,msec);
  // // setM(Left1,-10);
  // // setM(Left2,-10);
  // // wait(500,msec);
  // // drivePower(100);
  // // wait(500,msec);

  // // roller(-100);
  // // driveForward(36, 1300, 60);


//runs two line route

// sevenRedPreload();
  //   ///7 working ish
  // deploy();
  //   roller(-100);
  //   driveForward(27, 1100);
  //   turnC(-.73,800);
  //   driveForward(-31.5,1200);
  //   turnC(.75,800);
  //   driveForward(35, 1350,50);
  //   setM(Right1,100);
  //   setM(Right2,100);
  //   setM(Left1,15);
  //   setM(Left2,15);
  //   wait(500,msec);
  //   drivePower(10);
  //   wait(200,msec);
  //   drivePower(0);
  //   // turnC(-.35,500);
  //   // driveForward(7, 400);
  //   // driveForward(-30,1000);
  //   turnC(-2.3,1000);
  //   drivePower(100);
  //   wait(450,msec);
  //   cubeDump();

        // std::string overheated = "OH: ";
      // if (Left1.temperature() > 55)
      //   overheated = overheated + " L1";
      // if (Left2.temperature() > 55)
      //   overheated = overheated + " L2";
      // if (Right1.temperature() > 55)
      //   overheated = overheated + " R1";
      // if (Right2.temperature() > 55)
      //   overheated = overheated + " R2";
      // if (Lift.temperature() > 55)
      //   overheated = overheated + " L";
      // if (Tray.temperature() > 55)
      //   overheated = overheated + " T";
      // if (Roller1.temperature() > 55)
      //   overheated = overheated + " RO1";
      // if (Roller2.temperature() > 55)
      //   overheated = overheated + " RO2";
      // if (overheated != "OH: ") {
      //   Controller1.Screen.clearScreen();
      //   Controller1.Screen.setCursor(1, 1);
      //   Controller1.Screen.print(overheated.c_str());
      // } else {
      //   Controller1.Screen.clearScreen();
      // }

      // Controller1.Screen.setCursor(2, 1);
      // Controller1.Screen.print("Autos: ");
      // if(autosEnabled) Controller1.Screen.print("Yes");
      // else Controller1.Screen.print("No");
      // Controller1.Screen.setCursor(3, 1);
      // Controller1.Screen.print("Voltage: ");
      // Controller1.Screen.print(Brain.Battery.voltage());

      double stickMultZeroed(double stick) {
//   if(abs(stick)<120)return(.5*stick);
//   else if(stick<0)return ((6*(stick+120))-60);
//   return (6*(stick-120)+60);
// }
// //agressive x cubed curve
// double stickMultZeroedDefault(double stick) {
//   if (stick < 0)
//     return (-pow(abs(stick), 3) / 10000.0);
//   return (pow(abs(stick), 3) / 10000.0);
//   // return stick;
// }
// //quadratic curve - heavy emphasis around 40s
// double stickMultZeroed(double stick) {
//   if(stick< 0)
//   return(-(1000*pow(abs(stick)/150,4)-650*pow(abs(stick)/140,3)+abs(stick)));
//   return(1000*pow(abs(stick)/150,4)-650*pow(abs(stick)/140,3)+abs(stick));
// }
// //reduced sensitivity
// double stickMultZeroedbad(double stick) {
//   if(stick< 0)
//   return(-(1000*pow(abs(stick)/190,4)-650*pow(abs(stick)/179,3)+pow(abs(stick)/17,2)+(abs(stick)*3/5)));
//   return(1000*pow(abs(stick)/190,4)-650*pow(abs(stick)/179,3)+pow(abs(stick)/17,2)+(abs(stick)*3/5));
// }
// //quadratic curve - more lower sensitivity
// double stickMultZeroedSecondQuadratic(double stick) {
//   if(stick< 0)
//   return(-(1000*pow(abs(stick)/180,4)-650*pow(abs(stick)/179,3)+(.7*abs(stick))));
//   return(1000*pow(abs(stick)/180,4)-650*pow(abs(stick)/179,3)+(.7*abs(stick)));
// }
// double stickMultZeroedOld(double stick) {
//   if (stick < 0)
//     return (-pow(abs(stick), 1.7) / 25.0);
//   return (pow(stick, 1.7) / 25.0);
// }

// double stickMult(double stick) {
//   // if (stick < 0)
//   //   return (-pow(abs(stick), 1.9) / 70.0 + 10);
//   // return (pow(stick, 1.9) / 70.0 + 10);
//   return stick;
// }
// double stickMultAgressive(double stick) {
//   return (pow(stick, 2.5) / 1100.0 + 10);
// }


// void tank(int threshold) {
//   int L = Controller1.Axis3.value();
//   int R = Controller1.Axis2.value();
//   if (abs(L) < threshold)
//     L = 0;
//   if (abs(R) < threshold)
//     R = 0;
//   // if(abs(L-R)<15){
//   //   if (abs((L + R) / 2)<threshold)drivePower(0);
//   //   else
//   //     drivePower(stickMultZeroed(
//   //         (L + R) / 2));
//   // } else

//   // if ((L < -threshold && R < -threshold) || (L > threshold && R > threshold))
//   // {
//   int diff = (L - R) / 3.25;
//   if (Right2.temperature() > 65 || Left2.temperature() > 65) {
//     diff = 0;
//   } else if (diff > 30)
//     diff = 30;
//   else if (diff < -30)
//     diff = -30;
//   setM(Left1, (L - diff));
//   setM(Left2, (L - diff));
//   setM(Right1, (R + diff));
//   setM(Right2, (R + diff));
//   // // } else if ((L < -100 && R > 100) || (L > 100 && R < -100)) {
//   //   setM(Left1, stickMultZeroed(L));
//   //   setM(Left2, stickMultZeroed(L));
//   //   setM(Right1, stickMultZeroed(R));
//   //   setM(Right2, stickMultZeroed(R));
//   //   Controller1.Screen.setCursor(2, 1);
//   //     Controller1.Screen.print(stickMultZeroed(L));

//   //   Controller1.Screen.setCursor(3, 1);
//   //     Controller1.Screen.print(stickMultZeroed(R));
//   // } else {
//   //   int diff = (L - R) / 3;
//   //   setM(Left1, stickMultZeroed(L - diff));
//   //   setM(Left2, stickMultZeroed(L - diff));
//   //   setM(Right1, stickMultZeroed(R + diff));
//   //   setM(Right2, stickMultZeroed(R + diff));
//   // }
// }
