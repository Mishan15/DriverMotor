#include <DriverMotor.h>

driverMotor motor(5, 3, 4, 6, 9, 7);

void setup(){
    Serial.begin(9600);
    motor.drive(1, 150, 1, 150);
    delay(500);
    motor.drive(1, 100, 0, 100);
    delay(500);
    motor.drive(0, 100, 1, 100);
    delay(500);
    motor.drive(0, 100, 0, 100);
    delay(500);
    motor.stop();
}

void loop(){
    Serial.print("goodbay world");
}