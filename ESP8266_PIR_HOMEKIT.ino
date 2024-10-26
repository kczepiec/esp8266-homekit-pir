#include <Arduino.h>
#include <arduino_homekit_server.h>
#include "wifi_info.h"

#define LOG_D(fmt, ...)   printf_P(PSTR(fmt "\n") , ##__VA_ARGS__);

extern "C" homekit_server_config_t config;
extern "C" homekit_characteristic_t cha_motion_detected;

#define PIN_MOTION_SENSOR D1
bool last_motion_state = false;

void setup() {
    Serial.begin(115200);
    wifi_connect();
    
    my_homekit_setup();
    pinMode(PIN_MOTION_SENSOR, INPUT);
}

void loop() {
    my_homekit_loop();

    bool motion_detected = digitalRead(PIN_MOTION_SENSOR) == HIGH;
    if (motion_detected != last_motion_state) {
        cha_motion_detected.value.bool_value = motion_detected;
        homekit_characteristic_notify(&cha_motion_detected, cha_motion_detected.value);
        LOG_D("Motion Sensor: %s", motion_detected ? "Motion Detected" : "No Motion");
        last_motion_state = motion_detected;
    }
}

//==============================
// HomeKit setup and loop
//==============================

void my_homekit_setup() {
    arduino_homekit_setup(&config);
}

void my_homekit_loop() {
    arduino_homekit_loop();
    static uint32_t next_heap_millis = 0;
    const uint32_t t = millis();
    if (t > next_heap_millis) {
        next_heap_millis = t + 5 * 1000;
        LOG_D("Free heap: %d, HomeKit clients: %d",
                ESP.getFreeHeap(), arduino_homekit_connected_clients_count());
    }
}