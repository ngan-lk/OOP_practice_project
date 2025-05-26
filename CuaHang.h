#pragma once
#include "MatHang.h"
#include "LoaiHang.h"
#include "HoaDonBanHang.h"

class CuaHang
{
private:
	MatHang* matHang[100];
	int soLuongMatHang;
	LoaiHang* loaiHang[100];
	int soLuongLoaiHang;
	HoaDonBanHang* HDBH[100];
	int soLuongHDBH;
public:
	void Them(FILE* file, int loai);
	void Doc(FILE* file, int loai);
	void XemDanhSach(int loai, FILE* file);
	void Xoa(FILE* file, FILE* file_temp, int loai);
	void Sua(FILE* file, FILE* file_temp, int loai);
	void TimKiem(FILE* file, int loai); 
};

