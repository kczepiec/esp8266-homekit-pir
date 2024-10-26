/*
 * wifi_info.h
 *
 */

#ifndef WIFI_INFO_H_
#define WIFI_INFO_H_

#if defined(ESP8266)
#include <ESP8266WiFi.h>
#elif defined(ESP32)
#include <WiFi.h>
#endif

const char *ssid = "WIFI SSID";
const char *password = "WIFI PASSWORD";

void wifi_connect() {
    WiFi.persistent(false);
    WiFi.mode(WIFI_STA);
    WiFi.setAutoReconnect(true);
    WiFi.begin(ssid, password);
    Serial.println("Connecting...");
    while (!WiFi.isConnected()) {
        delay(100);
        Serial.print(".");
    }
    Serial.print("\nConnected, IP: ");
    Serial.println(WiFi.localIP());
}

#endif /* WIFI_INFO_H_ */