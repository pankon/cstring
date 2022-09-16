#ifndef __CSTRING_H__
#define __CSTRING_H__

#include <string.h>
#include <stdlib.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) <= (b)) ? (a) : (b))

/*
 * This header/library makes no assumptions about reallocs.
 * If you allocate a memory segment, it stays the same size.
 * It is very recommended not to touch the cstring_t's contents.
 */

typedef struct {
	size_t size;
	size_t length;
	char *data;
} cstring_t;

#define cstring_malloc malloc
#define cstring_free free

#define ptr_c_str(cstring_ptr) ((cstring_ptr)->data)
#define c_str(cstring) ((cstring).data)
#define ptr_c_strlen(cstring) ((cstring)->length)
#define c_strlen(cstring) ((cstring).length)

#define decl_static_cstring(name, size) \
	char _cstring_buf_##name[size] = {0}; \
	cstring_t name = {size, 0, _cstring_buf_##name}
	
#define decl_const_static_cstring(name, size) \
	const char _cstring_buf_##name[size] = {0}; \
	const cstring_t name = {size, 0, _cstring_buf_##name}

#define decl_static_cstring_from_string(name, static_string) \
	const cstring_t name = {sizeof(static_string), sizeof(static_string) - 1, static_string}
	
#define decl_const_static_cstring_from_string(name, static_string) \
	cstring_t name = {sizeof(static_string), sizeof(static_string) - 1, static_string}

#define c_strcpy(self, other) do { \
		(self).length = MIN((self).size, (other).length); \
		memcpy((self).data, (other).data, (self).length); \
	} while (0)

#define ptr_c_strcpy(self, other) do { \
		(self)->length = MIN((self)->size, (other)->length); \
		memcpy((self)->data, (other)->data, (self)->length); \
	} while (0)

#define c_strcpy_static(self, static_string) do { \
		(self).length = MIN((self).size, sizeof(static_string) - 1); \
		memcpy((self).data, static_string, (self).length); \
	} while (0)

#define ptr_c_strcpy_static(self, static_string) do { \
		(self)->length = MIN((self)->size, sizeof(static_string) - 1); \
		memcpy((self)->data, static_string, (self)->length); \
	} while (0)

#define c_strcpy_static(self, static_string) do { \
		(self).length = MIN((self).size, sizeof(static_string) - 1); \
		memcpy((self).data, static_string, (self).length); \
	} while (0)

#define ptr_c_strcat(self, other) do { \
		size_t diff = MIN((self)->size - (self)->length, (other)->length); \
		if (diff != 0) { \
			memcpy((self)->data + (self)->length, (other)->data, diff); \
			(self)->length += diff; \
		} \
	} while (0)

#define c_strcat(self, other) do { \
		size_t diff = MIN((self).size - (self).length, (other).length); \
		if (diff != 0) { \
			memcpy((self).data + (self).length, (other).data, diff); \
			(self).length += diff; \
		} \
	} while (0)

#define ptr_c_strcat_static(self, static_string) do { \
		size_t diff = MIN((self)->size - (self)->length, sizeof(static_string) - 1); \
		if (diff != 0) { \
			memcpy((self)->data + (self)->length, static_string, diff); \
			(self)->length += diff; \
		} \
	} while (0)

#define c_strcat_static(self, static_string) do { \
		size_t diff = MIN((self).size - (self).length, sizeof(static_string) - 1); \
		if (diff != 0) { \
			memcpy((self).data + (self).length, static_string, diff); \
			(self).length += diff; \
		} \
	} while (0)

#endif /* __CSTRING_H__ */
