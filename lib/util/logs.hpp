#pragma once

#include <iostream>
#include <Arduino.h>

#ifndef SERIAL_LOG_BAUD_RATE

#define SERIAL_LOG_BAUD_RATE 115200

#endif

static void _serial_setup() noexcept {
    static bool isBegin{false};
    if (not isBegin) {
        Serial.begin(SERIAL_LOG_BAUD_RATE);
        isBegin = true;
    }
}

#define _LOG(logLevel, message) \
    _serial_setup(); \
    std::cout << '[' << micros() << "] " << '[' << logLevel << "] " << message << std::endl

#define LOG_ERROR(message) \
    _serial_setup(); \
    _LOG("Error", message)

#define LOG_WARNING(message) \
    _serial_setup(); \
    _LOG("Warning", message)

#define LOG_INFO(message) \
    _serial_setup(); \
    _LOG("Info", message)

