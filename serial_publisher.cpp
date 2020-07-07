#include "serial_publisher.h"
extern SerialPublisher *publisher1, *publisher2, *publisher3, *publisher4;

SerialPublisher::SerialPublisher( const String &topic, int freq):topic_name_(topic) {
    this->frequency_ = 1000/freq;
    count_ = value_ = 0;
    alpha = 0.95;

}

void SerialPublisher::update(double val) {
    value_ = alpha * value_ + (1-alpha)*val;
    if(++count_>frequency_)
    {
        m_publish();
        count_ = 0;
    }

}

void SerialPublisher::m_publish() {
    Serial.print("[");
    Serial.print(topic_name_);
    Serial.print("]\t");
    Serial.println(value_);
}

void SerialPublisher::publishData(void *context) {
    int pin_number = (int)context;
    double data = analogRead(pin_number);
    switch (pin_number) {
        case PEDAL_SENSOR_ONE_PIN:publisher1->update(data);break;
        case PEDAL_SENSOR_TWO_PIN:publisher2->update(data);break;
        case STEER_SENSOR_ONE_PIN:publisher3->update(data);break;
        case STEER_SENSOR_TWO_PIN:publisher4->update(data);break;
        default:
            Serial.println(pin_number);break;
    }
}

