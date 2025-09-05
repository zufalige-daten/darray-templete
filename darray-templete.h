#pragma once

#define _forceinline inline __attribute__((always_inline))

#include <stdint.h>
#include <stddef.h>
#include <malloc.h>
#include <stdlib.h>

#define DARRAY_USE(T) typedef struct T##_darray { \
	size_t length; \
	T data[]; \
} T##_darray_t;

#define darray_init(T) (T##_darray_t *)_darray_init()
#define darray_add(T, darray, Q) _darray_add()

_forceinline void *_darray_init(void) {
	size_t *allocation;

	allocation = (size_t *)malloc(sizeof(size_t));
	*allocation = 0;

	return allocation;
}

#undef _forceinline

