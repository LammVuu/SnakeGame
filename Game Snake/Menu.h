#pragma once
#include "MyFuntion.h"

//Tọa độ khung tên
#define TRAI_TEN 35 // x
#define TREN_TEN 17 // y
#define DUOI_TEN 23 // y
#define PHAI_TEN 87 // x

//Tọa độ khung Hướng dẫn
#define TRAI_HD 34 // x
#define TREN_HD 11 // y
#define DUOI_HD 22 // y
#define PHAI_HD 91 // x

//Tọa độ Khung NewPlayer
#define TRAI_PL 30 // x
#define PHAI_PL 90 // X
#define TREN_PL 9 // y
#define DUOI_PL 23 // y

//Tọa độ Khung Dộ khó
#define TRAI_DK 52 // x
#define PHAI_DK 74 // x
#define TREN_DK 8 // y
#define DUOI_DK 23 // y

//Tọa độ con trỏ Menu
#define MENU_X 55
#define MENU_Y_TREN 10
#define MENU_Y_DUOI 20

//Tọa độ con trỏ Tùy chọn
#define TUYCHON_X 53
#define TUYCHON_Y_TREN 12
#define TUYCHON_Y_DUOI 18

//Tọa độ con trỏ Độ Khó
#define DOKHO_X 57
#define DOKHO_Y_TREN 12
#define DOKHO_Y_DUOI 18

//Tọa độ con trỏ Màu rắn
#define MAURAN_X 53
#define MAURAN_Y_TREN 9
#define MAURAN_Y_DUOI 19

//Tọa độ con trỏ NewPlayer
#define NL_X 46
#define NL_Y 12
#define NL_YESNO_TREN 17
#define NL_YESNO_X 57

//phần khởi động
void Loading();
void KhungTen();
void NhapTen(char s[], char z[], char b1[], char b2[], char b3[], char b4[], char b5[], char b6[], char b7[], char b8[], char b9[], char b0[]);
void Xoa(char S[], int vitri);
void XoaKhoangTrang(char S[]);

//Phần Menu
void MenuStart(char s[], char z[], char b1[], char b2[], char b3[], char b4[], char b5[], char b6[], char b7[], char b8[], char b9[], char b0[]);
int ChonMenu(int & ytro, int & key, int & menu);
void C4();
void KhungHuongDan();
void C5();
void KhungAboutUs();

//Tùy chọn chức năng
void TuyChon(int & yTuychon, int & yDokho, int & yMauran, int & yNL, int & key, int & hard, int & DOKHO, int & dau, int & than, int & mauran, int & chon, char s[], char z[], char b1[], char b2[], char b3[], char b4[], char b5[], char b6[], char b7[], char b8[], char b9[], char b0[], int & scoreDE, int & scoreTB, int & scoreKHO, int & scoreCZ, int & maxDE, int & maxTB, int & maxKHO, int & maxCZ);
void KhungTuyChon();
void NewPlayer(int & yNL, int & yTuychon, int & yDokho, int & yMauran, int & key, int & dau, int & than, int & mauran, int & chon, int & hard, int & DOKHO, char s[], char z[], char b1[], char b2[], char b3[], char b4[], char b5[], char b6[], char b7[], char b8[], char b9[], char b0[], int & scoreDE, int & scoreTB, int & scoreKHO, int & scoreCZ, int & maxDE, int & maxTB, int & maxKHO, int & maxCZ);
void KhungNewPlayer();

//Độ khó
void chondokho(int & yDokho, int yTuychon, int yMauran, int yNL, int & key, int & hard, int DOKHO, int dau, int than, int mauran, int chon, char s[], char z[], char b1[], char b2[], char b3[], char b4[], char b5[], char b6[], char b7[], char b8[], char b9[], char b0[], int maxDE, int maxTB, int maxKHO, int maxCZ, int scoreDE, int scoreTB, int scoreKHO, int scoreCZ);
void KhungDokho();
void FileDoKho(int hard, int DOKHO);
int DoKho(int & DOKHO);

//Tùy chọn màu rắn
void ChonMauRan(int & yMauran, int yTuychon, int yDokho, int yNL, int & key, int hard, int DOKHO, int dau, int than, int & mauran, int chon, char s[], char z[], char b1[], char b2[], char b3[], char b4[], char b5[], char b6[], char b7[], char b8[], char b9[], char b0[], int maxDE, int maxTB, int maxKHO, int maxCZ, int scoreDE, int scoreTB, int scoreKHO, int scoreCZ);
void KhungMauRan();
void MauRan(int & dau, int & than, int mauran);






//Màn
void man1();