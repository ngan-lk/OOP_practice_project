#include "BaseInvoice.h"
#include <string.h>

//void BaseInvoice::Doc(FILE* file) {
//    if (file != NULL) {
//        fgets(soHoaDon, MAX_LEN, file);
//        soHoaDon[strcspn(soHoaDon, "\n")] = 0;
//        fgets(ngayHoaDon, MAX_LEN, file);
//        ngayHoaDon[strcspn(ngayHoaDon, "\n")] = 0;
//        fgets(maHang, MAX_LEN, file);
//        maHang[strcspn(maHang, "\n")] = 0;
//        fscanf_s(file, "%d", &soLuong);
//        fgetc(file);
//        fscanf_s(file, "%d", &soTien);
//        fgetc(file);
//    }
//}

const char* BaseInvoice::taoSoHoaDon(FILE* file, const char* prefix) {
    rewind(file);
    int soLuongHoaDon = 0;
    char soHoaDonTao[100];

    while (fgets(soHoaDon, MAX_LEN, file) != NULL) {
        soHoaDon[strcspn(soHoaDon, "\n")] = 0;
        fgets(ngayHoaDon, MAX_LEN, file);
        ngayHoaDon[strcspn(ngayHoaDon, "\n")] = 0;
        fgets(maHang, MAX_LEN, file);
        maHang[strcspn(maHang, "\n")] = 0;
        fscanf_s(file, "%d", &soLuongBan);
        fgetc(file);
        fscanf_s(file, "%d", &soTien);
        fgetc(file);
        soLuongHoaDon++;
    }
    sprintf_s(soHoaDonTao, MAX_LEN, "%s%03d", prefix, soLuongHoaDon + 1);
    return soHoaDonTao;
}

