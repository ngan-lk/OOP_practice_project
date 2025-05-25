#include "MatHang.h"
#include "LoaiHang.h"
#include <stdio.h>
#include <string.h>

void MatHang::xuatMatHang() {
	printf("Ma hang:\t\t%s\n", getId());
	printf("Ten hang:\t\t%s\n", tenHang);
	printf("Han dung:\t\t%s\n", hanDung);
	printf("Cong ty san xuat:\t%s\n", congTySanXuat);
	printf("Loai hang:\t\t%s\n", loaiHang);
	printf("Nam san xuat:\t\t%d\n", namSanXuat);
	printf("So luong:\t\t%d\n", soLuong);
}

bool MatHang::Them(FILE* fileMatHang) {
	printf("Nhap ma loai hang: ");
	gets_s(loaiHang);

	if (LoaiHang::kiemTraLoaiHangTonTai(loaiHang)) {
		char id[100];
		printf("Nhap ma hang: ");
		scanf_s("%s", id, 100);
		nhapId(id);
		char c;

		do {
			c = getchar();
		} while (c != EOF && c != '\n');

		printf("Nhap ten mat hang: ");
		gets_s(tenHang);
		printf("Nhap han dung (dd/mm/yyyy): ");
		gets_s(hanDung);
		printf("Nhap cong ty san xuat: ");
		gets_s(congTySanXuat);
		printf("Nhap nam san xuat: ");
		scanf_s("%d", &namSanXuat);
		printf("Nhap so luong: ");
		scanf_s("%d", &soLuong);
	
		if (fileMatHang != NULL) {
			fprintf(fileMatHang, "%s\n", getId());
			fprintf(fileMatHang, "%s\n", tenHang);
			fprintf(fileMatHang, "%s\n", hanDung);
			fprintf(fileMatHang, "%s\n", congTySanXuat);
			fprintf(fileMatHang, "%s\n", loaiHang);
			fprintf(fileMatHang, "%d\n", namSanXuat);
			fprintf(fileMatHang, "%d\n", soLuong);
		}
		else {
			printf("Khong mo duoc file!");
		}

		return true;
	};
	printf("Ma loai hang khong hop le!\n\n");
	return false;
}

void MatHang::docFile(FILE* file) {
	if (file != NULL) {
		BaseObject::docFile(file);
		fgets(tenHang, MAX_LEN, file);
		fgets(hanDung, MAX_LEN, file);
		fgets(congTySanXuat, MAX_LEN, file);
		fgets(loaiHang, MAX_LEN, file);
		fscanf_s(file, "%d", &namSanXuat);
		fgetc(file);
		fscanf_s(file, "%d", &soLuong);
		fgetc(file);
		char* fields[] = { tenHang, hanDung, congTySanXuat, loaiHang };

		for (int i = 0; i < 4; i++) {
			size_t len = strlen(fields[i]);

			if (len > 0 && fields[i][len - 1] == '\n') {
				fields[i][len - 1] = '\0';
			}
		}
	}
}

void MatHang::Xoa(FILE* fileMatHang, FILE* file_temp) {
	printf("Nhap ma mat hang can xoa: ");
	char id[MAX_LEN];
	gets_s(id);
	id[strcspn(id, "\n")] = 0;
	char id_file[MAX_LEN];
	int found = 0;

	if (fileMatHang != NULL && file_temp != NULL) {
		rewind(fileMatHang);
		while (fgets(id_file, MAX_LEN, fileMatHang) != NULL) {
			id_file[strcspn(id_file, "\n")] = 0;
			fgets(tenHang, MAX_LEN, fileMatHang);
			tenHang[strcspn(tenHang, "\n")] = 0;
			fgets(hanDung, MAX_LEN, fileMatHang);
			hanDung[strcspn(hanDung, "\n")] = 0;
			fgets(congTySanXuat, MAX_LEN, fileMatHang);
			congTySanXuat[strcspn(congTySanXuat, "\n")] = 0;
			fgets(loaiHang, MAX_LEN, fileMatHang);
			loaiHang[strcspn(loaiHang, "\n")] = 0;
			fscanf_s(fileMatHang, "%d", &namSanXuat);
			fgetc(fileMatHang);
			fscanf_s(fileMatHang, "%d", &soLuong);
			fgetc(fileMatHang);
			if (strcmp(id_file, id) != 0) {
				fprintf(file_temp, "%s\n", id_file);
				fprintf(file_temp, "%s\n", tenHang);
				fprintf(file_temp, "%s\n", hanDung);
				fprintf(file_temp, "%s\n", congTySanXuat);
				fprintf(file_temp, "%s\n", loaiHang);
				fprintf(file_temp, "%d\n", namSanXuat);
				fprintf(file_temp, "%d\n", soLuong);
			}
			else {
				char confirm;
				found = 1;
				printf("\nBan co chac muon xoa ma hang [%s - %s]? (Y/N): ", id_file, tenHang);
				scanf_s("%c", &confirm, 1);
				while (getchar() != '\n');
				while (confirm != 'y' && confirm != 'Y' && confirm != 'n' && confirm != 'N') {
					printf("\nLua chon khong hop le. Vui long nhap Y de tiep tuc hoac N de ket thuc.\n");
					scanf_s("%c", &confirm, 1);
					while (getchar() != '\n');
				}

				if (confirm == 'Y' || confirm == 'y') {
					printf("\nXoa thanh cong ma hang [%s - %s]\n\n", id_file, tenHang);
				}
				else {
					printf("\n");
					fprintf(file_temp, "%s\n", id_file);
					fprintf(file_temp, "%s\n", tenHang);
					fprintf(file_temp, "%s\n", hanDung);
					fprintf(file_temp, "%s\n", congTySanXuat);
					fprintf(file_temp, "%s\n", loaiHang);
					fprintf(file_temp, "%d\n", namSanXuat);
					fprintf(file_temp, "%d\n", soLuong);
				}
			}
		}

		if (found == 0) printf("\nMa mat hang khong hop le.\n\n");
	}
	
}

void MatHang::Sua(FILE* fileMatHang, FILE* file_temp) {
	printf("Nhap ma mat hang can sua: ");
	char id[MAX_LEN];
	gets_s(id);
	id[strcspn(id, "\n")] = 0;
	char id_file[MAX_LEN];
	int found = 0;

	if (fileMatHang != NULL && file_temp != NULL) {
		rewind(fileMatHang);
		while (fgets(id_file, MAX_LEN, fileMatHang) != NULL) {
			id_file[strcspn(id_file, "\n")] = 0;
			fgets(tenHang, MAX_LEN, fileMatHang);
			tenHang[strcspn(tenHang, "\n")] = 0;
			fgets(hanDung, MAX_LEN, fileMatHang);
			hanDung[strcspn(hanDung, "\n")] = 0;
			fgets(congTySanXuat, MAX_LEN, fileMatHang);
			congTySanXuat[strcspn(congTySanXuat, "\n")] = 0;
			fgets(loaiHang, MAX_LEN, fileMatHang);
			loaiHang[strcspn(loaiHang, "\n")] = 0;
			fscanf_s(fileMatHang, "%d", &namSanXuat);
			fgetc(fileMatHang);
			fscanf_s(fileMatHang, "%d", &soLuong);
			fgetc(fileMatHang);
			if (strcmp(id_file, id) != 0) {
				fprintf(file_temp, "%s\n", id_file);
				fprintf(file_temp, "%s\n", tenHang);
				fprintf(file_temp, "%s\n", hanDung);
				fprintf(file_temp, "%s\n", congTySanXuat);
				fprintf(file_temp, "%s\n", loaiHang);
				fprintf(file_temp, "%d\n", namSanXuat);
				fprintf(file_temp, "%d\n", soLuong);
			}
			else {
				char confirm;
				int choice;
				found = 1;
				printf("\nBan dang sua thong tin mat hang [%s - %s]\n", id_file, tenHang);
				printf("1. Ten hang:\t\t%s\n", tenHang);
				printf("2. Han dung:\t\t%s\n", hanDung);
				printf("3. Cong ty san xuat:\t%s\n", congTySanXuat);
				printf("4. Loai hang:\t\t%s\n", loaiHang);
				printf("5. Nam san xuat:\t\t%d\n", namSanXuat);
				printf("6. So luong:\t\t%d\n", soLuong);

				do {
					printf("\nNhap so tuong ung truong thong tin can sua: ");
					scanf_s(" %d", &choice);
					while (getchar() != '\n');

					switch (choice) {
					case 1:
						printf("\nTen hang moi: ");
						gets_s(tenHang);
						tenHang[strcspn(tenHang, "\n")] = 0;
						break;
					case 2:
						printf("\nHan dung moi: ");
						gets_s(hanDung);
						hanDung[strcspn(hanDung, "\n")] = 0;
						break;
					case 3:
						printf("\nCong ty san xuat moi: ");
						gets_s(congTySanXuat);
						congTySanXuat[strcspn(congTySanXuat, "\n")] = 0;
						break;
					case 4:
						printf("\nLoai hang moi: ");
						gets_s(loaiHang);
						loaiHang[strcspn(loaiHang, "\n")] = 0;
						break;
					case 5:
						printf("\nNam san xuat moi: ");
						scanf_s("%d", &namSanXuat);
						while (getchar() != '\n');
						break;
					case 6:
						printf("\nSo luong moi: ");
						scanf_s("%d", &soLuong);
						while (getchar() != '\n');
						break;
					default:
						printf("\nLua chon khong hop le. Vui long nhap so tu 1 den 7.\n");
						break;
					}

					printf("\nBan co muon tiep tuc sua thong tin khac khong? (Y/N): ");
					scanf_s("%c", &confirm, 1);
					while (getchar() != '\n');

					while (confirm != 'y' && confirm != 'Y' && confirm != 'n' && confirm != 'N') {
						printf("\nLua chon khong hop le. Vui long nhap Y de tiep tuc hoac N de ket thuc chinh sua: ");
						scanf_s("%c", &confirm, 1);
						while (getchar() != '\n');
					}

				} while (confirm == 'y' || confirm == 'Y');

				printf("\nChinh sua thanh cong thong tin ma hang [%s - %s]\n\n", id_file, tenHang);
				fprintf(file_temp, "%s\n", id_file);
				fprintf(file_temp, "%s\n", tenHang);
				fprintf(file_temp, "%s\n", hanDung);
				fprintf(file_temp, "%s\n", congTySanXuat);
				fprintf(file_temp, "%s\n", loaiHang);
				fprintf(file_temp, "%d\n", namSanXuat);
				fprintf(file_temp, "%d\n", soLuong);
			}
		}

		if (found == 0) printf("\nMa mat hang khong hop le.\n\n");
	}
}

void MatHang::TimKiem(FILE* fileMatHang) {
	char tuKhoa[100];
	char id_file[100];
	bool found = 0;
	printf("Nhap tu khoa tim kiem (ma, ten hoac cong ty san xuat): ");
	gets_s(tuKhoa);
	tuKhoa[strcspn(tuKhoa, "\n")] = 0;
	if (fileMatHang != NULL) {
		rewind(fileMatHang);
		while (fgets(id_file, MAX_LEN, fileMatHang) != NULL) {
			id_file[strcspn(id_file, "\n")] = 0;
			fgets(tenHang, MAX_LEN, fileMatHang);
			tenHang[strcspn(tenHang, "\n")] = 0;
			fgets(hanDung, MAX_LEN, fileMatHang);
			hanDung[strcspn(hanDung, "\n")] = 0;
			fgets(congTySanXuat, MAX_LEN, fileMatHang);
			congTySanXuat[strcspn(congTySanXuat, "\n")] = 0;
			fgets(loaiHang, MAX_LEN, fileMatHang);
			loaiHang[strcspn(loaiHang, "\n")] = 0;
			fscanf_s(fileMatHang, "%d", &namSanXuat);
			fgetc(fileMatHang);
			fscanf_s(fileMatHang, "%d", &soLuong);
			fgetc(fileMatHang);
			if (strcmp(tuKhoa, id_file) == 0 || strcmp(tuKhoa, tenHang) == 0 || strcmp(tuKhoa, congTySanXuat) == 0) {
				found = 1;
				printf("Ma hang:\t\t%s\n", id_file);
				printf("Ten hang:\t\t%s\n", tenHang);
				printf("Han dung:\t\t%s\n", hanDung);
				printf("Cong ty san xuat:\t%s\n", congTySanXuat);
				printf("Loai hang:\t\t%s\n", loaiHang);
				printf("Nam san xuat:\t\t%d\n", namSanXuat);
				printf("So luong:\t\t%d\n", soLuong);
				break;
			}
		}
		if (found == 0) printf("\nKhong tim thay mat hang phu hop!\n\n");
	}
}

