#define INC
//#define RAND


//#define TOE
//#define TOE_BE
//#define ADD
//#define XOR
#define MURMUR
//#define BOB

struct ipv4_5tuple {
        uint8_t  proto;
        uint32_t src_addr;
        uint32_t dst_addr;
        uint16_t sport;
        uint16_t dport;
};

uint64_t ctr = 0;

#ifdef INC
double tot_inter = 0;

static struct timespec ts;
#endif

#ifdef RAND
uint64_t ib[2] = {0,0};
#endif

/*
uint8_t rss_hash_default_key[] = {
        0x2c, 0xc6, 0x81, 0xd1,
        0x5b, 0xdb, 0xf4, 0xf7,
        0xfc, 0xa2, 0x83, 0x19,
        0xdb, 0x1a, 0x3e, 0x94,
        0x6b, 0x9e, 0x38, 0xd9,
        0x2c, 0x9c, 0x03, 0xd1,
        0xad, 0x99, 0x44, 0xa7,
        0xd9, 0x56, 0x3d, 0x59,
        0x06, 0x3c, 0x25, 0xf3,
        0xfc, 0x1f, 0xdc, 0x2a,
};
*/

uint8_t rss_hash_default_key[] = {
	0x6d, 0x5a, 0x56, 0xda, 0x25, 0x5b, 0x0e, 0xc2,
	0x41, 0x67, 0x25, 0x3d, 0x43, 0xa3, 0x8f, 0xb0,
	0xd0, 0xca, 0x2b, 0xcb, 0xae, 0x7b, 0x30, 0xb4,
	0x77, 0xcb, 0x2d, 0xa3, 0x80, 0x30, 0xf2, 0x0c,
	0x6a, 0x42, 0xb7, 0x3b, 0xbe, 0xac, 0x01, 0xfa,
};

uint8_t converted_key[RTE_DIM(rss_hash_default_key)];
