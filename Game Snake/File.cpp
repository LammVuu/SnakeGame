#pragma once
#include "File.h"
#include "kmin_console.h"
#include "Menu.h"


void Diem(int & hard,int & DOKHO, int & scoreDE, int & scoreTB, int & scoreKHO, int & scoreCZ, int & maxDE, int & maxTB, int & maxKHO, int & maxCZ)
{
	// các điểm khi bị xử thua sẽ được lưu vào các file dưới đây
	if (DoKho(DOKHO) == DE) // Nếu Độ khó là Dễ sẽ lưu vào file Dễ. các Dộ khó khác sẽ tương tự như thế
	{
		ofstream DiemDE;
		DiemDE.open("Diem DE.txt");
		DiemDE << scoreDE << endl;
		DiemDE.close();
	}
	else if (DoKho(DOKHO) == TB)
	{
		ofstream DiemTB;
		DiemTB.open("Diem TB.txt");
		DiemTB << scoreTB << endl;
		DiemTB.close();
	}
	else if (DoKho(DOKHO) == KHO)
	{
		ofstream DiemKHO;
		DiemKHO.open("Diem KHO.txt");
		DiemKHO << scoreKHO << endl;
		DiemKHO.close();
	}
	else if (DoKho(DOKHO) == CRAZZY)
	{
		ofstream DiemCZ;
		DiemCZ.open("Diem CZ.txt");
		DiemCZ << scoreCZ << endl;
		DiemCZ.close();
	}
}
void DiemCaoNhat(char s[], int & hard, int & maxDE, int & maxTB, int & maxKHO, int & maxCZ, int & scoreDE, int & scoreTB, int & scoreKHO, int & scoreCZ)
{
	// Hàm này sẽ đọc các File điểm đã lưu ở hàm trên.
	clrscr();
	KhungDiem();
	ifstream diemde;
	diemde.open("Diem DE.txt");
	if (diemde.fail())
		scoreDE = 0;
	else
	diemde >> scoreDE;
	diemde.close();

	ifstream diemtb;
	diemtb.open("Diem TB.txt");
	if (diemtb.fail())
		scoreTB = 0;
	else
	diemtb >> scoreTB;
	diemtb.close();

	ifstream diemkho;
	diemkho.open("Diem KHO.txt");
	if (diemkho.fail())
		scoreKHO = 0;
	else
	diemkho >> scoreKHO;
	diemkho.close();

	ifstream diemcz;
	diemcz.open("Diem CZ.txt");
	if (diemcz.fail())
		scoreCZ = 0;
	else
	diemcz >> scoreCZ;
	diemcz.close();
	
	//So sánh các điểm khi đọc được từ File và trong cùng một Độ khó
	if (scoreDE > 0 && scoreDE > maxDE) // So sánh điểm Dễ
	{
		maxDE = scoreDE;
		ofstream FileOut;
		FileOut.open("Diem DE cao nhat.txt");
		FileOut << maxDE;
		FileOut.close();
	}
	else if (scoreDE <= maxDE)
		scoreDE = 0;

	if (scoreTB > 0 && scoreTB > maxTB)// So Sánh điểm Trung Bình
	{
		maxTB = scoreTB;
		ofstream FileOut;
		FileOut.open("Diem TB cao nhat.txt");
		FileOut << maxTB;
		FileOut.close();
	}
	else if (scoreTB <= maxTB)
		scoreTB = 0;

	if (scoreKHO > 0 && scoreKHO > maxKHO) // So Sánh điểm Khó
	{
		maxKHO = scoreKHO;
		ofstream FileOut;
		FileOut.open("Diem KHO cao nhat.txt");
		FileOut << maxKHO;
		FileOut.close();
	}
	else if (scoreKHO <= maxKHO)
		scoreKHO = 0;

	if (scoreCZ > 0 && scoreCZ > maxCZ) // cuối cùng là // So Sánh điểm Crazzy
	{
		maxCZ = scoreCZ;
		ofstream FileOut;
		FileOut.open("Diem CRAZZY cao nhat.txt");
		FileOut << maxCZ;
		FileOut.close();
	}
	else if (scoreCZ <= maxCZ)
		scoreCZ = 0;
	
	//sau khi so sánh xong sẽ xuất ra màn hình cho người chơi xem
	gotoXY(53, 12); setTextColor(CYAN_COLOR); cout << "Player: "; setTextColor(WHITE_COLOR); cout << s;
	ifstream FileDe;
	FileDe.open("Diem DE cao nhat.txt");
	FileDe >> maxDE;
	FileDe.close();
	gotoXY(53, 15); setTextColor(BLUE_COLOR); cout << "DE"; gotoXY(67, 15); setTextColor(WHITE_COLOR); cout << maxDE;
	ifstream FileTb;
	FileTb.open("Diem TB cao nhat.txt");
	FileTb >> maxTB;
	FileTb.close();
	gotoXY(53, 17); setTextColor(YELLOW_COLOR); cout << "TB"; gotoXY(67, 17); setTextColor(WHITE_COLOR); cout << maxTB;
	ifstream FileKho;
	FileKho.open("Diem KHO cao nhat.txt");
	FileKho >> maxKHO;
	FileKho.close();
	gotoXY(53, 19); setTextColor(GREEN_COLOR); cout << "KHO"; gotoXY(67, 19); setTextColor(WHITE_COLOR); cout << maxKHO;
	ifstream FileCz;
	FileCz.open("diem CRAZZY cao nhat.txt");
	FileCz >> maxCZ;
	FileCz.close();
	gotoXY(53, 21); setTextColor(DARK_RED_COLOR); cout << "CRAZZY"; gotoXY(67, 21); setTextColor(WHITE_COLOR); cout << maxCZ;
	_getch();
}
void KhungDiem() // Vẽ Khung trang trí cho phần Điểm Cao Nhất
{
	gotoXY(30, 3); setTextColor(YELLOW_COLOR);
	cout << "0   0  00000  000000  0   0    00000  00000  00000  00000  00000";
	gotoXY(30, 4);
	cout << "0   0    0    0       0   0    0      0      0   0  0   0  0";
	gotoXY(30, 5);
	cout << "00000    0    0   00  00000    00000  0      0   0  00000  000";
	gotoXY(30, 6);
	cout << "0   0    0    0    0  0   0        0  0      0   0  0  0   0";
	gotoXY(30, 7);
	cout << "0   0  00000  000000  0   0    00000  00000  00000  0   0  00000";
	//vẽ cột ngang trên
	setTextColor(DARK_YELLOW_COLOR);
	for (int x = TRAI_DIEM; x <= PHAI_DIEM; x++)
	{
		gotoXY(x, 10);
		cout << (char)205;
	}
	//vẽ cột dọc trái
	for (int y = TREN_DIEM; y <= DUOI_DIEM; y++)
	{
		gotoXY(TRAI_DIEM, y);
		cout << (char)186;
		gotoXY(TRAI_DIEM, TREN_DIEM);
		cout << (char)201;
	}
	//vẽ cột ngang dưới
	for (int x = TRAI_DIEM; x <= PHAI_DIEM; x++)
	{
		gotoXY(x, DUOI_DIEM);
		cout << (char)205;
		gotoXY(TRAI_DIEM, DUOI_DIEM);
		cout << (char)200;
	}
	//vẽ cột dọc phải
	for (int y = TREN_DIEM; y <= DUOI_DIEM; y++)
	{
		gotoXY(PHAI_DIEM, y);
		cout << (char)186;
		gotoXY(PHAI_DIEM, TREN_DIEM);
		cout << (char)187;
		gotoXY(PHAI_DIEM, DUOI_DIEM);
		cout << (char)188;
	}
}

