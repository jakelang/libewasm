#ifndef __EWASM_BITWISE_H
#define __EWASM_BITWISE_H

#include <stdint.h> 

#include <ewasm-types.h>

/*
 * Basic bitwise operation helpers for byte arrays
 */
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

/*
 * Type-specific bitwise operations: evm_uint256
 */
struct evm_uint256
and_uint256(struct evm_uint256 *a, struct evm_uint256 *b)
{
	struct evm_uint256 ret;
	ret = *a;
	and_bytes(&ret, b, 32);
	return ret;
}

struct evm_uint256
or_uint256(struct evm_uint256 *a, struct evm_uint256 *b)
{
	struct evm_uint256 ret;
	ret = *a;
	or_bytes(&ret, b, 32);
	return ret;
}

struct evm_uint256
xor_uint256(struct evm_uint256 *a, struct evm_uint256 *b)
{
	struct evm_uint256 ret;
	ret = *a;
	xor_bytes(&ret, b, 32);
	return ret;
}

struct evm_uint256
not_uint256(struct evm_uint256 *a)
{
	struct evm_uint256 ret;
	ret = *a;
	not_bytes(&ret, 32);
	return ret;
}

/*
 * Type-specific bitwise operations: evm_value
 */
struct evm_value
and_value(struct evm_value *a, struct evm_value *b)
{
	struct evm_value ret;
	ret = *a;
	and_bytes(&ret, b, 16);
	return ret;
}

struct evm_value
or_value(struct evm_value *a, struct evm_value *b)
{
	struct evm_value ret;
	ret = *a;
	or_bytes(&ret, b, 16);
	return ret;
}

struct evm_value
xor_value(struct evm_value *a, struct evm_value *b)
{
	struct evm_value ret;
	ret = *a;
	xor_bytes(&ret, b, 16);
	return ret;
}

struct evm_value
not_value(struct evm_value *a)
{
	struct evm_value ret;
	ret = *a;
	not_bytes(&ret, 16);
	return ret;
}

#endif
