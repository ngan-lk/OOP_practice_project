#pragma once
#include "Utils.h"
#include <stdio.h>

class BaseInvoice
{
private:
	char soHoaDon[MAX_LEN];
	char ngayHoaDon[MAX_LEN];
	char maHang[MAX_LEN];
	int soLuong;
	int soTien;
public:
	//void Doc(FILE* file) {};
	const char* taoSoHoaDon(FILE* file, const char* prefix);
};

