typedef struct {        /* receiver raw data control type */
    gtime_t time;       /* message time */
    gtime_t tobs;       /* observation data time */
    obs_t obs;          /* observation data */
    obs_t obuf;         /* observation data buffer */
    nav_t nav;          /* satellite ephemerides */
    sta_t sta;          /* station parameters */
    int ephsat;         /* sat number of update ephemeris (0:no satellite) */
    sbsmsg_t sbsmsg;    /* SBAS message */
    char msgtype[256];  /* last message type */
    unsigned char subfrm[MAXSAT][380];  /* subframe buffer */
    lexmsg_t lexmsg;    /* LEX message */
    double lockt[MAXSAT][NFREQ+NEXOBS]; /* lock time (s) */
    double icpp[MAXSAT],off[MAXSAT],icpc; /* carrier params for ss2 */
    double prCA[MAXSAT],dpCA[MAXSAT]; /* L1/CA pseudrange/doppler for javad */
    unsigned char halfc[MAXSAT][NFREQ+NEXOBS]; /* half-cycle add flag */
    char freqn[MAXOBS]; /* frequency number for javad */
    int nbyte;          /* number of bytes in message buffer */ 
    int len;            /* message length (bytes) */
    int iod;            /* issue of data */
    int tod;            /* time of day (ms) */
    int tbase;          /* time base (0:gpst,1:utc(usno),2:glonass,3:utc(su) */
    int flag;           /* general purpose flag */
    int outtype;        /* output message type */
    unsigned char buff[MAXRAWLEN]; /* message buffer */
    char opt[256];      /* receiver dependent options */
    double receive_time;/* RT17: Reiceve time of week for week rollover detection */
    unsigned int plen;  /* RT17: Total size of packet to be read */
    unsigned int pbyte; /* RT17: How many packet bytes have been read so far */
    unsigned int page;  /* RT17: Last page number */
    unsigned int reply; /* RT17: Current reply number */
    int week;           /* RT17: week number */
    unsigned char pbuff[255+4+2]; /* RT17: Packet buffer */
} raw_t;
