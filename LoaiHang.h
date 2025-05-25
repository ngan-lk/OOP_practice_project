#pragma once
#include "BaseObject.h"

class LoaiHang : public BaseObject
{
private:
	char tenLoaiHang[MAX_LEN];
public:
	void xuatLoaiHang();
	bool Them(FILE* fileMatHang);
	void docFile(FILE* file);
	static bool kiemTraLoaiHangTonTai(const char* maLoaiHang);
	void Xoa(FILE* fileMatHang, FILE* file_temp);
	void Sua(FILE* fileMatHang, FILE* file_temp);
};


