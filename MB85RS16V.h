#ifndef MB85RS16V_H
#define MB85RS16V_H
#include <Arduino.h>
#include <SPI.h>

#define _READ  0x03
#define _WREN  0x06
#define _WRITE 0x02
class MB85RS16V
{
	public:
		MB85RS16V(void);
		void begin();
		void begin(byte cs_pin);
		uint8_t read  (uint16_t framAddr);
		void read (uint16_t framAddr,uint8_t num,uint8_t data[]);
		void read (uint16_t framAddr,uint8_t num,char data[]);
		void write (uint16_t framAddr, uint8_t value);
		void write (uint16_t framAddr, uint8_t length,uint8_t data[]);
		void write (uint16_t framAddr,uint8_t length, char data[]);
		void update(uint16_t framAddr, uint8_t value);
		void update (uint16_t framAddr, uint8_t length,uint8_t data[]);
		void update (uint16_t framAddr,uint8_t length, char data[]);
		uint32_t RAID();
	private:
		byte _cs_pin = SS;
};

#endif

