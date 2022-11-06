#include <Arduino.h>
#include <asserts.hpp>
#include <storage.hpp>

void setup() {}

void loop() {
    auto const addresses = compute_addresses<uint16_t, uint16_t, char[20], uint8_t>(1);
    for (size_t i = 0; i < addresses.len; ++i) {
        LOG_INFO("start address: " << addresses.data[i]);
    }
    delay(2000);
}