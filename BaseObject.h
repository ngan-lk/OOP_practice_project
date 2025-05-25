#pragma once
#include "Utils.h"
#include <stdio.h>

class BaseObject
{
private:
	char id[MAX_LEN];
public:
	void nhapId(const char* id);
	void docFile(FILE* file);
	const char* getId();
	virtual void Xoa(FILE* fileMatHang, FILE* file_temp) = 0;
	virtual bool Them(FILE* fileMatHang) = 0;
	virtual void Sua(FILE* fileMatHang, FILE* file_temp) = 0;
	virtual void TimKiem(FILE* fileMatHang) = 0;
};

