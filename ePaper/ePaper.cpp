// Include the standard types
#include <Arduino.h>
#include <ePaper.h>

#define BLACK_BG 1
#define WHITE_BG 0

unsigned int chars[95] =
{
//    abcdefgh          ijklmnop
    (B00000000 << 8) + B00000000, // (space)
    (B00000001 << 8) + B00000001, // !
    (B00000001 << 8) + B00010000, // "
    (B10111011 << 8) + B11011101, // #
    (B10011011 << 8) + B11011001, // $
    (B01011011 << 8) + B11011010, // %
    (B00010101 << 8) + B11011101, // &
    (B00000001 << 8) + B00000000, // `
    (B10000011 << 8) + B10000000, // (
    (B00000001 << 8) + B11000001, // )
    (B01010101 << 8) + B10101010, // *
    (B00010001 << 8) + B10001000, // +
    (B00000000 << 8) + B00000010, // ,
    (B00010000 << 8) + B00001000, // -
    (B00000000 << 8) + B00000001, // .
    (B01000000 << 8) + B00000010, // /
//    abcdefgh          ijklmnop
    (B10101010 << 8) + B01010101, // 0
    (B01101000 << 8) + B00000000, // 1
    (B10110010 << 8) + B01001101, // 2
    (B10111010 << 8) + B01000001, // 3
    (B00111000 << 8) + B00011000, // 4
    (B10000110 << 8) + B01011001, // 5
    (B10011010 << 8) + B01011101, // 6
    (B11000000 << 8) + B01000010, // 7
    (B10111010 << 8) + B01011101, // 8
    (B10111010 << 8) + B01011001, // 9
    (B00000000 << 8) + B01001000, // :
    (B00000000 << 8) + B01001010, // ;
    (B01000100 << 8) + B00000000, // <
    (B00010010 << 8) + B00001001, // =
    (B00000000 << 8) + B00100010, // >
    (B10110000 << 8) + B11000000, // ?
    (B10111010 << 8) + B11010101, // @
//    abcdefgh          ijklmnop
    (B10111000 << 8) + B01011100, // A
    (B10111011 << 8) + B11000001, // B
    (B10000010 << 8) + B01010101, // C
    (B10101011 << 8) + B11000001, // D
    (B10000010 << 8) + B01011101, // E
    (B10000000 << 8) + B01011100, // F
    (B10011010 << 8) + B01010101, // G
    (B00111000 << 8) + B00011100, // H
    (B10000011 << 8) + B11000001, // I
    (B00101010 << 8) + B00000101, // J
    (B01000100 << 8) + B00011100, // K
    (B00000010 << 8) + B00010101, // L
    (B01101000 << 8) + B00110100, // M
    (B00101100 << 8) + B00110100, // N
    (B10101010 << 8) + B01010101, // O
    (B10110000 << 8) + B01011100, // P
    (B10101110 << 8) + B01010101, // Q
    (B10110100 << 8) + B01011100, // R
    (B10011010 << 8) + B01011001, // S
    (B10000001 << 8) + B11000000, // T
    (B00101010 << 8) + B00010101, // U
    (B01000000 << 8) + B00010110, // V
    (B00101100 << 8) + B00010110, // W
    (B01000100 << 8) + B00100010, // X
    (B01000000 << 8) + B10100000, // Y
    (B11000010 << 8) + B01000011, // Z
    (B10000010 << 8) + B01010101, // [
    (B00000100 << 8) + B00100000, // 
    (B10101010 << 8) + B01000001, // ]
    (B00000100 << 8) + B00000010, // ^
    (B00000010 << 8) + B00000001, // _
    (B00000001 << 8) + B00000000, // `
//    abcdefgh          ijklmnop
    (B00000010 << 8) + B10001101, // a
    (B00000000 << 8) + B10011101, // b
    (B00000000 << 8) + B00001101, // c
    (B00000001 << 8) + B10001101, // d
    (B00000000 << 8) + B00001111, // e
    (B10010001 << 8) + B10001000, // f
    (B00000001 << 8) + B11011001, // g
    (B00000000 << 8) + B10011100, // h
    (B10000000 << 8) + B10000000, // i
    (B00000001 << 8) + B10000001, // j
    (B00010101 << 8) + B10000000, // k
    (B00000001 << 8) + B10000000, // l
    (B00011000 << 8) + B10001100, // m
    (B00011000 << 8) + B10001000, // n
    (B00000000 << 8) + B10001101, // o
    (B00000001 << 8) + B01011100, // p
    (B00000011 << 8) + B11011000, // q
    (B00010000 << 8) + B10000000, // r
    (B00010110 << 8) + B00000000, // s
    (B00010001 << 8) + B10001000, // t
    (B00000010 << 8) + B10000101, // u
    (B00000000 << 8) + B00000110, // v
    (B00001010 << 8) + B10000101, // w
    (B01000100 << 8) + B00100010, // x
    (B00000001 << 8) + B10011001, // y
    (B00000000 << 8) + B00001011, // z
    (B00000000 << 8) + B00000000, // {
    (B00000000 << 8) + B00000000, // |
    (B00000000 << 8) + B00000000, // }
    (B00000000 << 8) + B00000000  // ~*/
//    abcdefgh          ijklmnop
};

char topData[160];
char bottomData[160];

// Constructor
ePaper::ePaper(int EIO, int XCK, int LATCH, int SLPB, int DI0)
{
    _EIO = EIO;
    _XCK = XCK;
    _LATCH = LATCH;
    _SLPB = SLPB;
    _DI0 = DI0;

    pinMode(_EIO, OUTPUT);
    pinMode(_XCK, OUTPUT);
    pinMode(_LATCH, OUTPUT);
    pinMode(_SLPB, OUTPUT);
    pinMode(_DI0, OUTPUT);

    // Initial Pin Configurations -----------------------
    digitalWrite(_SLPB, HIGH);      // Sleep high turns the display on
    digitalWrite(_DI0, HIGH);         // Initialize data high
    digitalWrite(_XCK, LOW);
    digitalWrite(_EIO, HIGH);
    digitalWrite(_LATCH, LOW);
}

void ePaper::flipData(char * characterData)
{
    char a;
    for (int i=0; i<80; i++)
    {
        a = characterData[i];
        characterData[i] = characterData[159-i];
        characterData[159-i] = a;
    }
}

void ePaper::print(char * displayTop, char * displayBottom, int bw, int com)
{
    digitalWrite(_EIO, LOW);
    if (bw)
        digitalWrite(_DI0, HIGH);
    else
        digitalWrite(_DI0, LOW);
    delayMicroseconds(1);
    clock();     // Y0
    digitalWrite(_EIO, HIGH);

    for (int i = 0; i<160; i++)
    {
        if (bw)
        {
            if (displayBottom[i])
                digitalWrite(_DI0, LOW);
            else
                digitalWrite(_DI0, HIGH);
            delayMicroseconds(1);
            clock();
        }
        else
        {
            if (displayBottom[i])
                digitalWrite(_DI0, HIGH);
            else
                digitalWrite(_DI0, LOW);
            delayMicroseconds(1);
            clock();
        }
    }
    if (com)
        digitalWrite(_DI0, HIGH);
    else
        digitalWrite(_DI0, LOW);
    clock();     // Y161

    //--- 2nd display ---

    if (bw)
        digitalWrite(_DI0, HIGH);
    else
        digitalWrite(_DI0, LOW);
    clock();     // Y0

    for (int i = 0; i<160; i++)
    {
        if (bw)
        {
            if (displayTop[i])
                digitalWrite(_DI0, LOW);
            else
                digitalWrite(_DI0, HIGH);
            delayMicroseconds(1);
            clock();
        }
        else
        {
            if (displayTop[i])
                digitalWrite(_DI0, HIGH);
            else
                digitalWrite(_DI0, LOW);
            delayMicroseconds(1);
            clock();
        }
    }

    if (com)
        digitalWrite(_DI0, HIGH);
    else
        digitalWrite(_DI0, LOW);
    delayMicroseconds(1);
    clock();     // Y161

    latch();
}

void ePaper::clock()
{
    digitalWrite(_XCK, HIGH);
    delayMicroseconds(1);
    digitalWrite(_XCK, LOW);
    delayMicroseconds(1);
}

void ePaper::latch()
{
    digitalWrite(_LATCH, HIGH);
    delayMicroseconds(5);
    digitalWrite(_LATCH, LOW);
    delayMicroseconds(5);
}

void ePaper::writeNumberTop(long input)
{
    sprintf(topData, "%10ld", input);
    createData(topData, topData);
}

void ePaper::writeNumberBottom(long input)
{
    sprintf(bottomData, "%10ld", input);
    createData(bottomData, bottomData);
}

void ePaper::writeTop(char * characterData)
{
    sprintf(topData, "%-10s", characterData);
    createData(topData, topData);
}

void ePaper::writeBottom(char * characterData)
{
    sprintf(bottomData, "%-10s", characterData);
    createData(bottomData, bottomData);
}

void ePaper::writeDisplay()
{
    flipData(topData);  // If data is not flipped, it will look upside down.

    // in the following calls, use WHITE_BG for a white background or
    // BLACK_BG for a black background
    print(topData, bottomData, WHITE_BG, 1);
    delay(100);
    print(topData, bottomData, WHITE_BG, 1);
    delay(500);
    print(topData, bottomData, WHITE_BG, 0);
    delay(100);
    print(topData, bottomData, WHITE_BG, 0);
}

void ePaper::createData(char * characterData, char * toDisplay)
{
    for (int i=0; i<10; i++)
    {
        int n = chars[toDisplay[i]-32];
        for (int j=15; j>=0; j--)
        {
            characterData[(9-i)*16 + j] = n & 1;
            n = n >> 1;
        }
    }
}

