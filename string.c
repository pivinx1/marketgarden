#include "string.h"

unsigned int strlen(const char* str)
{
	unsigned int len = 0;
	while(str[len])
		len++;
	return len;
}
void* memmove(void* dstptr, const void* srcptr, unsigned int size) {
	unsigned char* dst = (unsigned char*) dstptr;
	const unsigned char* src = (const unsigned char*) srcptr;
	if (dst < src) {
		for (unsigned int i = 0; i < size; i++)
			dst[i] = src[i];
	} else {
		for (unsigned int i = size; i != 0; i--)
			dst[i-1] = src[i-1];
	}
	return dstptr;
}
