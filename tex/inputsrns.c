extern int input_srns(raw_t *raw, unsigned char data)
{
    if ((raw->nbyte == 0) && (data == SRNSSYNC1)) {
        raw->buff[0] = 0x10;
        raw->nbyte = 1;
		raw->size = 0;
		raw->type = 0;
        return 0;
    }

    if (raw->nbyte == 1 && raw->flag == 0) {
		if (data == SRNSSYNC2) {
        	raw->flag = -6;
		} else {
			raw->nbyte = 0;
		}
        return 0;
    }

	if (raw->flag >= -6 && raw->flag < 0) {
		switch (raw->flag) {
		case -4:
			raw->size |= data;
			break;
		case -3:
			raw->size |= ((uint16_t)data) << 8;
			raw->size *= 4;
			break;
		case -2:
			raw->type |= (((uint8_t)data) << 4) >> 4;
			break;
		case -1:
			raw->type |= ((uint16_t)data) << 4;
			raw->buff[1] = raw->type;
			raw->nbyte = 2;
			break;
		case -6:
			break;
		case -5:
			break;
		};
		raw->flag++;
		return 0;
	}

	if (raw->size > 0) {
		raw->buff[raw->nbyte++] = data;
		raw->size--;
		if (raw->size == 0) {
			raw->len = raw->nbyte - 4;
			raw->nbyte = 0;
			raw->size = 0;

			return decode_srns(raw);
		}
	}
    return 0;
}
