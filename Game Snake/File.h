#pragma once
#include "MyFuntion.h"

#define TREN_DIEM 10 // y
#define TRAI_DIEM 45 // x
#define PHAI_DIEM 77 // x
#define DUOI_DIEM 23 // y

//Ghi Điểm cao nhất
void Diem(int & hard, int & DOKHO, int & scoreDE, int & scoreTB, int & scoreKHO, int & scoreCZ, int & maxDE, int & maxTB, int & maxKHO, int & maxCZ);
void DiemCaoNhat(char s[], int & hard, int & maxDE, int & maxTB, int & maxKHO, int & maxCZ, int & scoreDE, int & scoreTB, int & scoreKHO, int & scoreCZ);
void KhungDiem();