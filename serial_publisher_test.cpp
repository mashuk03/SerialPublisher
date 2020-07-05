#include <Arduino.h>
#include "serial_publisher.h"
#include <Timer.h>
#include "helper.h"
#include "ReadStringSerial.h"

Timer t;
SerialPublisher *publisher1, *publisher2, *publisher3, *publisher4;
ReadStringSerial RSS;

void publishData(void *context)
{
    int pin_number = (int)context;
    double data = analogRead(pin_number) * (5.0 / 1023.0);
    switch (pin_number) {
        case PEDAL_SENSOR_ONE_PIN:publisher1->update(data);break;
        case PEDAL_SENSOR_TWO_PIN:publisher2->update(data);break;
        case STEER_SENSOR_ONE_PIN:publisher3->update(data);break;
        case STEER_SENSOR_TWO_PIN:publisher4->update(data);break;
        default:
            Serial.println(pin_number);break;
    }
}


void setup() {
    Serial.begin(BAUD_RATE);
    publisher1 = new SerialPublisher("/PEDAL_SENSOR_ONE", 100);
    publisher2 = new SerialPublisher("/PEDAL_SENSOR_TWO", 100);
    publisher3 = new SerialPublisher("/STEER_SENSOR_ONE_PIN", 100);
    publisher4 = new SerialPublisher("/STEER_SENSOR_TWO_PIN", 100);
    t.every(SENSOR_INPUT_INTERVAL, publishData, (void *)PEDAL_SENSOR_ONE_PIN);
    t.every(SENSOR_INPUT_INTERVAL, publishData, (void *)PEDAL_SENSOR_TWO_PIN);
    t.every(SENSOR_INPUT_INTERVAL, publishData, (void *)STEER_SENSOR_ONE_PIN);
    t.every(SENSOR_INPUT_INTERVAL, publishData, (void *)STEER_SENSOR_TWO_PIN);
}

void loop() {
    t.update();
    RSS.update();
}
