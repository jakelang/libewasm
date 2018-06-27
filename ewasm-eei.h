#ifndef __EWASM_EEI_H 
#define __EWASM_EEI_H 

#include <stdint.h> /* typedefs for integer types */

#if defined __cplusplus
extern "C" {
#endif
/*
 * useGas:
 * Subtracts a specified amount from the gas counter
 *
 * @param amount		Amount of gas to subtract
 */
void eei_useGas(uint64_t amount);

/*
 * getGasLeft:
 * Gets value of gas counter
 *
 * @return			Gas remaining
 */
uint64_t eei_getGasLeft();

/*
 * getAddress:
 * Writes address of currently executing account to memory
 *
 * @param[out] resultOffset	Offset to write executing address
 */
void eei_getAddress(uint32_t resultOffset);

/*
 * getBalance:
 * Writes balance of specified address to memory
 *
 * @param addressOffset		Offset of address
 * @param[out] resultOffset	Offset to write balance
 */
void eei_getBalance(struct evm_address *addressOffset, struct evm_uint128 *resultOffset);

/*
 * getCaller:
 * Writes address of contract caller to memory
 *
 * @param[out] resultOffset	Offset to write address of caller
 */
void eei_getCaller(struct evm_address *resultOffset);

/*
 * getCallValue:
 * Writes value deposited with transaction or call responsible for execution
 *
 * @param[out] resultOffset	Offset to write value to
 */
void eei_getCallValue(struct evm_uint128 *resultOffset);

/*
 * getCallDataSize:
 * Gets size of input data sent with call or transaction responsible for
 * execution
 *
 * @return			Size of input data
 */
uint32_t eei_getCallDataSize();

/*
 * getReturnDataSize:
 * Gets size of buffer containing return data from previous call
 * (or create, in case of failure)
 *
 * @return			Size of return data buffer
 */
uint32_t eei_getReturnDataSize();

/*
 * getCodeSize:
 * Gets size of code currently executing
 *
 * @return			Size of code
 */
uint32_t eei_getCodeSize();

/*
 * getExternalCodeSize:
 * Gets size of code at specified account
 *
 * @param AddressOffset		Offset of address
 *
 * @return			Size of code at address
 */
uint32_t eei_getExternalCodeSize(struct evm_address *addressOffset);

/*
 * getTxOrigin:
 * Write address of externally owned account responsible for transaction 
 * to memory
 *
 * @param[out] resultOffset	Offset to write address
 */
void eei_getTxOrigin(struct evm_address *resultOffset);

/*
 * getTxGasPrice:
 * Writes price of gas in current environment to memory
 *
 * @param[out] valueOffset	Offset to write gas price
 */
void eei_getTxGasPrice(struct evm_uint128 *valueOffset);

/*
 * getBlockHash:
 * Writes hash of specified block to memory
 *
 * @param number		Number of block
 * @param[out] resultOffset	Offset to write block hash
 */
void eei_getBlockHash(int64_t number, struct evm_uint256 *resultOffset);

/*
 * getBlockCoinBase:
 * Writes current block's beneficiary address (receiver of block reward) 
 * to memory
 *
 * @param[out] resultOffset	Offset to write beneficiary address
 */
void eei_getBlockCoinBase(struct evm_address *resultOffset);

/*
 * getBlockDifficulty:
 * Writes current block difficulty to memory
 *
 * @param[out] offset		Offset to write difficulty
 */
void eei_getBlockDifficulty(struct evm_uint256 *offset);

/*
 * getBlockNumber:
 * Gets number of current block
 *
 * @return			Number of block
 */
int64_t eei_getBlockNumber();

/*
 * getBlockTimeStamp:
 * Gets timestamp of current block
 *
 * @return			Timestamp of block
 */
int64_t eei_getBlockTimestamp();

/*
 * getBlockGasLimit:
 * Gets gas limit of current block
 *
 * @return			Gas limit of block
 */
int64_t eei_getBlockGasLimit();

/*
 * storageStore:
 * Stores a 256-bit value in persistent storage
 *
 * @param pathOffset		Offset containing storage path
 * @param valueOffset		Offset containing value to store
 */
void eei_storageStore(struct evm_uint256 *pathOffset, struct evm_uint256 *valueOffset);

/*
 * storageLoad:
 * Loads a 256-bit value from specified storage path
 *
 * @param pathOffset		Offset containing storage path
 * @param[out] resultOffset	Offset to write storage value
 */
void eei_storageLoad(struct evm_uint256 *pathOffset, struct evm_uint256 *resultOffset);

/*
 * log:
 * Creates a new log in current environment containing up to four 256-bit topics
 *
 * @param dataOffset		Offset to load data from
 * @param length		Length of data
 * @param numberOfTopics	Number of log topics
 * @param topic1		Offset containing topic 1
 * @param topic2		Offset containing topic 2
 * @param topic3		Offset containing topic 3
 * @param topic4		Offset containing topic 4
 */
void eei_log(uint8_t *dataOffset,
	 uint32_t length,
	 uint32_t numberOfTopics,
	 struct evm_uint256 *topic1,
	 struct evm_uint256 *topic2,
	 struct evm_uint256 *topic3,
	 struct evm_uint256 *topic4);
/*
 * callDataCopy:
 * Copies call/transaction input data to memory at specified offset
 *
 * @param[out] resultOffset	Offset to write input data
 * @param dataOffset		Offset within input data
 * @param dataLength		Length of data
 */
void eei_callDataCopy(uint8_t *resultOffset, 
		  uint32_t dataOffset, 
		  uint32_t dataLength);

/*
 * returnDataCopy:
 * Copies current return data buffer to memory at specified offset
 *
 * @param[out] resultOffset	Offset to write return data
 * @param dataOffset		Offset within return data
 * @param length		Length of return data
 */
void eei_returnDataCopy(uint8_t *resultOffset,
		    uint32_t dataOffset,
		    uint32_t length);

/*
 * codeCopy:
 * Copies currently executing code to memory at specified offset
 *
 * @param[out] resultOffset	Offset to write code
 * @param codeOffset		Offset within code
 * @param length		Length of code
 */
void eei_codeCopy(uint8_t *resultOffset,
	      uint32_t codeOffset,
	      uint32_t length);

/*
 * externalCodeCopy:
 * Copies code at specified account to memory at specified offset
 *
 * @param addressOffset		Offset containing address with associated code
 * @param[out] resultOffset	Offset to write code
 * @param codeOffset		Offset within code
 * @param length		Length of code
 */
void eei_externalCodeCopy(struct evm_address *addressOffset,
		      uint8_t *resultOffset,
		      uint32_t codeOffset,
		      uint32_t length);

/*
 * call:
 * Sends message to specified address
 *
 * @param gas			Gas limit
 * @param addressOffset		Offset containing address to send message
 * @param valueOffset		Offset containing value to send with message
 * @param dataOffset		Offset containing input data for message
 * @param dataLength		Length of input data
 *
 * @return 			Exit status: 0 on success
 * 					     1 on failure
 * 					     2 on revert
 */
uint32_t eei_call(uint64_t gas, 
	      struct evm_address *addressOffset, 
	      struct evm_uint128 *valueOffset, 
	      uint8_t *dataOffset, 
	      uint32_t dataLength);

/*
 * callCode:
 * Message-calls current account with code of an alternative account
 *
 * @param gas			Gas limit
 * @param addressOffset		Offset containing address with code
 * @param valueOffset		Offset containing value to send with message
 * @param dataOffset		Offset containing input data for message
 * @param dataLength		Length of input data
 *
 * @return 			Exit status: 0 on success
 * 					     1 on failure
 * 					     2 on revert
 */
uint32_t eei_callCode(uint64_t gas,
		  struct evm_address *addressOffset,
		  struct evm_uint128 *valueOffset,
		  uint8_t *dataOffset,
		  uint32_t dataLength);
/*
 * callDelegate:
 * Message-calls current account with code of an alternative account,
 * but persisting sender and value
 *
 * @param gas			Gas limit
 * @param addressOffset		Offset containing address with code
 * @param dataOffset		Offset containing input data for message
 * @param dataLength		Length of input data
 *
 * @return 			Exit status: 0 on success
 * 					     1 on failure
 * 					     2 on revert
 */
uint32_t eei_callDelegate(uint64_t gas,
		      struct evm_address *addressOffset,
		      uint8_t *dataOffset,
		      uint32_t dataLength);

/*
 * callStatic:
 * Sends message to specified address but prohibits state changes including
 * log, create, selfDestruct and call. This property is preserved for sub-calls
 *
 * @param gas			Gas limit
 * @param addressOffset		Offset containing address to send message
 * @param dataOffset		Offset containing input data for message
 * @param dataLength		Length of input data
 *
 * @return 			Exit status: 0 on success
 * 					     1 on failure
 * 					     2 on revert
 */
uint32_t eei_callStatic(uint64_t gas,
		    struct evm_address *addressOffset,
		    uint8_t *dataOffset,
		    uint32_t dataLength);

/*
 * create:
 * Deploys a contract with specified code and initial value deposit
 *
 * @param valueOffset		Offset containing value to be deposited
 * @param dataOffset		Offset containing code to be deployed
 * @param length		Length of code to be deployed
 * @param[out] resultOffset	Offset to write new contract address
 *
 * @return			Exit status: 0 on success
 * 					     1 on failure
 * 					     2 on revert
 */
uint32_t eei_create(struct evm_uint128 *valueOffset,
		uint8_t *dataOffset,
		uint32_t length,
		struct evm_address *resultOffset);

/*
 * return:
 * Sets output data and halts execution
 * FIXME: return coincides with a language keyword and should be renamed
 *
 * @param dataOffset		Offset containing return data
 * @param length		Length of return data
 */
void eei_return(uint8_t *dataOffset, uint32_t length);

/*
 * revert:
 * Sets output data for current execution, refunds gas to caller,
 * reverts any state modifications and halts execution
 *
 * @param dataOffset		Offset containing return data
 * @param length		Length of return data
 */
void eei_revert(uint8_t *dataOffset, uint32_t length);

/*
 * selfDestruct:
 * Marks executing account for deletion, sends remaining balance to specified
 * beneficiary address, and halts execution
 *
 * @param addressOffset		Offset containing beneficiary address
 */
void eei_selfDestruct(struct evm_address *addressOffset);

#if defined __cplusplus 
}
#endif

#endif
