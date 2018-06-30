#ifndef __EWASM_EEI_HELPERS_H
#define __EWASM_EEI_HELPERS_H

#include <ewasm-types.h>
#include <ewasm-eei.h>

/*
 * Friendly wrapper functions for EEI methods
 */
struct evm_address
getAddress()
{
	struct evm_address ret;
	eei_getAddress(&ret);
	return ret;
}

struct evm_uint128
getBalance(struct evm_address *address)
{
	struct evm_uint128 ret;
	eei_getBalance(address, &ret);
	return ret;
}

struct evm_address
getCaller()
{
	struct evm_address ret;
	eei_getCaller(&ret);
	return ret;
}

struct evm_uint128
getCallValue()
{
	struct evm_uint128 ret;
	eei_getCallValue(&ret);
	return ret;
}

struct evm_address
getTxOrigin()
{
	struct evm_address ret;
	eei_getTxOrigin(&ret);
	return ret;
}

struct evm_uint128
getTxGasPrice()
{
	struct evm_uint128 ret;
	eei_getTxGasPrice(&ret);
	return ret;
}

struct evm_uint256
getBlockHash(int64_t num)
{
	struct evm_uint256 ret;
	eei_getBlockHash(num, &ret);
	return ret;
}

struct evm_address
getBlockCoinbase()
{
	struct evm_address ret;
	eei_getBlockCoinbase(&ret);
	return ret;
}

struct evm_uint256
getBlockDifficulty()
{
	struct evm_uint256 ret;
	eei_getBlockDifficulty(&ret);
	return ret;
}

struct evm_uint256
storageLoad(struct evm_uint256 *path)
{
	struct evm_uint256 ret;
	eei_storageLoad(path, &ret);
	return ret;
}

#endif
