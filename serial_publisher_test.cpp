#include <Arduino.h>
#include "serial_publisher.h"
#include <Timer.h>
#include "helper.h"
#include "ReadStringSerial.h"
#include "FunctionGenerator.h"

Timer t;
SerialPublisher *publisher1, *publisher2, *publisher3, *publisher4;
ReadStringSerial RSS;
FunctionGenerator * sinWave, *cosWave;

void serialEvent()
{
    RSS.update();
}
void setup() {
    Serial.begin(BAUD_RATE);
    while (!Serial);
    publisher1 = new SerialPublisher("/PEDAL_SENSOR_ONE", 100);
    publisher2 = new SerialPublisher("/PEDAL_SENSOR_TWO", 100);
    publisher3 = new SerialPublisher("/STEER_SENSOR_ONE_PIN", 100);
    publisher4 = new SerialPublisher("/STEER_SENSOR_TWO_PIN", 100);
    t.every(SENSOR_INPUT_INTERVAL, SerialPublisher::publishData, (void *)PEDAL_SENSOR_ONE_PIN);
    t.every(SENSOR_INPUT_INTERVAL, SerialPublisher::publishData, (void *)PEDAL_SENSOR_TWO_PIN);
    t.every(SENSOR_INPUT_INTERVAL, SerialPublisher::publishData, (void *)STEER_SENSOR_ONE_PIN);
    t.every(SENSOR_INPUT_INTERVAL, SerialPublisher::publishData, (void *)STEER_SENSOR_TWO_PIN);

    sinWave = new FunctionGenerator("/SINEWAVE", sin);
    cosWave = new FunctionGenerator("/COSWAVE", sin);

    t.every(51, FunctionGenerator::callback, (void *)1);
    t.every(50, FunctionGenerator::callback, (void *)2);
}

void loop() {
    t.update();

}
