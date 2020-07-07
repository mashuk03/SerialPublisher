//
// Created by robor on 7/7/2020.
//

#include "FunctionGenerator.h"
extern FunctionGenerator * sinWave, *cosWave;
extern ReadStringSerial RSS;

FunctionGenerator::FunctionGenerator(const String &topic, FunctionGenerator::InputFunc func) :SerialPublisher(topic,1), func_(func){
    time_ = 0;
}

void FunctionGenerator::callback(void *context) {
    int type = (int)context;
    switch (type) {
        case 1:sinWave->update(type);break;
        case 2: cosWave->update(type);break;
    }
}

void FunctionGenerator::update(double val) {
    float A = RSS.getdata(int(val));
    float B = 1.5;
    float D = A;
    const float C = 2.3;
    time_ += dt;
    value_ = A * func_(B*(time_+C)) + D;
    m_publish();
}
