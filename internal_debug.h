/*
 * File: internal_debug.h
 * Author: Ragib Asif
 * Email: ragib.asif30@myhunter.cuny.edu
 * GitHub: https://github.com/ragibasif
 * LinkedIn: https://www.linkedin.com/in/ragibasif/
 * SPDX-License-Identifier: MIT
 * Copyright (c) 2025 Ragib Asif
 * Version 1.0.0
 *
 * Header file for internal debugging.
 *
 */

#ifndef __INTERNAL_DEBUG_H__
#define __INTERNAL_DEBUG_H__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/******************************************************************************/
/*                          DEBUGGING - DO NOT TOUCH                          */
/******************************************************************************/

#define F_MEMORY_DEBUG /* turns on the memory debugging system */
#define F_MEMORY_PRINT /* turns on the memory printing system */
#define F_EXIT_CRASH   /* turns on the crash on exit */
#include "internal_debug/dbg.h"
#include "internal_debug/forge.h"

/******************************************************************************/

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __INTERNAL_DEBUG_H__
