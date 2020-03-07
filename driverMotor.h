#pragma once
#include <Arduino.h>

class driverMotor{
    public:
        driverMotor(byte leftM1, byte leftM2, byte rightM1, byte rightM2); // инициализация поумолчанию. 
        driverMotor(byte leftM1, byte leftM2, byte leftMS, byte rightM1, byte rightM2, byte rightMS, bool use_as_def = 1); // инициализвция для 6-пинового интерфейса. 
        void drive(bool directionLeft, byte speedLeft, bool directionRight, byte speedRight);
        void stop();
    private:
        byte _leftM1, _leftM2, _rightM1, _rightM2, _leftMS, _rightMS;
        byte _driver_type = 0;
};

