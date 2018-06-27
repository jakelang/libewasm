#ifndef __EWASM_BITWISE_H
#define __EWASM_BITWISE_H

#include <stdint.h> 

#include <ewasm-types.h>

void
and_bytes(uint8_t *dst, uint8_t *src, size_t length)
{
	size_t i;
	for (i = 0; i < length; ++i)
		dst[i] &= src[i];
}

void
or_bytes(uint8_t *dst, uint8_t *src, size_t length)
{
	size_t i;
	for (i = 0; i < length; ++i)
		dst[i] |= src[i];
}

void 
xor_bytes(uint8_t *dst, uint8_t *src, size_t length)
{
	size_t i;
	for (i = 0; i < length; ++i)
		dst[i] ^= src[i];
}

void 
not_bytes(uint8_t *dst, size_t length)
{
	size_t i;
	for (i = 0; i < length; ++i)
		dst[i] = ~dst[i];
}

#endif
