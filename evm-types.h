#ifndef EVM_TYPES_H
#define EVM_TYPES_H

#define __ewasm_i32 unsigned int
#define __ewasm_i64 unsigned long long int

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
struct evm_value {
	uint8_t bytes[16];
};

#endif
