#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define POLY 0x1EDC6F41

uint32_t crc32c(uint32_t crc, uint8_t* input, size_t length)
{
    for (size_t i = 0; i < length; ++i)
    {
        crc = crc ^ input[i];
        for (int j = 0; j < 8; j++)
            crc = (crc >> 1) ^ 0x80000000 ^ ((~crc & 1) * POLY);
    }
    return crc;
}

