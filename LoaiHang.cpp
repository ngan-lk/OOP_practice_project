#include "LoaiHang.h"
#include <stdio.h>
#include <string.h>

void LoaiHang::xuatLoaiHang() {
	printf("Ma loai hang:\t\t%s\n", getId());
	printf("Ten loai hang:\t\t%s\n", tenLoaiHang);
}

bool LoaiHang::Them(FILE* file) {
	char id[100];
	printf("Nhap ma loai hang: ");
	scanf_s("%s", id, 100);
	nhapId(id);
	char c;

	do {
		c = getchar();
	} while (c != EOF && c != '\n');

	printf("Nhap ten loai hang: ");
	gets_s(tenLoaiHang);

	if (file != NULL) {
		fprintf(file, "%s\n", getId());
		fprintf(file, "%s\n", tenLoaiHang);
	}
	else {
		printf("Khong mo duoc file!");
	}

	return true;
}

void LoaiHang::docFile(FILE* file) {
	if (file != NULL) {
		BaseObject::docFile(file);
		fgets(tenLoaiHang, MAX_LEN, file);
		size_t len = strlen(tenLoaiHang);

		if (len > 0 && tenLoaiHang[len - 1] == '\n') {
			tenLoaiHang[len - 1] = '\0';
		}
	}
}

bool LoaiHang::kiemTraLoaiHangTonTai(const char* maLoaiHang) {
	FILE* file = NULL;
	fopen_s(&file, "LoaiHang.txt", "rt");
	if (file != NULL) {
		char id[MAX_LEN];
		char tenLoaiHang[MAX_LEN];

		while (fgets(id, MAX_LEN, file) != NULL) {
			id[strcspn(id, "\n")] = 0;
			fgets(tenLoaiHang, 100, file);
			tenLoaiHang[strcspn(tenLoaiHang, "\n")] = 0;

			if (strcmp(id, maLoaiHang) == 0) {
				fclose(file);
				return true;
			}
		}

		fclose(file);
		return false;
	}
}

void LoaiHang::Xoa(FILE* fileLoaiHang, FILE* file_temp) {
	printf("Nhap ma loai hang can xoa: ");
	char id[MAX_LEN];
	gets_s(id);
	id[strcspn(id, "\n")] = 0;
	char id_file[MAX_LEN];
	int found = 0;

	if (fileLoaiHang != NULL && file_temp != NULL) {
		rewind(fileLoaiHang);
		while (fgets(id_file, MAX_LEN, fileLoaiHang) != NULL) {
			id_file[strcspn(id_file, "\n")] = 0;
			fgets(tenLoaiHang, MAX_LEN, fileLoaiHang);
			tenLoaiHang[strcspn(tenLoaiHang, "\n")] = 0;
			if (strcmp(id_file, id) != 0) {
				fprintf(file_temp, "%s\n", id_file);
				fprintf(file_temp, "%s\n", tenLoaiHang);
			}
			else {
				char confirm;
				found = 1;
				printf("\nBan co chac muon xoa loai hang [%s - %s]? (Y/N): ", id_file, tenLoaiHang);
				scanf_s("%c", &confirm, 1);
				while (getchar() != '\n');
				while (confirm != 'y' && confirm != 'Y' && confirm != 'n' && confirm != 'N') {
					printf("\nLua chon khong hop le. Vui long nhap Y de tiep tuc hoac N de ket thuc.\n");
					scanf_s("%c", &confirm, 1);
					while (getchar() != '\n');
				}

				if (confirm == 'Y' || confirm == 'y') {
					printf("\nXoa thanh cong loai hang [%s - %s]\n\n", id_file, tenLoaiHang);
				}
				else {
					printf("\n");
					fprintf(file_temp, "%s\n", id_file);
					fprintf(file_temp, "%s\n", tenLoaiHang);
				}
			}
		}

		if (found == 0) printf("\nMa loai hang khong hop le.\n\n");
	}
}

void LoaiHang::Sua(FILE* fileLoaiHang, FILE* file_temp) {
	printf("Nhap ma loai hang can sua: ");
	char id[MAX_LEN];
	gets_s(id);
	id[strcspn(id, "\n")] = 0;
	char id_file[MAX_LEN];
	int found = 0;

	if (fileLoaiHang != NULL && file_temp != NULL) {
		rewind(fileLoaiHang);
		while (fgets(id_file, MAX_LEN, fileLoaiHang) != NULL) {
			id_file[strcspn(id_file, "\n")] = 0;
			fgets(tenLoaiHang, MAX_LEN, fileLoaiHang);
			tenLoaiHang[strcspn(tenLoaiHang, "\n")] = 0;
			if (strcmp(id_file, id) != 0) {
				fprintf(file_temp, "%s\n", id_file);
				fprintf(file_temp, "%s\n", tenLoaiHang);
			}
			else {
				char confirm;
				found = 1;
				printf("\nBan dang sua thong tin loai hang [%s - %s]\n", id_file, tenLoaiHang);
				printf("Ten loai hang: %s\n", tenLoaiHang);
				printf("\nTiep tuc? (Y/N): ");
				scanf_s("%c", &confirm, 1);
				while (getchar() != '\n');

				do {
					if (confirm == 'y' || confirm == 'Y') {
						printf("\nTen loai hang moi: ");
						gets_s(tenLoaiHang);
						tenLoaiHang[strcspn(tenLoaiHang, "\n")] = 0;
						break;
					}
					while (confirm != 'y' && confirm != 'Y' && confirm != 'n' && confirm != 'N') {
						printf("\nLua chon khong hop le. Vui long nhap Y de tiep tuc hoac N de ket thuc chinh sua: ");
						scanf_s("%c", &confirm, 1);
						while (getchar() != '\n');
					}
				} while (confirm == 'y' || confirm == 'Y');

				printf("\nChinh sua thanh cong thong tin loai hang [%s - %s]\n\n", id_file, tenLoaiHang);
				fprintf(file_temp, "%s\n", id_file);
				fprintf(file_temp, "%s\n", tenLoaiHang);
			}
		}
		if (found == 0) printf("\nMa loai hang khong hop le.\n\n");
	}
}

void LoaiHang::TimKiem(FILE* fileMatHang) {


}
