#ifndef EVM_TYPES_H
#define EVM_TYPES_H

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
 * Used for account balances.
 */
struct evm_value {
	uint8_t bytes[16];
};

#endif
