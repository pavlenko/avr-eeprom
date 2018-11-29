#include <EEPROM.h>
#include <stdint.h>

#define EEPROM_UINT8_ADDR  0x00
#define EEPROM_UINT16_ADDR 0x01
#define EEPROM_UINT32_ADDR 0x02
#define EEPROM_FLOAT_ADDR  0x03

int main() {
    EEPROM.writeU08(EEPROM_UINT8_ADDR, 1);  // <-- This call block program 8000+ cycles
    EEPROM.writeU16(EEPROM_UINT16_ADDR, 2); // <-- This call block program 2 * 8000+ cycles
    EEPROM.writeU32(EEPROM_UINT32_ADDR, 3); // <-- This call block program 4 * 8000+ cycles
    EEPROM.writeFL(EEPROM_FLOAT_ADDR, 4);   // <-- This call block program 4 * 8000+ cycles
}

