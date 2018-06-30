#ifndef __ETHEREUM_H
#define __ETHEREUM_H

#include <ewasm-types.h>
#include <ewasm-eei.h>

#if defined __INCLUDE_EEI_HELPERS
#include <ewasm-eei-helpers.h>
#endif

#if defined __INCLUDE_ARITH_OPS
#define __INCLUDE_BITWISE_OPS
#include <ewasm-arith.h>
#endif

#if defined __INCLUDE_BITWISE_OPS
#include <ewasm-bitwise.h>
#endif

#endif
