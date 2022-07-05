#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

struct SRNS_Packet {
	uint16_t preambule;
	uint16_t sender;
	uint16_t size;
	uint16_t number;
	uint8_t counter;

	uint8_t* payload;

	uint32_t crc;
};

int main(int argc, char** argv)
{
	FILE* file;
	file = fopen(argv[1], "rb");

	struct SRNS_Packet packet;
	while (fread(&packet.preambule, 2, 1, file)) {
		if (packet.preambule == 0x5253) {
			fread(&packet.sender, 2, 1, file);
			fread(&packet.size, 2, 1, file);
			fread(&packet.number, 2, 1, file);
			packet.counter = packet.number & 0xf;
			packet.number >>= 4;

			packet.payload = malloc(4 * packet.size);
			fread(packet.payload, 1, 4 * packet.size, file);
			fread(&packet.crc, 4, 1, file);
			free(packet.payload);
		}
	}
	fclose(file);
	return 0;
}
