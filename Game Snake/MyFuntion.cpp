#include "kmin_console.h"
#include "MyFuntion.h"
#include "Menu.h"


Toado ran[MAX];
int sodot = 3;

//Con Rắn
void khoitao()
{
	sodot = 3;
	ran[0].x = TUONG_TRAI + 3;
	ran[1].x = TUONG_TRAI + 2;
	ran[2].x = TUONG_TRAI + 1;
	ran[0].y = ran[1].y = ran[2].y = TUONG_TREN + 1;
}
void themdot()
{
	ran[sodot] = ran[sodot - 1];
	sodot++;
}
void hienthiran(Toado dotcuoicu, int & dau, int & than, int mauran)
{
	ifstream FileIn;
	FileIn.open("Color Ran.txt");
		if (FileIn.fail())
		{
			dau = WHITE_COLOR; than = WHITE_COLOR;
		}
		else
		{
			FileIn >> dau;
			FileIn >> than;
		}
	FileIn.close();
	for (int i = 0; i < sodot; i++)
	{
		gotoXY(ran[0].x, ran[0].y);
		setTextColor(dau);
		cout << (char)157;
		gotoXY(ran[i].x, ran[i].y);
		setTextColor(than);
		cout << (char)155;
	}
	gotoXY(dotcuoicu.x, dotcuoicu.y);
	cout << " ";

}
//Bắt sự kiện
Toado dichuyen(int huong)
{
	Toado dotcuoicu = ran[sodot - 1];
	for (int i = sodot; i>0; i--)
	{
		ran[i] = ran[i - 1];
	}
	switch (huong)
	{
	case LEN: ran[0].y--;
		break;
	case XUONG: ran[0].y++;
		break;
	case TRAI: ran[0].x--;
		break;
	case PHAI:ran[0].x++;
		break;
	}
	return dotcuoicu;
}
void batsukien(int & huong)
{
	int key = inputKey();
	if ((key == 'w' || key == 'W' || key == KEY_UP) && huong != XUONG)
		huong = LEN;
	else if ((key == 's' || key =='S'|| key == KEY_DOWN) && huong != LEN)
		huong = XUONG;
	else if ((key == 'a' || key == 'A' ||key == KEY_LEFT) && huong != PHAI)
		huong = TRAI;
	else if ((key == 'd' || key == 'D' || key == KEY_RIGHT) && huong != TRAI)
		huong = PHAI;
	else if (xuly() == true)
		huong = PHAI;
	else if (key == 27 || key == 'p' || key == 'P')
	{
		gotoXY(40, 15);
		setTextColor(15);
		system("pause");
		clrscr();
		vetuong();
	}
}

//vẽ
int random(int a, int b)
{
	return a + rand() % (b - a + 1);
}
void vetuong()
{
	//in TUONG TREN
	for (int x = TUONG_TRAI; x <= TUONG_PHAI; x++)
	{
		gotoXY(x, TUONG_TREN);
		setTextColor(WHITE_COLOR);
		cout << char(223);
	}
	//in TUONG DUOI
	for (int x = TUONG_TRAI; x <= TUONG_PHAI; x++)
	{
		gotoXY(x, TUONG_DUOI);
		setTextColor(WHITE_COLOR);
		cout << (char)220;
	}
	//in TUONG TRAI
	for (int y = TUONG_TREN; y <= TUONG_DUOI; y++)
	{
		gotoXY(TUONG_TRAI, y);
		setTextColor(WHITE_COLOR);
		cout << (char)219;
	}
	//in TUONG PHAI
	for (int y = TUONG_TREN; y <= TUONG_DUOI; y++)
	{
		gotoXY(TUONG_PHAI, y);
		setTextColor(WHITE_COLOR);
		cout << (char)219;
	}
}

//Hiển thị và Xử lý va chạm
bool vacham(int xmoi, int ymoi)
{
	if (ran[0].x == xmoi && ran[0].y == ymoi) // Nếu rắn đụng trúng mồi
		return true;
	else
		return false;
}
void xulyvacham(int & xmoi, int & ymoi, int & xbonus, int & ybonus, int & d, int & colorMoi, int & hard, int & DOKHO, int & scoreDE, int & scoreTB, int & scoreKHO, int & scoreCZ)
{
	if (vacham(xmoi, ymoi) == true)
	{
		colorMoi = random(1, 15);
		ifstream FileIn;
		FileIn.open("Dokho.txt"); // mở file Độ khó
		if (FileIn.fail())
			DOKHO = DE;
		else
		FileIn >> DOKHO;
		FileIn.close();
		if (DOKHO==DE) // đụng trúng mồi sẽ tăng điểm và thêm đốt
			scoreDE++;
		else if (DOKHO==TB)
			scoreTB++;
		else if (DOKHO==KHO)
			scoreKHO++;
		else if (DOKHO==CRAZZY)
			scoreCZ++;
		d++;
		xmoi = random(TUONG_TRAI + 1, TUONG_PHAI - 1);
		ymoi = random(TUONG_TREN + 1, TUONG_DUOI - 1);
		themdot();
	}
	if (ran[0].x == xbonus && ran[0].y == ybonus) //rắn đụng trúng mồi Bonus sẽ + 5 điểm
	{
		if (DoKho(DOKHO) == DE)
			scoreDE = scoreDE + 5;
		else if (DoKho(DOKHO) == TB)
			scoreTB = scoreTB + 5;
		else if (DoKho(DOKHO) == KHO)
			scoreKHO = scoreKHO + 5;
		else if (DoKho(DOKHO) == CRAZZY)
			scoreCZ = scoreCZ + 5;
		xbonus = random(TUONG_TRAI + 1, TUONG_PHAI - 1);
		ybonus = random(TUONG_TREN + 1, TUONG_DUOI - 1);
		d = 0;
	}
	if (xuly() == true)//Nếu thua game
	{
		xuat(hard, DOKHO, scoreDE, scoreTB, scoreKHO, scoreCZ);
		xmoi = random(TUONG_TRAI + 1, TUONG_PHAI - 1);
		ymoi = random(TUONG_TREN + 1, TUONG_DUOI - 1);
		d = 0;
	}
}
void HienThiGame(int xmoi, int ymoi, int xbonus, int ybonus, int d, char s[], int & hard, int & DOKHO, int colorMoi, int & scoreDE, int & scoreTB, int & scoreKHO, int & scoreCZ)
{
	// Hiển thị thông tin người chơi, điểm và mức độ trên màn hình console
	gotoXY(TUONG_TRAI + 2, 1);
	setTextColor(11); cout << "Nguoi Choi: "; setTextColor(WHITE_COLOR); cout << s;
	gotoXY(TUONG_TRAI + 32, 1);
	setTextColor(11);
	cout << "Diem: "; setTextColor(WHITE_COLOR);
	gotoXY(TUONG_TRAI + 38, 1);
	if (DoKho(DOKHO)==DE)
		cout << scoreDE;
	else if (DoKho(DOKHO) == TB)
		cout << scoreTB;
	else if (DoKho(DOKHO) == KHO)
		cout << scoreKHO;
	else if (DoKho(DOKHO) == CRAZZY)
		cout << scoreCZ;
	gotoXY(TUONG_TRAI + 50, 1);
	setTextColor(11); cout << "Do Kho: ";
	if (DoKho(DOKHO) == DE) { setTextColor(WHITE_COLOR); cout << "DE"; } 
	else if (DoKho(DOKHO) == TB) { setTextColor(WHITE_COLOR); cout << "TRUNG BINH"; }
	else if (DoKho(DOKHO) == KHO) { setTextColor(WHITE_COLOR); cout << "KHO"; }
	else if (DoKho(DOKHO) == CRAZZY) { setTextColor(WHITE_COLOR); cout << "CRAZZY"; }
	gotoXY(xmoi, ymoi);
	setTextColor(colorMoi);
	cout << (char)111;
	if (d >= 6)
	{
		gotoXY(xbonus, ybonus);
		setTextColor(random(1,15));
		cout << (char)225;
	}
}
void LoaiDiem(int & hard,int & DOKHO, int & scoreDE, int & scoreTB, int & scoreKHO, int & scoreCZ) //dựa trên Độ khó sẽ có điểm khác nhau
{
	if (DoKho(DOKHO) == DE) scoreDE = 0;
	else if (DoKho(DOKHO) == TB) scoreTB = 0;
	else if (DoKho(DOKHO) == KHO) scoreKHO = 0;
	else if (DoKho(DOKHO) == CRAZZY) scoreCZ = 0;
}



//xử lý thua
int xuthua()
{
	//nếu rắn đụng trúng tường
	if (ran[0].x == TUONG_TRAI || ran[0].x == TUONG_PHAI || ran[0].y == TUONG_DUOI || ran[0].y == TUONG_TREN)
		return 1;
	else
		return -1;
}
int RanTuAn()
{
	//nếu rắn tự ăn bản thân
	for (int i = 1; i <= sodot; i++)
	if (ran[0].x == ran[i].x && ran[0].y == ran[i].y)
		return 1;
}
bool xuly()
{
	// xử lý thua khi 2 trường hợp trên xảy ra
	if (xuthua() == 1 || RanTuAn() == 1)
		return true;
	else
		return false;
}
void xuat(int hard, int DOKHO, int scoreDE, int scoreTB, int scoreKHO, int scoreCZ)
{
	//xuất các thông tin như điểm khi bị thua
	gotoXY(47, 13);
	setTextColor(12);
	cout << "Game over!  Diem cua ban: ";
	setTextColor(WHITE_COLOR);
	if (DoKho(DOKHO) == DE) // Tùy vào Đô khó game sẽ có loại điểm tương ứng
	{
		cout << scoreDE << endl;
	}
	else if (DoKho(DOKHO) == TB)
	{
		cout << scoreTB << endl;
	}
	else if (DoKho(DOKHO) == KHO)
	{
		cout << scoreKHO << endl;
	}
	else if (DoKho(DOKHO) == CRAZZY)
	{
		cout << scoreCZ << endl;
	}
	gotoXY(49, 15); setTextColor(12); cout << "Nhan"; setTextColor(WHITE_COLOR); cout << " Enter "; setTextColor(12); cout << "de quay lai Menu";
	while (_getch()!= Enter); // Khi nhấn phím Enter sẽ Tiếp tục trò chơi
}

//Khởi động game
void ChayGame(int & huong, int & xmoi, int & ymoi, int & xbonus, int & ybonus, int & d, int & dau, int & than, int & mauran, char s[], int hard, int DOKHO, int & colorMoi, int & scoreDE, int & scoreTB, int & scoreKHO, int & scoreCZ)
{
	noCursorType();
	Toado dotcuoicu = dichuyen(huong);
	batsukien(huong);
	hienthiran(dotcuoicu, dau, than, mauran);
	xulyvacham(xmoi, ymoi, xbonus, ybonus, d, colorMoi, hard, DOKHO, scoreDE, scoreTB, scoreKHO, scoreCZ);
	HienThiGame(xmoi, ymoi, xbonus, ybonus, d, s, hard, DOKHO, colorMoi, scoreDE, scoreTB, scoreKHO, scoreCZ);
}


