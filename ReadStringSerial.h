//
// Created by mmisl on 7/4/2020.
//

#ifndef SERIALPUBLISHER_READSTRINGSERIAL_H
#define SERIALPUBLISHER_READSTRINGSERIAL_H
#include <Arduino.h>

class ReadStringSerial {
public:
    ReadStringSerial();
    void update();
    String getdata();

protected:
    void m_serialEvent();

private:
    String inputString_;         // a String to hold incoming data
    bool stringComplete_;  // whether the string is complete
    String data_;
};


#endif //SERIALPUBLISHER_READSTRINGSERIAL_H
