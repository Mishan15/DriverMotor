#include "driverMotor.h"


driverMotor::driverMotor(byte leftM1, byte leftM2, byte rightM1, byte rightM2){
    _leftM1 = leftM1;
    _leftM2 = leftM2;
    _rightM1 = rightM1;
    _rightM2 = rightM2;
    pinMode(_leftM1, OUTPUT);
    pinMode(_leftM2, OUTPUT);
    pinMode(_rightM1, OUTPUT);
    pinMode(_rightM2, OUTPUT);
    digitalWrite(_leftM1, LOW);
    digitalWrite(_leftM2, LOW);
    digitalWrite(_rightM1, LOW);
    digitalWrite(_rightM2, LOW);
    _driver_type = 0;
}

driverMotor::driverMotor(byte leftDr, byte leftSpd, byte rightDr, byte rightSpd, char type){
    if(type == 'a'){
        _leftSpd = leftSpd;
        _rightSpd = rightSpd;
        _leftDr = leftDr;
        _rightDr = rightDr;
        pinMode(_leftDr, OUTPUT);
        pinMode(_leftSpd, OUTPUT);
        pinMode(_rightDr, OUTPUT);
        pinMode(_rightSpd, OUTPUT);
        digitalWrite(_leftSpd, LOW);
        digitalWrite(_rightSpd, LOW);
        _driver_type = 2;
    }
}

driverMotor::driverMotor(byte leftM1, byte leftM2, byte leftMS, byte rightM1, byte rightM2, byte rightMS, bool use_as_def = 1){
    _leftM1 = leftM1;
    _leftM2 = leftM2;
    _rightM1 = rightM1;
    _rightM2 = rightM2;
    pinMode(_leftM1, OUTPUT);
    pinMode(_leftM2, OUTPUT);
    pinMode(_rightM1, OUTPUT);
    pinMode(_rightM2, OUTPUT);
    pinMode(leftMS, OUTPUT); 
    pinMode(rightMS, OUTPUT); 
    digitalWrite(_leftM1, LOW);
    digitalWrite(_leftM2, LOW);
    digitalWrite(_rightM1, LOW);
    digitalWrite(_rightM2, LOW);
    if(use_as_def) {
        _driver_type = 0;
        digitalWrite(leftMS, HIGH);
        digitalWrite(rightMS, HIGH);
    }else{
        _driver_type = 1;
    }
}

void driverMotor::drive(bool directionLeft, byte speedLeft, bool directionRight, byte speedRight){
    if(_driver_type == 0){
        if(directionLeft){
            digitalWrite(_leftM1, LOW);
            analogWrite(_leftM2, speedLeft);
        }else{
            digitalWrite(_leftM2, LOW);
            analogWrite(_leftM1, speedLeft);
        }

        if(directionRight){
            digitalWrite(_rightM1, LOW);
            analogWrite(_rightM2, speedRight);
        }else{
            digitalWrite(_rightM2, LOW);
            analogWrite(_rightM1, speedRight);
        }
    }else if(_driver_type == 1){
        if(directionLeft){
            digitalWrite(_leftM1, LOW);
            digitalWrite(_leftM2, HIGH);
            analogWrite(_leftMS, speedLeft);
        }else{
            digitalWrite(_leftM1, HIGH);
            digitalWrite(_leftM2, LOW);
            analogWrite(_leftMS, speedLeft);
        }

        if(directionRight){
            digitalWrite(_rightM1, LOW);
            digitalWrite(_rightM2, HIGH);
            analogWrite(_rightMS, speedRight);
        }else{
            digitalWrite(_rightM1, HIGH);
            digitalWrite(_rightM2, LOW);
            analogWrite(_rightMS, speedRight);
        }
    }else if(_driver_type == 2){
        if(directionLeft){
            digitalWrite(_leftDr, HIGH);
            analogWrite(_leftSpd, speedLeft);
        }else{
            digitalWrite(_leftDr, LOW);
            analogWrite(_leftSpd, speedLeft);
        }

        if(directionRight){
            digitalWrite(_rightDr, HIGH);
            analogWrite(_rightSpd, speedLeft);
        }else{
            digitalWrite(_rightDr, LOW);
            analogWrite(_rightSpd, speedLeft);
        }
    }
}

void driverMotor::stop(){
    if(_driver_type == 0){
        digitalWrite(_leftM1, LOW);
        digitalWrite(_leftM2, LOW);
        digitalWrite(_rightM1, LOW);
        digitalWrite(_rightM2, LOW);
    }else{
        digitalWrite(_leftM1, LOW);
        digitalWrite(_leftM2, LOW);
        digitalWrite(_rightM1, LOW);
        digitalWrite(_rightM2, LOW);
    }
}