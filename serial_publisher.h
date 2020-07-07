#ifndef _SERIAL_PUBLISHER_H_
#define _SERIAL_PUBLISHER_H_
#include <Arduino.h>
#include "helper.h"
class SerialPublisher {

public:
    SerialPublisher(const String& topic, int freq);
    virtual void update(double val);
    static void publishData(void *context);
    double alpha;
private:
    String topic_name_;
    int frequency_, count_;

protected:
    double value_;
    void m_publish();

};

#endif //_SERIAL_PUBLISHER_H_
