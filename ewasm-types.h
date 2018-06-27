#ifndef __EWASM_TYPES_H
#define __EWASM_TYPES_H

#include <stdint.h> /* typedefs for integer types */

/*
 * 256-bit unsigned integer type.
 *
 * Used for hashes, difficulties, log topics, and storage values/paths.
 */
struct evm_uint256 {
	uint8_t bytes[32];
};

/*
 * 160-bit unsigned integer type.
 *
 * Used for account addresses.
 */
struct evm_address {
	uint8_t bytes[20];
};

/*
 * 128-bit unsigned integer type.
 *
 * Used for ether values.
 */
struct evm_uint128 {
	uint8_t bytes[16];
};

#endif
