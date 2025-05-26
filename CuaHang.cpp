#include "CuaHang.h"
#include "BaseObject.h"

void CuaHang::Them(FILE* file, int loai) {
	FILE* fRead = NULL;
	BaseObject* doiTuongThem;
	BaseInvoice* hoaDon;

	if (loai == 1) {
		fopen_s(&fRead, "MatHang.txt", "rt");

		if (fRead != NULL) {
			Doc(fRead, loai);
			fclose(fRead);
		}

		if (soLuongMatHang < 100) {
			//MatHang* mh = new MatHang();
			doiTuongThem = new MatHang();
			if (doiTuongThem->Them(file)) {
				matHang[soLuongMatHang] = (MatHang*)doiTuongThem;
				soLuongMatHang++;
				printf("\nDa them mat hang moi va luu file thanh cong!\n\n");
			};
		}
		else {
			printf("Danh sach day, khong the them mat hang moi!\n");
		}
	}
	else if (loai == 2) {
		fopen_s(&fRead, "LoaiHang.txt", "rt");

		if (fRead != NULL) {
			Doc(fRead, loai);
			fclose(fRead);
		}

		if (soLuongLoaiHang < 100) {
			//LoaiHang* lh = new LoaiHang();
			doiTuongThem = new LoaiHang();
			doiTuongThem->Them(file);
			loaiHang[soLuongLoaiHang] = (LoaiHang*) doiTuongThem;
			soLuongLoaiHang++;
			printf("\nDa them loai hang moi va luu file thanh cong!\n\n");
		}
		else {
			printf("Danh sach day, khong the them mat hang moi!\n");
		}
	}
	else if (loai == 3) {
		hoaDon = new HoaDonBanHang();
		hoaDon->TaoHoaDon(file);
		char choice;
		do {
			printf("Them mat hang vao hoa don:\n");
			hoaDon->Them(file);
			HDBH[soLuongHDBH] = (HoaDonBanHang*)hoaDon;
			soLuongHDBH++;
			printf("Tiep tuc them mat hang? (Y/N): ");
			scanf_s("%c", &choice, 1);
			while (getchar() != '\n');
		} while (choice == 'y' || choice == 'Y');
		printf("Da them hoa don ban hang moi va luu file thanh cong!\n\n");
	}
}

void CuaHang::Doc(FILE* file, int loai) {
	BaseObject* doiTuongDoc;
	if (loai == 1) {
		soLuongMatHang = 0;
		while (true) {
			doiTuongDoc = new MatHang();
			doiTuongDoc->docFile(file);
			if (feof(file)) {
				delete doiTuongDoc;
				break;
			}
			matHang[soLuongMatHang] = (MatHang*)doiTuongDoc;
			soLuongMatHang++;
		}
	}
	else if (loai == 2) {
		soLuongLoaiHang = 0;
		while (true) {
			doiTuongDoc = new LoaiHang();
			doiTuongDoc->docFile(file);
			if (feof(file)) {
				delete doiTuongDoc;
				break;
			}
			loaiHang[soLuongLoaiHang] = (LoaiHang*)doiTuongDoc;
			soLuongLoaiHang++;
		}
	}
}


void CuaHang::XemDanhSach(int loai, FILE* file) {
	if (loai == 1) {
		Doc(file, loai);
		for (int i = 0; i < soLuongMatHang; i++) {
			matHang[i]->XemDanhSach();
			printf("\n");
		}
	}
	else if (loai == 2) {
		Doc(file, loai);
		for (int i = 0; i < soLuongLoaiHang; i++) {
			loaiHang[i]->XemDanhSach();
			printf("\n");
		}
	}
}

void CuaHang::Xoa(FILE* file, FILE* file_temp, int loai) {
	BaseObject* doiTuongXoa;
	if (loai == 1) {
		doiTuongXoa = new MatHang();
		doiTuongXoa->Xoa(file, file_temp);
	}
	else if (loai == 2) {
		doiTuongXoa = new LoaiHang();
		doiTuongXoa->Xoa(file, file_temp);
	}
}

void CuaHang::Sua(FILE* file, FILE* file_temp, int loai) {
	BaseObject* doiTuongSua;
	if (loai == 1) {
		doiTuongSua = new MatHang();
		doiTuongSua->Sua(file, file_temp);
	}
	else if (loai == 2) {
		doiTuongSua = new LoaiHang();
		doiTuongSua->Sua(file, file_temp);
	}
}

void CuaHang::TimKiem(FILE* file, int loai) {
	BaseObject* doiTuongTimKiem;
	if (loai == 1) {
		doiTuongTimKiem = new MatHang();
		doiTuongTimKiem->TimKiem(file);
	}
	else if (loai == 2) {
		doiTuongTimKiem = new LoaiHang();
		doiTuongTimKiem->TimKiem(file);
	}
}

