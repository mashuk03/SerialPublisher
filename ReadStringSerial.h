//
// Created by mmisl on 7/4/2020.
//

#ifndef SERIALPUBLISHER_READSTRINGSERIAL_H
#define SERIALPUBLISHER_READSTRINGSERIAL_H
#include <Arduino.h>
#define NUM_DACS 4
#define T2 100

class ReadStringSerial {
public:
    ReadStringSerial();
    void update();
    int getdata(int);
    int incomingByte[NUM_DACS];

protected:
    void m_serialEvent();

private:
    bool data_arrieved_;
    int data_;
    const int pwmPin1 = 12;
    const int pwmPin2 = 13;

};


#endif //SERIALPUBLISHER_READSTRINGSERIAL_H
