#pragma once
#include "Utils.h"
#include <stdio.h>

class BaseInvoice
{
protected:
	char soHoaDon[MAX_LEN];
	char ngayHoaDon[MAX_LEN];
	char maHang[MAX_LEN];
	int soLuongBan;
	int donGia;
	int soTien;
public:
	//void Doc(FILE* file) {};
	const char* taoSoHoaDon(FILE* file, const char* prefix);
	virtual void Them(FILE* file) = 0;
	virtual void TaoHoaDon(FILE* file) = 0;
};

