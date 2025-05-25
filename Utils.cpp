#include <stdio.h>
#include <ctype.h>

void xoaManHinh(int viTriBatDauXoa) {
	printf("\033[%d;1H\033[0J", viTriBatDauXoa);
}

int isNumber(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i]))
            return 0;
    }
    return 1;
}