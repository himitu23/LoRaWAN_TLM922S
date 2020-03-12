/***************
 *
 * LoRaWAN_TLM922S_Table.cpp
 *
 * release site: https://github.com/askn37/LoRaWAN_TLM922S
 * maintainer: askn https://twitter.com/askn37
 *
 */

#include <Arduino.h>
#include <avr/pgmspace.h>
#include "LoRaWAN_TLM922S_Table.h"

const PROGMEM uint32_t PS_DICT[] = {
	0x004f0143U, 0x0065019aU, 0x006f014bU, 0x00660154U, 0x00390199U, 0x00690125U, 0x00720103U, 0x006f016dU,
	0x006c019fU, 0x006501a3U, 0x003c0020U, 0x006f0170U, 0x003e0187U, 0x005f0160U, 0x00720143U, 0x0070012dU,
	0x040a012aU, 0x006f0177U, 0x0061017aU, 0x00320104U, 0x00610175U, 0x00610181U, 0x006b0143U, 0x01200187U,
	0x0073019dU, 0x00690129U, 0x11210142U, 0x00720150U, 0x00730109U, 0x006e0123U, 0x00650106U, 0x004c0194U,
	0x006301a2U, 0x006e0126U, 0x00320113U, 0x00690143U, 0x0078019eU, 0x006c0115U, 0x006b015cU, 0x00650116U,
	0x005f012eU, 0x006e0130U, 0x003c018eU, 0x00440143U, 0x006f0190U, 0x00650120U, 0x0065011eU, 0x1373011cU,
	0x00690151U, 0x1768014cU, 0x00660184U, 0x0077014eU, 0x00620143U, 0x00750134U, 0x006f019cU, 0x1879014dU,
	0x0065012bU, 0x00740185U, 0x0062015eU, 0x0078010eU, 0x0079016eU, 0x006e0144U, 0x0b640179U, 0x006e0146U,
	0x006e0147U, 0x0074018dU, 0x0064017bU, 0x0220010cU, 0x00490143U, 0x006d0192U, 0x00690167U, 0x00770162U,
	0x00750143U, 0x006e0148U, 0x006f01a0U, 0x006e0143U, 0x00630128U, 0x00730135U, 0x00650141U, 0x0073013cU,
	0x00650143U, 0x005f01a5U, 0x0047013aU, 0x005f015fU, 0x005f0102U, 0x006a0153U, 0x006f0155U, 0x00530122U,
	0x00690156U, 0x0075015dU, 0x003d0176U, 0x0c640195U, 0x006e0161U, 0x00730149U, 0x004e0143U, 0x00740102U,
	0x0064019bU, 0x00550143U, 0x006f0121U, 0x0076011dU, 0x006e0158U, 0x00650164U, 0x005f0114U, 0x00670171U,
	0x19640165U,          0U, 0x003d0186U, 0x004d0198U, 0x0074010fU, 0x006a0143U, 0x00610133U, 0x086b0100U,
	0x006a0149U, 0x007201a6U, 0x0720013bU, 0x10640105U, 0x14640101U, 0x00740112U, 0x0020013fU, 0x005f0124U,
	0x00200140U, 0x0065016cU, 0x0064010dU, 0x006e0182U, 0x006c0166U, 0x0e6e0184U, 0x00610143U, 0x00630159U,
	0x0a6b0111U, 0x0076013dU, 0x00610145U, 0x006e018aU, 0x006f0143U, 0x00670183U, 0x0020014fU, 0x003e000dU,
	0x006e018fU, 0x0f660132U, 0x0065017cU, 0x15680139U, 0x005f0118U, 0x00610152U, 0x00200157U, 0x00690107U,
	0x006d0138U, 0x0520015aU, 0x006d0136U, 0x1272011bU, 0x00540117U, 0x00650188U, 0x0069010bU, 0x030a010aU,
	0x0064012cU, 0x004d011fU, 0x006e0196U, 0x00690108U, 0x00630178U, 0x00790127U, 0x00740143U, 0x00610163U,
	0x006e018cU, 0x0620016aU, 0x0063017eU, 0x0063017fU, 0x16740119U, 0x0074014aU, 0x0061016bU
};

const PROGMEM uint8_t CMD_DICT[] = {
    0x67U, 0x13U, 0x03U,     0x6fU, 0x6dU, 0x00U,     0x20U, 0x45U, 0x01U,     0x20U, 0xf9U, 0x01U,	// 0x0100, 9
    0x65U, 0x2eU, 0x03U,     0x76U, 0xb3U, 0x02U,     0x65U, 0xc6U, 0x01U,     0x6aU, 0x13U, 0x03U,	// 0x010c, 21
    0x73U, 0x13U, 0x03U,     0x76U, 0x1aU, 0x02U,     0x64U, 0x57U, 0x01U,     0x0dU, 0x60U, 0x01U,	// 0x0118, 33
    0x61U, 0xe1U, 0x01U,     0x6fU, 0x81U, 0x01U,     0x64U, 0x95U, 0x02U,     0x74U, 0x13U, 0x03U,	// 0x0124, 45
    0x70U, 0x7aU, 0x02U,     0x61U, 0x1fU, 0x03U,     0x20U, 0x6fU, 0x01U,     0x77U, 0xceU, 0x02U,	// 0x0130, 57
    0x20U, 0xe3U, 0x02U,     0x72U, 0x5fU, 0x02U,     0x0dU, 0xc0U, 0x01U,     0x64U, 0x03U, 0x01U,	// 0x013c, 69
    0x5fU, 0xbfU, 0x02U,     0x70U, 0x6dU, 0x00U,     0x65U, 0xfcU, 0x01U,     0x65U, 0xc9U, 0x01U,	// 0x0148, 81
    0x6fU, 0xdaU, 0x02U,     0x64U, 0x8dU, 0x01U,     0x6bU, 0xb7U, 0x01U,     0x6fU, 0x1fU, 0x03U,	// 0x0154, 93
    0x61U, 0xcbU, 0x02U,     0x72U, 0x72U, 0x01U,     0x79U, 0x49U, 0x03U,     0x64U, 0xd2U, 0x01U,	// 0x0160, 105
    0x5fU, 0xa1U, 0x02U,     0x78U, 0x2dU, 0x01U,     0x64U, 0x5cU, 0x02U,     0x0dU, 0x56U, 0x02U,	// 0x016c, 117
    0x20U, 0x19U, 0x03U,     0x70U, 0x48U, 0x01U,     0x69U, 0x10U, 0x03U,     0x20U, 0x5eU, 0x03U,	// 0x0178, 129
    0x61U, 0x2bU, 0x03U,     0x72U, 0x3aU, 0x03U,     0x0dU, 0x2cU, 0x02U,     0x61U, 0x0fU, 0x01U,	// 0x0184, 141
    0x72U, 0x1eU, 0x01U,     0x70U, 0x86U, 0x02U,     0x74U, 0xf5U, 0x02U,     0x74U, 0x17U, 0x02U,	// 0x0190, 153
    0x20U, 0xb1U, 0x01U,     0x6eU, 0x39U, 0x01U,     0x63U, 0x4dU, 0x02U,     0x0dU, 0x4eU, 0x01U,	// 0x019c, 165
    0x6eU, 0x7eU, 0x01U,     0x0dU, 0x93U, 0x01U,     0x66U, 0x54U, 0x01U,     0x65U, 0x08U, 0x02U,	// 0x01a8, 177
    0x62U, 0x23U, 0x02U,     0x68U, 0x46U, 0x03U,     0x6fU, 0xbcU, 0x02U,     0x0dU, 0x1dU, 0x02U,	// 0x01b4, 189
    0x6eU, 0x54U, 0x01U,     0x0dU, 0x16U, 0x03U,     0x76U, 0x77U, 0x02U,     0x67U, 0x01U, 0x03U,	// 0x01c0, 201
    0x65U, 0x00U, 0x01U,     0x6eU, 0x92U, 0x02U,     0x61U, 0xf2U, 0x02U,     0x74U, 0x51U, 0x01U,	// 0x01cc, 213
    0x5fU, 0xd5U, 0x01U,     0x6bU, 0xd8U, 0x01U,     0x66U, 0x3eU, 0x02U,     0x72U, 0x2aU, 0x01U,	// 0x01d8, 225
    0x66U, 0x37U, 0x03U,     0x20U, 0x40U, 0x03U,     0x65U, 0x1bU, 0x01U,     0x6eU, 0xadU, 0x02U,	// 0x01e4, 237
    0x20U, 0xfbU, 0x02U,     0x0dU, 0x5aU, 0x01U,     0x61U, 0x9eU, 0x02U,     0x31U, 0x78U, 0x01U,	// 0x01f0, 249
    0x76U, 0x68U, 0x02U,     0x6bU, 0xcfU, 0x01U,     0x63U, 0x36U, 0x01U,     0x61U, 0x7bU, 0x01U,	// 0x01fc, 261
    0x6cU, 0xb4U, 0x01U,     0x65U, 0xdbU, 0x01U,     0x20U, 0x3fU, 0x01U,     0x74U, 0x83U, 0x02U,	// 0x0208, 273
    0x65U, 0x28U, 0x03U,     0x6eU, 0x59U, 0x02U,     0x5fU, 0x4aU, 0x02U,     0x74U, 0x14U, 0x02U,	// 0x0214, 285
    0x79U, 0x0bU, 0x02U,     0x61U, 0x96U, 0x01U,     0x0dU, 0x20U, 0x02U,     0x61U, 0x8fU, 0x02U,	// 0x0220, 297
    0x72U, 0xeaU, 0x01U,     0x0dU, 0x90U, 0x01U,     0x0dU, 0x3dU, 0x03U,     0x77U, 0x52U, 0x03U,	// 0x022c, 309
    0x75U, 0x36U, 0x01U,     0x70U, 0x74U, 0x02U,     0x66U, 0x27U, 0x01U,     0x20U, 0x30U, 0x01U,	// 0x0238, 321
    0x62U, 0x65U, 0x02U,     0x64U, 0x6cU, 0x01U,     0x74U, 0x0cU, 0x01U,     0x65U, 0x65U, 0x02U,	// 0x0244, 333
    0x20U, 0xe4U, 0x01U,     0x6eU, 0xfeU, 0x02U,     0x6eU, 0x27U, 0x01U,     0x63U, 0x3bU, 0x02U,	// 0x0250, 345
    0x61U, 0x6cU, 0x01U,     0x64U, 0x8fU, 0x02U,     0x65U, 0x87U, 0x01U,     0x5fU, 0x11U, 0x02U,	// 0x025c, 357
    0x61U, 0x18U, 0x01U,     0x72U, 0x43U, 0x03U,     0x0dU, 0x12U, 0x01U,     0x76U, 0xd4U, 0x02U,	// 0x0268, 369
    0x75U, 0x6cU, 0x01U,     0x61U, 0x4fU, 0x03U,     0x65U, 0x0aU, 0x03U,     0x65U, 0x18U, 0x01U,	// 0x0274, 381
    0x6cU, 0x8fU, 0x02U,     0x65U, 0x4fU, 0x03U,     0x62U, 0x33U, 0x01U,     0x68U, 0xa2U, 0x01U,	// 0x0280, 393
    0x77U, 0xf6U, 0x01U,     0x5fU, 0x25U, 0x03U,     0x69U, 0x80U, 0x02U,     0x75U, 0x34U, 0x03U,	// 0x028c, 405
    0x6cU, 0x4fU, 0x03U,     0x65U, 0x71U, 0x02U,     0x72U, 0xc5U, 0x02U,     0x74U, 0xccU, 0x01U,	// 0x0298, 417
    0x0dU, 0xb0U, 0x02U,     0x74U, 0x5dU, 0x01U,     0x6dU, 0x6cU, 0x01U,     0x61U, 0x8cU, 0x02U,	// 0x02a4, 429
    0x69U, 0xb6U, 0x02U,     0x65U, 0x47U, 0x02U,     0x75U, 0x9bU, 0x02U,     0x61U, 0xaaU, 0x02U,	// 0x02b0, 441
    0x74U, 0xe0U, 0x02U,     0x78U, 0xb9U, 0x02U,     0x6eU, 0x02U, 0x02U,     0x6fU, 0x6cU, 0x00U,	// 0x02bc, 453
    0x0dU, 0x63U, 0x01U,     0x61U, 0xa7U, 0x02U,     0x6fU, 0x47U, 0x02U,     0x79U, 0x05U, 0x02U,	// 0x02c8, 465
    0x65U, 0x5bU, 0x03U,     0x72U, 0x47U, 0x02U,     0x20U, 0x6bU, 0x02U,     0x63U, 0x38U, 0x02U,	// 0x02d4, 477
    0x63U, 0x84U, 0x01U,     0x65U, 0xecU, 0x02U,     0x66U, 0xaeU, 0x01U,     0x0dU, 0xe6U, 0x02U,	// 0x02e0, 489
    0x74U, 0x24U, 0x01U,     0x6cU, 0xd1U, 0x02U,     0x6fU, 0xefU, 0x02U,     0x5fU, 0x69U, 0x01U,	// 0x02ec, 501
    0x73U, 0x62U, 0x02U,     0x66U, 0xc2U, 0x02U,     0x63U, 0x9fU, 0x01U,     0x20U, 0x4bU, 0x01U,	// 0x02f8, 513
    0x0dU, 0x99U, 0x01U,     0x65U, 0x4cU, 0x03U,     0x65U, 0x98U, 0x02U,     0x0dU, 0xdeU, 0x01U,	// 0x0304, 525
    0x6fU, 0x15U, 0x01U,     0x20U, 0xedU, 0x01U,     0x74U, 0x31U, 0x03U,     0x30U, 0x41U, 0x02U,	// 0x0310, 537
    0x31U, 0x41U, 0x02U,     0x20U, 0xa8U, 0x01U,     0x0dU, 0xd7U, 0x02U,     0x74U, 0x7dU, 0x02U,	// 0x031c, 549
    0x73U, 0x07U, 0x03U,     0x66U, 0x06U, 0x01U,     0x67U, 0x06U, 0x01U,     0x65U, 0xf8U, 0x02U,	// 0x0328, 561
    0x61U, 0x44U, 0x02U,     0x6eU, 0xddU, 0x02U,     0x5fU, 0x66U, 0x01U,     0x74U, 0x53U, 0x02U,	// 0x0334, 573
    0x31U, 0x55U, 0x03U,     0x64U, 0x29U, 0x02U,     0x63U, 0xffU, 0x01U,     0x72U, 0xbaU, 0x01U,	// 0x0340, 585
    0x72U, 0x06U, 0x01U,     0x73U, 0x06U, 0x01U,     0x68U, 0x1aU, 0x02U,     0x20U, 0x1cU, 0x03U,	// 0x034c, 597
    0x5fU, 0x35U, 0x02U,     0x64U, 0x58U, 0x03U,     0x6fU, 0x89U, 0x02U
};

const PROGMEM uint16_t CMD_TABLE[] = {
    0x0000U, 0x026eU, 0x01bdU, 0x01c3U, 0x0109U, 0x01e7U, 0x018aU, 0x02a4U,
    0x030dU, 0x0175U, 0x013cU, 0x01a5U, 0x022fU, 0x0121U, 0x01abU, 0x0250U,
    0x01f0U, 0x0322U, 0x0304U, 0x0232U, 0x02c8U, 0x020eU, 0x02e9U, 0x0142U,
    0x01f3U, 0x019cU, 0x0226U
};

// end of code
