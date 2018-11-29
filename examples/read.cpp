#include <EEPROM.h>
#include <stdint.h>

#define EEPROM_UINT8_ADDR  0x00
#define EEPROM_UINT16_ADDR 0x01
#define EEPROM_UINT32_ADDR 0x02
#define EEPROM_FLOAT_ADDR  0x03

int main() {
    uint8_t value1  = EEPROM.readU08(EEPROM_UINT8_ADDR);
    uint16_t value2 = EEPROM.readU16(EEPROM_UINT8_ADDR);
    uint32_t value3 = EEPROM.readU32(EEPROM_UINT8_ADDR);
    float value4    = EEPROM.readFL(EEPROM_UINT8_ADDR);
}

