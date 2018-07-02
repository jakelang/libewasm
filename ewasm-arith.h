#ifndef __EWASM_ARITH_H
#define __EWASM_ARITH_H

/*
 * add_uint256:
 * Adds two unsigned 256-bit integers. Equivalent to dst += src.
 * @param  dst:	 The augend
 * @param src:	 The addend
 * 
 * @return	 Whether an overflow occurred
 */
int 
add_uint256(struct evm_uint256 *dst, struct evm_uint256 *src)
{

}

/*
 * add_uint128:
 * Adds two unsigned 128-bit integers. Equivalent to dst += src.
 * @param  dst:	 The augend
 * @param src:	 The addend
 * 
 * @return	 Whether an overflow occurred
 */
int
add_uint128(struct evm_uint128 *dst, struct evm_uint128 *src)
{

}

#endif
