#pragma once
#include <iostream>
#include <conio.h>
#include <ctime>
#include <fstream>
#include <stdio.h>
using namespace std;

#define MAX 100
#define Enter 13
#define DE 150
#define TB 90
#define KHO 40
#define CRAZZY 25
#define LEN 1
#define XUONG 2
#define TRAI 3
#define PHAI 4
#define TUONG_TRAI 10 
#define TUONG_TREN 5 
#define TUONG_PHAI 110
#define TUONG_DUOI 25
#define CAY_TRAI_TREN 30 
#define CAY_TRAI_DUOI 50
#define CAY_PHAI_TREN 70
#define CAY_PHAI_DUOI 90


struct Toado
{
	int x;
	int y;
};


//tạo rắn
void khoitao();
void hienthiran(Toado dotcuoicu, int & dau, int & than, int mauran);
void themdot();

//cập nhật rắn
Toado dichuyen(int huong);
void batsukien(int & huong);

//vẽ
int random(int a, int b);
void vetuong();

//xử lý va chạm
bool vacham(int xmoi, int ymoi);
void xulyvacham(int & xmoi, int & ymoi, int & xbonus, int & ybonus, int & d, int & mau, int & hard, int & DOKHO, int & scoreDE, int & scoreTB, int & scoreKHO, int & scoreCZ);
void HienThiGame(int xmoi, int ymoi, int xbonus, int ybonus, int d, char s[], int & hard, int & DOKHO, int colorMoi, int & scoreDE, int & scoreTB, int & scoreKHO, int & scoreCZ);
void LoaiDiem(int & hard, int & DOKHO, int & scoreDE, int & scoreTB, int & scoreKHO, int & scoreCZ);

//xử thua
int xuthua();
int RanTuAn();
bool xuly();
void xuat(int hard, int DOKHO, int scoreDE, int scoreTB, int scoreKHO, int scoreCZ);

void ChayGame(int & huong, int & xmoi, int & ymoi, int & xbonus, int & ybonus, int & d, int & dau, int & than, int & mauran, char s[], int hard, int DOKHO, int & colorMoi, int & scoreDE, int & scoreTB, int & scoreKHO, int & scoreCZ);




