#pragma once
#include "BaseInvoice.h"

class HoaDonBanHang : public BaseInvoice
{
public:
	void TaoHoaDon(FILE* fileHDBH);
	void Them(FILE* fileHDBH);
};

