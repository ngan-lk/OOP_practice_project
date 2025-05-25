#pragma once
#include "BaseObject.h"
#include <stdio.h>

class MatHang : public BaseObject
{
private:
	char tenHang[MAX_LEN];
	char hanDung[MAX_LEN];
	char congTySanXuat[MAX_LEN];
	char loaiHang[MAX_LEN];
	int namSanXuat;
	int soLuong;
public:
	void XemDanhSach();
	void docFile(FILE* file);
	void Xoa(FILE* fileMatHang, FILE* file_temp);
	bool Them(FILE* fileMatHang);
	void Sua(FILE* fileMatHang, FILE* file_temp);
	void TimKiem(FILE* fileMatHang);
};

