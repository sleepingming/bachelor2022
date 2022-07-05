static int decode_srns(raw_t *raw)
{
	int type=U1(raw->buff+1);

	trace(3,"decode_srns: type=%02x len=%d\n",type,raw->len);

	sprintf(raw->msgtype,"NVS: type=%2d len=%3d",type,raw->len);

	switch (type) {
		case ID_XF5RAW: return decode_xf5raw_srns(raw);
		case ID_XF7EPH:  return decode_xf7eph (raw);
		default: break;
	}
    return 0;
}
