#include "serial_publisher.h"
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

