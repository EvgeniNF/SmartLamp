#pragma once

#include <cstdint>
#include <EEPROM.h>
#include <asserts.hpp>


#ifndef EEPROM_SIZE 

#define EEPROM_SIZE 4096

#endif


void _EEPROM_setup() noexcept;

template<bool commit=true, class T>
uint16_t EEPROM_write(uint16_t startAddress, T const &data) noexcept {
    _EEPROM_setup();

    EEPROM.put(startAddress, data);

    if constexpr (commit) {
        ASSERT_TRUE(EEPROM.commit());
    }
    
    uint16_t endAddress = startAddress + sizeof(T) + 1;
    return endAddress;
}

struct Array {
    static constexpr uint16_t size{20};
    uint16_t data[size];
    uint16_t len{0};
};

template<class... T>
Array EEPROM_smart_write(uint16_t startAddress, T const &...data) noexcept {
    _EEPROM_setup();

    Array addresses;
    
    (([&] () {
        auto const nextAddress = EEPROM_write<false>(startAddress, data);
        addresses.data[addresses.len] = startAddress;
        ++addresses.len;
        startAddress = nextAddress;
        ASSERT_NLESS(addresses.len, addresses.size);
    }), ...);

    ASSERT_TRUE(EEPROM.commit());
    return addresses;
}   

template<class T>
T EEPROM_read(uint16_t startAddress) noexcept {
    _EEPROM_setup();

    T value;
    EEPROM.get(startAddress, value);
    return value;
}

template<class... T>
void EEPROM_smart_read(uint16_t startAddress, T &...data) noexcept {
    _EEPROM_setup();

    (([&] () {
        data = EEPROM_read<T>(startAddress);
        startAddress = startAddress + sizeof(T) + 1;
    }()), ...);
}

template<class... T> 
Array compute_addresses(uint16_t startAddress) {
    Array addresses;
    
    (([&] () {
        addresses.data[addresses.len] = startAddress;
        startAddress += sizeof(T) + 1;
        ++addresses.len;
    }()), ...);

    return addresses;
}
