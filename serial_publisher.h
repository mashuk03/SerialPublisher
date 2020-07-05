#ifndef _SERIAL_PUBLISHER_H_
#define _SERIAL_PUBLISHER_H_
#include <Arduino.h>
#include <Timer.h>
class SerialPublisher {

public:
    SerialPublisher(const String& topic, int freq);
    void update(double val);
    double alpha;
private:
    String topic_name_;
    int frequency_, count_;
    double value_;
protected:
    void m_publish();

};

#endif //_SERIAL_PUBLISHER_H_
