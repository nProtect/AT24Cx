/**

AT24CX.h
Library for using the EEPROM AT24C32/64

Copyright (c) 2014 Christian Paul

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

 */
#ifndef AT24CX_h
#define AT24CX_h

// includes
#include <Arduino.h>

// byte
typedef uint8_t byte;

// AT24Cx I2C address
// 80
// 0x50
#define AT24CX_ID B1010000

// general class definition
class AT24CX {
public:
	AT24CX();
	AT24CX(byte index, byte pageSize);

	//Write Functions
	void write(unsigned int address, byte data);
	void write(unsigned int address, byte *data, int n);
	void writeInt(unsigned int address, unsigned int data);
	void writeLong(unsigned int address, unsigned long data);
	void writeFloat(unsigned int address, float data);
	void writeDouble(unsigned int address, double data);
	void writeChars(unsigned int address, char *data, int length);

	//Read Functions
	byte read(unsigned int address);
	void read(unsigned int address, byte *data, int n);
	unsigned int readInt(unsigned int address);
	unsigned long readLong(unsigned int address);
	float readFloat(unsigned int address);
	double readDouble(unsigned int address);
	void readChars(unsigned int address, char *data, int n);

	bool update(unsigned int address, byte data);
	bool updateInt(unsigned int address, unsigned int data);
	bool updateLong(unsigned int address, unsigned long data);
	bool updateFloat(unsigned int address, float data);
	bool updateDouble(unsigned int address, double data);
	bool updateChars(unsigned int address, char* data, int length);

protected:
	void init(byte index, byte pageSize);

private:
	void startWireIfNeeded();
	void read(unsigned int address, byte *data, int offset, int n);
	void write(unsigned int address, byte *data, int offset, int n);
	int _id;
	byte _b[8];
	byte _pageSize;
	byte _wireLibStarted;
};

// AT24C32 class definition
class AT24C32 : public AT24CX {
public:
	AT24C32();
	AT24C32(byte index);
};

// AT24C64 class definition
class AT24C64 : public AT24CX {
public:
	AT24C64();
	AT24C64(byte index);
};

// AT24C128 class definition
class AT24C128 : public AT24CX {
public:
	AT24C128();
	AT24C128(byte index);
};

// AT24C256 class definition
class AT24C256 : public AT24CX {
public:
	AT24C256();
	AT24C256(byte index);
};

// AT24C512 class definition
class AT24C512 : public AT24CX {
public:
	AT24C512();
	AT24C512(byte index);
};



#endif
