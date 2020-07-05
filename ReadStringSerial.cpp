//
// Created by mmisl on 7/4/2020.
//

#include "ReadStringSerial.h"

ReadStringSerial::ReadStringSerial() {
    inputString_ = "";         // a String to hold incoming data
    stringComplete_ = false;
    inputString_.reserve(200);

}

void ReadStringSerial::update() {
    m_serialEvent();
    if (stringComplete_) {
        data_=inputString_;
        Serial.println(inputString_);
        // clear the string:
        //inputString_ = "";
        stringComplete_ = false;
    }
}

void ReadStringSerial::m_serialEvent() {
    while (Serial.available()) {
        // get the new byte:
        char inChar = (char)Serial.read();
        // add it to the inputString:
        inputString_ += inChar;
        // if the incoming character is a newline, set a flag so the main loop can
        // do something about it:
        if (inChar == '\n') {
            stringComplete_ = true;
        }
    }

}

String ReadStringSerial::getdata() {

    return data_;
}
