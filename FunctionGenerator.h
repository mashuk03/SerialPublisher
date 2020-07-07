//
// Created by robor on 7/7/2020.
//

#ifndef SERIALPUBLISHER_FUNCTIONGENERATOR_H
#define SERIALPUBLISHER_FUNCTIONGENERATOR_H
#include "serial_publisher.h"
#include "ReadStringSerial.h"

class FunctionGenerator: public SerialPublisher {
    using InputFunc = double (*)(double);
public:
    FunctionGenerator(const String& topic, InputFunc func );
    static void callback(void *context);

    void update(double val) override;

private:
    float time_;
    const float dt = 0.1;
    InputFunc func_;

};


#endif //SERIALPUBLISHER_FUNCTIONGENERATOR_H
