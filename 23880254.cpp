#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Utils.h"
#include "BaseObject.h"
#include "MatHang.h"
#include "CuaHang.h"

int main()
{
	char input[100];

	int choice;
	int subChoice;
	int back = 1;

	CuaHang* cuaHang = new CuaHang();
	FILE* fileMatHang;
	FILE* fileMatHang_temp;
	FILE* fileLoaiHang;
	FILE* fileLoaiHang_temp;

	do {
		system("cls");
		printf("========QUAN LY CUA HANG========\n\n");
		printf("1. Quan ly mat hang\n");
		printf("2. Quan ly loai hang\n");
		printf("3. Quan ly hoa don ban hang\n");
		printf("4. Quan ly hoa don nhap hang\n");
		printf("5. Thong ke\n\n");
		printf("Chon chuc nang: ");

		gets_s(input);
		input[strcspn(input, "\n")] = 0;

		if (!isNumber(input)) {
			choice = -1;
		}

		choice = atoi(input);
		xoaManHinh(3);

		switch (choice) {
		case 1:
			system("cls");
			printf("========QUAN LY MAT HANG========\n\n");
			printf("1. Them mat hang\n");
			printf("2. Xoa mat hang\n");
			printf("3. Sua mat hang\n");
			printf("4. Tim kiem mat hang\n");
			printf("5. Xem danh sach mat hang\n");
			printf("0. Quay lai\n\n");
			printf("=============================\n\n");
			printf("Chon chuc nang: ");
			scanf_s("%d", &subChoice);
			while (getchar() != '\n');
			printf("\n");

			switch (subChoice) {
			case 1:
				fopen_s(&fileMatHang, "MatHang.txt", "at");

				if (fileMatHang != NULL) {
					cuaHang->Them(fileMatHang, 1);
					fclose(fileMatHang);
				}

				break;
			case 2:
				fopen_s(&fileMatHang, "MatHang.txt", "rt");
				fopen_s(&fileMatHang_temp, "MatHang_temp.txt", "wt");
				if (fileMatHang != NULL && fileMatHang_temp != NULL) {
					cuaHang->Xoa(fileMatHang, fileMatHang_temp, 1);
					fclose(fileMatHang);
					fclose(fileMatHang_temp);
					remove("MatHang.txt");
					int renamed = rename("MatHang_temp.txt", "MatHang.txt");
				}
				break;
			case 3:
				fopen_s(&fileMatHang, "MatHang.txt", "rt");
				fopen_s(&fileMatHang_temp, "MatHang_temp.txt", "wt");
				if (fileMatHang != NULL && fileMatHang_temp != NULL) {
					cuaHang->Sua(fileMatHang, fileMatHang_temp, 1);
					fclose(fileMatHang);
					fclose(fileMatHang_temp);
					remove("MatHang.txt");
					int renamed = rename("MatHang_temp.txt", "MatHang.txt");
				}
				break;
			case 4:
				fopen_s(&fileMatHang, "MatHang.txt", "rt");
				if (fileMatHang != NULL) {
					cuaHang->TimKiem(fileMatHang, 1);
					fclose(fileMatHang);
				}
				break;
			case 5:
				printf("5. Xem danh sach mat hang\n");
				break;
			case 0:
				continue;
			default:
				printf("Lua chon khong hop le!");
			}
			break;
		case 2:
			system("cls");
			printf("========QUAN LY LOAI HANG========\n\n");
			printf("1. Them loai hang\n");
			printf("2. Xoa loai hang\n");
			printf("3. Sua loai hang\n");
			printf("4. Tim kiem loai hang\n");
			printf("5. Xem danh sach loai hang\n");
			printf("0. Quay lai\n\n");
			printf("=============================\n\n");
			printf("Chon chuc nang: ");
			scanf_s("%d", &subChoice);
			while (getchar() != '\n');
			printf("\n");

			switch (subChoice) {
			case 1:
				fopen_s(&fileLoaiHang, "LoaiHang.txt", "at");

				if (fileLoaiHang != NULL) {
					cuaHang->Them(fileLoaiHang, 2);
					fclose(fileLoaiHang);
				}

				break;
			case 2:
				fopen_s(&fileLoaiHang, "LoaiHang.txt", "rt");
				fopen_s(&fileLoaiHang_temp, "LoaiHang_temp.txt", "wt");
				if (fileLoaiHang != NULL && fileLoaiHang_temp != NULL) {
					cuaHang->Xoa(fileLoaiHang, fileLoaiHang_temp, 2);
					fclose(fileLoaiHang);
					fclose(fileLoaiHang_temp);
					remove("LoaiHang.txt");
					int renamed = rename("LoaiHang_temp.txt", "LoaiHang.txt");
				}
				break;
			case 3:
				fopen_s(&fileLoaiHang, "LoaiHang.txt", "rt");
				fopen_s(&fileLoaiHang_temp, "LoaiHang_temp.txt", "wt");
				if (fileLoaiHang != NULL && fileLoaiHang_temp != NULL) {
					cuaHang->Sua(fileLoaiHang, fileLoaiHang_temp, 2);
					fclose(fileLoaiHang);
					fclose(fileLoaiHang_temp);
					remove("LoaiHang.txt");
					int renamed = rename("LoaiHang_temp.txt", "LoaiHang.txt");
				}
				break;
			case 4:
				printf("4. Tim kiem mat hang\n");
				break;
			case 5:
				printf("5. Xem danh sach mat hang\n");
				break;
			case 0:
				continue;
			default:
				printf("Lua chon khong hop le!");
			}
			break;
		case 3:
			printf("3. Quan ly hoa don ban hang\n\n");
			break;
		case 4:
			printf("4. Quan ly hoa don nhap hang\n\n");
			break;
		case 5:
			printf("5. Thong ke\n\n");
			break;
		default:
			printf("Lua chon khong hop le!\n\n");
		}

		printf("Tro ve truoc, bam '1'\n");
		printf("Thoat chuong trinh, bam '0'\n");
		scanf_s("%d", &back);
		while (getchar() != '\n');

		if (back == 1) {
			system("cls");
		}
		else {
			exit(0);
		}

	} while (back == 1);

}