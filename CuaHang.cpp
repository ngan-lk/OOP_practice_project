#include "CuaHang.h"
#include "BaseObject.h"

void CuaHang::Them(FILE* file, int loai) {
	FILE* fRead = NULL;
	BaseObject* doiTuongThem;

	if (loai == 1) {
		fopen_s(&fRead, "MatHang.txt", "rt");

		if (fRead != NULL) {
			Doc(fRead);
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
			Doc(fRead);
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
}

void CuaHang::Doc(FILE* file) {
	soLuongMatHang = 0;

	while (true) {
		MatHang* mh = new MatHang();
		mh->docFile(file);

		if (feof(file)) {
			delete mh;
			break;
		}

		matHang[soLuongMatHang] = mh;
		soLuongMatHang++;
	}
}


void CuaHang::Xuat() {
	for (int i = 0; i < soLuongMatHang; i++) {
		matHang[i]->xuatMatHang();
		printf("\n");
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

void CuaHang::Sua() {

}

void CuaHang::TimKiem() {

}

