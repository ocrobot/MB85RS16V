#include "MB85RS16V.h"

MB85RS16V::MB85RS16V(void)
{
	
}

void MB85RS16V::begin()
{
  pinMode (_cs_pin, OUTPUT);
  SPI.begin();
  SPI.setBitOrder(MSBFIRST);
  SPI.setDataMode (SPI_MODE0);
  SPI.setClockDivider(SPI_CLOCK_DIV2);
}

uint8_t MB85RS16V::read  (uint16_t framAddr)
{
	byte buffer;
	digitalWrite(_cs_pin,LOW);
	SPI.transfer(_READ);
	SPI.transfer(framAddr / 256);  //地址高位
	SPI.transfer(framAddr % 256); //地址低位
    buffer = SPI.transfer(0x00);	//获取数据
	digitalWrite(_cs_pin,HIGH);
	return buffer;
}

void MB85RS16V::write (uint16_t framAddr, uint8_t value)
{
	digitalWrite(_cs_pin,LOW);
	SPI.transfer(_WREN);      //写指令使能
	digitalWrite(_cs_pin,HIGH);

	digitalWrite(_cs_pin,LOW);
	SPI.transfer(_WRITE);  // 写存储
	SPI.transfer(framAddr / 256);  //地址
	SPI.transfer(framAddr % 256);
	SPI.transfer(value);    //写入内容
	digitalWrite(_cs_pin,HIGH);
}




//返回芯片ID
uint32_t MB85RS16V::RAID()
{
	byte data[4];
	uint32_t _ID;
	digitalWrite(_cs_pin,LOW);
	SPI.transfer(0x9f);
	data[0] = SPI.transfer(0x00);
	data[1] = SPI.transfer(0x00);
	data[2] = SPI.transfer(0x00);
	data[3] = SPI.transfer(0x00);
	digitalWrite(_cs_pin,HIGH);
	_ID = ((uint32_t)data[0]<<24) +((uint32_t)data[1]<<16) + ((uint32_t)data[2]<<8) +(uint32_t)data[3] ;
	return _ID;
}