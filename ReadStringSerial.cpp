//
// Created by mmisl on 7/4/2020.
//

#include "ReadStringSerial.h"

ReadStringSerial::ReadStringSerial() {
    for (int i = 0; i < NUM_DACS; ++i) {
        incomingByte[i] = 1;
    }
    data_arrieved_ = false;
}

void ReadStringSerial::update() {
    m_serialEvent();
//    if(data_arrieved_)
//    {
//        int value = data_ - T2;
//        int id = (data_ - value) / T2;
//        if (id>0 && id<=NUM_DACS)
//            incomingByte[id-1] = value;
//        data_arrieved_ = false;
//    }

}

void ReadStringSerial::m_serialEvent() {

    if (Serial.available() > 0) {
        // read the incoming byte:
        data_ = (int)Serial.read();
        if (data_>99)
            incomingByte[1] = data_;
        else
            incomingByte[0] = data_;
        data_arrieved_ = true;
    }

}

int ReadStringSerial::getdata(int id) {

    return (id>0 && id<=NUM_DACS)?incomingByte[id-1]:-1;
}
