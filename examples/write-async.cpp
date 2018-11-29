// If you want to override EEPROM write buffer length you can define size before include header
#define EEPROM_WRITE_BUFFER_LENGTH 16

#include <EEPROM.h>
#include <stdint.h>

#define EEPROM_UINT8_ADDR  0x00
#define EEPROM_UINT16_ADDR 0x01
#define EEPROM_UINT32_ADDR 0x02
#define EEPROM_FLOAT_ADDR  0x03

void onWriteCompleted() {
    //TODO do something after EEPROM buffer written
}

int main() {
    EEPROM.start();// <-- Reset write buffer

    EEPROM.writeU08(EEPROM_UINT8_ADDR, 1);
    EEPROM.writeU16(EEPROM_UINT16_ADDR, 2);
    EEPROM.writeU32(EEPROM_UINT32_ADDR, 3);
    EEPROM.writeFL(EEPROM_FLOAT_ADDR, 4);

    EEPROM.setOnWriteCompleteHandler(onWriteCompleted);
    EEPROM.flush();// Write buffer to EEPROM in background
}

