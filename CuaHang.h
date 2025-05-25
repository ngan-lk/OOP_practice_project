#pragma once
#include "MatHang.h"
#include "LoaiHang.h"

class CuaHang
{
private:
	MatHang* matHang[100];
	int soLuongMatHang;
	LoaiHang* loaiHang[100];
	int soLuongLoaiHang;
public:
	void Them(FILE* file, int loai);
	void Doc(FILE* file);
	void Xuat();
	void Xoa(FILE* file, FILE* file_temp, int loai);
	void Sua();
	void TimKiem();
};

