//
// Created by mmisl on 7/4/2020.
//

#include "ReadStringSerial.h"

ReadStringSerial::ReadStringSerial() {
    for (int i = 0; i < NUM_DACS; ++i) {
        incomingByte[i] = 0;
    }
    data_arrieved_ = false;
}

void ReadStringSerial::update() {
    m_serialEvent();
    if(data_arrieved_)
    {
        if(data_<256)
        {
            incomingByte[0] = data_;
            analogWrite(pwmPin1, incomingByte[0]);
        }
        else if(data_<512)
        {
            incomingByte[1] = data_ - 256;
            analogWrite(pwmPin2, incomingByte[1]);
        }
        else if(data_<768)
            incomingByte[2] = data_ - 512;
        else if(data_<1024)
            incomingByte[3] = data_ - 768;
        data_arrieved_ = false;
    }

}

void ReadStringSerial::m_serialEvent() {

    String inputString = "";
    while (Serial.available()) {
        // get the new byte:
        char inChar = (char)Serial.read();
        if (inChar == '\n')
        {
            data_arrieved_ = true;
            data_ = inputString.toInt();
            break;
        }
        else
            // add it to the inputString:
            inputString += inChar;
    }

}

int ReadStringSerial::getdata(int id) {

    return (id>0 && id<=NUM_DACS)?incomingByte[id-1]:-1;
}
