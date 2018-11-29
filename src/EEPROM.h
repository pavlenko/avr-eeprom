#ifndef EEPROM_H
#define EEPROM_H

#include <avr/interrupt.h>
#include <stdint.h>

#ifndef EEPROM_WRITE_BUFFER_LENGTH
#define EEPROM_WRITE_BUFFER_LENGTH 8
#endif

ISR(EE_RDY_vect);

class EEPROMClass
{
    friend void EE_RDY_vect();
private:
    void (*_onWriteCompleteHandler) ();
public:
    /**
     * @param address
     * @return
     */
    uint8_t readU08(uint16_t address);

    /**
     * @param address
     * @return
     */
    uint16_t readU16(uint16_t address);

    /**
     * @param address
     * @return
     */
    uint32_t readU32(uint16_t address);

    /**
     * @param address
     * @return
     */
    float readFL(uint16_t address);

    /**
     * @param address
     * @param value
     */
    void writeU08(uint16_t address, uint8_t value);

    /**
     * @param address
     * @param value
     */
    void writeU16(uint16_t address, uint16_t value);

    /**
     * @param address
     * @param value
     */
    void writeU32(uint16_t address, uint32_t value);

    /**
     * @param address
     * @param value
     */
    void writeFL(uint16_t address, float value);

    /**
     * Reset write buffer before write
     */
    void start();

    /**
     * Write buffer to EEPROM
     */
    void flush();

    /**
     * @param handler_ptr
     */
    void setOnWriteCompleteHandler(void (*handler_ptr) ());
};

extern EEPROMClass EEPROM;

#endif //EEPROM_H
