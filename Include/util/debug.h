#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <switch/types.h>

void printBytes(u8 *bytes, size_t size, bool includeHeader);

#ifdef __cplusplus
}
#endif