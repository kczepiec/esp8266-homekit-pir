#include <homekit/homekit.h>
#include <homekit/characteristics.h>

void my_accessory_identify(homekit_value_t _value) {
    printf("Accessory identify\n");
}

homekit_characteristic_t cha_motion_detected = HOMEKIT_CHARACTERISTIC_(MOTION_DETECTED, false);

homekit_characteristic_t cha_name = HOMEKIT_CHARACTERISTIC_(NAME, "Motion Sensor");

homekit_accessory_t *accessories[] = {
    HOMEKIT_ACCESSORY(.id=1, .category=homekit_accessory_category_sensor, .services=(homekit_service_t*[]) {
        HOMEKIT_SERVICE(ACCESSORY_INFORMATION, .characteristics=(homekit_characteristic_t*[]) {
            HOMEKIT_CHARACTERISTIC(NAME, "Motion Sensor"),
            HOMEKIT_CHARACTERISTIC(MANUFACTURER, "ESP8266 HomeKit"),
            HOMEKIT_CHARACTERISTIC(SERIAL_NUMBER, "XXXXXXXXX"),
            HOMEKIT_CHARACTERISTIC(MODEL, "ESP8266"),
            HOMEKIT_CHARACTERISTIC(FIRMWARE_REVISION, "1.0"),
            HOMEKIT_CHARACTERISTIC(IDENTIFY, my_accessory_identify),
            NULL
        }),
        HOMEKIT_SERVICE(MOTION_SENSOR, .primary=true, .characteristics=(homekit_characteristic_t*[]) {
            &cha_motion_detected,
            &cha_name,
            NULL
        }),
        NULL
    }),
    NULL
};

homekit_server_config_t config = {
    .accessories = accessories,
    .password = "111-11-111"
};