#include "storage.hpp"


void _EEPROM_setup() noexcept {
    static bool isBegin{false};
    if (not isBegin) {
        EEPROM.begin(EEPROM_SIZE);
        _serial_setup();
    }
}


