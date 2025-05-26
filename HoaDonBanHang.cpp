#include "HoaDonBanHang.h"
#include <string.h>

void HoaDonBanHang::TaoHoaDon(FILE* fileHDBH) {
	strcpy_s(soHoaDon, taoSoHoaDon(fileHDBH, "HDBH"));
	printf("Nhap ngay hoa don: ");
	gets_s(ngayHoaDon);
	ngayHoaDon[strcspn(ngayHoaDon, "\n")] = 0;

	fprintf(fileHDBH, "%s\n", soHoaDon);
	fprintf(fileHDBH, "%s\n", ngayHoaDon);
}

void HoaDonBanHang::Them(FILE* fileHDBH) {
	printf("Nhap ma mat hang: ");
	gets_s(maHang);
	printf("Nhap so luong: ");
	scanf_s("%d", &soLuongBan);
	FILE* file;
	fopen_s(&file, "MatHang.txt", "rt");

	char id[MAX_LEN];
	char tenHang[MAX_LEN];
	char hanDung[MAX_LEN];
	char congTySanXuat[MAX_LEN];
	char loaiHang[MAX_LEN];

	int namSanXuat;
	int soLuong;

	if (file != NULL) {
		while (fgets(id, MAX_LEN, file) != NULL) {
			id[strcspn(id, "\n")] = 0;
			fgets(tenHang, MAX_LEN, file);
			tenHang[strcspn(tenHang, "\n")] = 0;
			fgets(hanDung, MAX_LEN, file);
			hanDung[strcspn(hanDung, "\n")] = 0;
			fgets(congTySanXuat, MAX_LEN, file);
			congTySanXuat[strcspn(congTySanXuat, "\n")] = 0;
			fgets(loaiHang, MAX_LEN, file);
			loaiHang[strcspn(loaiHang, "\n")] = 0;
			fscanf_s(file, "%d", &namSanXuat);
			fgetc(file);
			fscanf_s(file, "%d", &soLuong);
			fgetc(file);

			if (strcmp(maHang, id) == 0) {
				if (soLuongBan <= soLuong) {
					printf("Nhap don gia: ");
					scanf_s("%d", &donGia);
					while (getchar() != '\n');
					soTien = soLuong * donGia;

					fprintf(fileHDBH, "%s\n", maHang);
					fprintf(fileHDBH, "%d\n", soLuong);
					fprintf(fileHDBH, "%d\n", donGia);
					fprintf(fileHDBH, "%d\n", soTien);
					return;
				}
				else {
					printf("Khong du so luong xuat ban!\n");
					return;
				}
			}
		}

		printf("Khong tim thay mat hang!\n");
	}	
}
