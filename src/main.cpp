#include <Arduino.h>
#include <asserts.hpp>
#include <storage.hpp>

void setup() {
    LOG_BEGINE();
}

void loop() {
    EEPROM_smart_write(0, "hello", "world", "I'm", "Here");
    delay(1000);
}