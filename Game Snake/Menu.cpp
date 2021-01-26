#include "MyFuntion.h"
#include "kmin_console.h"
#include "Menu.h"
#include "File.h"

//phần khởi động
void Loading() // trang trí cho Game thêm hấp dẫn
{
	for (int i = 0; i < 101; i++)
	{
		noCursorType();
		gotoXY(53, 15);
		setTextColor(BLUE_COLOR);
		cout << "LOANDING... "; setTextColor(WHITE_COLOR); cout << i << " %";
		if (i <= 4) Sleep(500);
		else if (i <= 42) Sleep(30);
		else if (i <= 47)Sleep(100);
		else if (i <= 95) Sleep(30);
		else if (i <= 100)Sleep(300);
		for (int j = 0; j <= i; j++)
		{
			gotoXY(j + 10, 17);
			setTextColor(DARK_RED_COLOR);
			cout << (char)205;

		}
	}
	Sleep(1500);
	clrscr();
}
void KhungTen() // vẽ khung Nhập tên để trang trí 
{
	setTextColor(random(1, 15));
	//vẽ cột ngang trên
	for (int x = TRAI_TEN; x <= PHAI_TEN; x++)
	{
		gotoXY(x, TREN_TEN);
		cout << (char)205;
	}
	//vẽ cột dọc trái
	for (int y = TREN_TEN; y <= DUOI_TEN; y++)
	{
		gotoXY(TRAI_TEN, y);
		cout << (char)186;
		gotoXY(TRAI_TEN, TREN_TEN);
		cout << (char)201;
	}
	//vẽ cột ngang dưới
	for (int x = TRAI_TEN; x <= PHAI_TEN; x++)
	{
		gotoXY(x, DUOI_TEN);
		cout << (char)205;
		gotoXY(TRAI_TEN, DUOI_TEN);
		cout << (char)200;
	}
	//vẽ cột dọc phải
	for (int y =  TREN_TEN; y <= DUOI_TEN; y++)
	{
		gotoXY(PHAI_TEN, y);
		cout << (char)186;
		gotoXY(PHAI_TEN, TREN_TEN);
		cout << (char)187;
		gotoXY(PHAI_TEN, DUOI_TEN);
		cout << (char)188;
	}
}
void NhapTen(char s[], char z[], char b1[], char b2[], char b3[], char b4[], char b5[], char b6[], char b7[], char b8[], char b9[], char b0[])
{
	// Nhập vào tên người chơi
	noCursorType();
	ifstream FileIn;
	FileIn.open("PlayerName.txt");
	if (FileIn.fail()) // nếu Mở file thất bại => lần đầu chơi
	{
		fflush(stdin);
		do{
			clrscr();
			gotoXY(1, 2);
			setTextColor(RED_COLOR);
			cout << "\\\\        //\\\\        // ||////// ||       ||/////// ||///////|| ||\\\\        //|| ||//////    ///////// ||///////||";
			gotoXY(1, 3);
			cout << " \\\\      //  \\\\      //  ||       ||       ||        ||       || || \\\\      // || ||              ||    ||       ||";
			gotoXY(1, 4);
			cout << "  \\\\    //    \\\\    //   ||////   ||       ||        ||       || ||  \\\\    //  || ||////          ||    ||       ||";
			gotoXY(1, 5);
			cout << "   \\\\  //      \\\\  //    ||       ||       ||        ||       || ||   \\\\  //   || ||              ||    ||       ||";
			gotoXY(1, 6);
			cout << "    \\\\//        \\\\//     ||////// ||////// ||/////// ||///////|| ||    \\\\//    || ||//////        ||    ||///////||";
			gotoXY(37, 9);
			setTextColor(BLUE_COLOR);
			cout << "||////// ||\\    ||     //\\\\     ||  // ||//////";
			gotoXY(37, 10);
			cout << "||       || \\   ||    //  \\\\    || //  ||";
			gotoXY(37, 11);
			cout << "||////|| ||  \\  ||   //||||\\\\   ||\\\\   ||////";
			gotoXY(37, 12);
			cout << "      || ||   \\ ||  //      \\\\  || \\\\  ||";
			gotoXY(37, 13);
			cout << "//////|| ||    \\|| //        \\\\ ||  \\\\ ||//////";
			KhungTen();
			gotoXY(TRAI_TEN+5, TREN_TEN+2);
			setTextColor(CYAN_COLOR);
			cout << "Nhap vao ten (< 16 ky tu): "; setTextColor(WHITE_COLOR); cin.getline(s, 50);
			XoaKhoangTrang(s);
		} while (strlen(s) >= 16 || strlen(s) == 0);
		ofstream Name;
		Name.open("PlayerName.txt");
		Name << s << endl;
		Name.close();
	}
	else // ngược lại sẽ đọc tên từ File và xuất ra màn hình
	{
		FileIn >> s;
		KhungTen();
		gotoXY(50, TREN_TEN +2); setTextColor(CYAN_COLOR);
		for (int i = 0; i < strlen(z); i++)
		{
			cout << z[i]; Sleep(60);
			if (z[i] == '.') Sleep(300);
		}
		setTextColor(WHITE_COLOR);
		for (int i = 0; i < strlen(s); i++)
		{
			cout << s[i]; Sleep(150);
		}
		FileIn.close();
	}
	gotoXY(TRAI_TEN + 9 , TREN_TEN + 4); setTextColor(CYAN_COLOR);
	cout << "Are you ready ?"; setTextColor(CYAN_COLOR); cout << " Press "; setTextColor(WHITE_COLOR); cout << "Enter"; setTextColor(CYAN_COLOR); cout << " to Play";
	while (_getch() != Enter);
}
//Xóa khoảng trắng cho tên vừa nhập vào
void Xoa(char x[], int vitri)
{
	int l = strlen(x);
	for (int i = vitri; i <= l; i++)
		x[i] = x[i + 1];
}
void XoaKhoangTrang(char S[])
{
	int l = strlen(S);
	for (int i = 0; i <= l; i++)
	{
		fflush(stdin);
		if (S[0] == ' ')
			Xoa(S, i);
		if (S[i] == ' ')
		{
			Xoa(S, i);
			i--;
		}
		if (S[l] == ' ')
			Xoa(S, l);
	}
}


//Phần Menu
void MenuStart(char s[], char z[], char b1[], char b2[], char b3[], char b4[], char b5[], char b6[], char b7[], char b8[], char b9[], char b0[])
{
	//Menu khởi động cho game. KHá đẹp nhé
	noCursorType();
	for (int i = 0; i <= strlen(b1); i++)
	{
		gotoXY(1 + i, 2);
		setTextColor(RED_COLOR);
		cout << b1[i]; Sleep(5);
		gotoXY(1 + i, 3);
		cout << b2[i]; Sleep(5);
		gotoXY(1 + i, 4);
		cout << b3[i]; Sleep(5);
		gotoXY(1 + i, 5);
		cout << b4[i]; Sleep(5);
		gotoXY(1 + i, 6);
		cout << b5[i];  Sleep(5);
	}

	for (int i = 0; i <= strlen(b6); i++)
	{
		gotoXY(37 + i, 9);
		setTextColor(BLUE_COLOR);
		cout << b6[i]; Sleep(10);

		gotoXY(37 + i, 10);
		cout << b7[i]; Sleep(10);

		gotoXY(37 + i, 11);
		cout << b8[i]; Sleep(10);

		gotoXY(37 + i, 12);
		cout << b9[i]; Sleep(10);

		gotoXY(37 + i, 13);
		cout << b0[i]; Sleep(10);
	}
	NhapTen(s, z, b1, b2, b3, b4, b5, b6, b7, b8, b9, b0);
}
int ChonMenu(int & ytro, int & key, int & menu)
{
	// Chọn Menu bằng cách bấm mũi tên lên xuống hoặc S hoặc W
	while (1)
	{
		clrscr();
		noCursorType();
		gotoXY(MENU_X, MENU_Y_TREN);
		setTextColor(RED_COLOR);
		cout << "TRO CHOI MOI";

		gotoXY(MENU_X, MENU_Y_TREN + 2);
		setTextColor(BLUE_COLOR);
		cout << "TUY CHON";

		gotoXY(MENU_X, MENU_Y_TREN + 4);
		setTextColor(YELLOW_COLOR);
		cout << "DIEM CAO NHAT";

		gotoXY(MENU_X, MENU_Y_TREN + 6);
		setTextColor(GREEN_COLOR);
		cout << "HUONG DAN";

		gotoXY(MENU_X, MENU_Y_TREN + 8);
		setTextColor(CYAN_COLOR);
		cout << "GIOI THIEU";

		gotoXY(MENU_X, MENU_Y_TREN + 10);
		setTextColor(WHITE_COLOR);
		cout << "THOAT";
		key = inputKey();
		if (key == 'w' || key== 'W' || key == KEY_UP)
		{
			ytro=ytro-2;
			if (ytro <= MENU_Y_TREN - 1) ytro = MENU_Y_DUOI;
		}
		else if (key == 's' || key == 'S' || key == KEY_DOWN)
		{
			ytro = ytro + 2;
			if (ytro >= MENU_Y_DUOI + 1) ytro = MENU_Y_TREN;
		}
		setTextColor(WHITE_COLOR);
		gotoXY(MENU_X - 4, ytro); cout << (char)175 << (char)175; gotoXY(MENU_X + 15, ytro); cout << (char)174<<char(174);
		//trả về các giá trị tương ứng với tên trong Menu
		if (ytro == MENU_Y_TREN && key == Enter)
		{
			menu = 1;
			break;
		}
		else if (ytro == MENU_Y_TREN + 2 && key == Enter)
		{
			menu = 2;
			break;
		}
		else if (ytro == MENU_Y_TREN + 4 && key == Enter)
		{
			menu = 3;
			break;
		}
		else if (ytro == MENU_Y_TREN + 6 && key == Enter)
		{
			menu = 4;
			break;
		}
		else if (ytro == MENU_Y_TREN + 8 && key == Enter)
		{
			menu = 5;
			break;
		}
		else if (ytro == MENU_Y_DUOI && key == Enter)
		{
			menu = 6;
			break;
		}
		Sleep(150);
	}
	return menu;
}

void C4()
{
	//Hàm xuât ra Hướng dẫn cách chơi. đa số đều bỏ qua và đi thằng vào game.
	clrscr();
	KhungHuongDan(); 
	gotoXY(40, 13);
	setTextColor(WHITE_COLOR); cout << "Nhan"; setTextColor(YELLOW_COLOR); cout << "   UP   "; setTextColor(WHITE_COLOR); cout << "hoac"; setTextColor(YELLOW_COLOR); cout << "  W  "; setTextColor(WHITE_COLOR); cout << "de di chuyen Ran di Len";
	gotoXY(40, 14);
	setTextColor(WHITE_COLOR); cout << "Nhan"; setTextColor(YELLOW_COLOR); cout << "  DOWN  "; setTextColor(WHITE_COLOR); cout << "hoac"; setTextColor(YELLOW_COLOR); cout << "  S  "; setTextColor(WHITE_COLOR); cout << "de di chuyen Ran di Xuong";
	gotoXY(40, 15);
	setTextColor(WHITE_COLOR); cout << "Nhan"; setTextColor(YELLOW_COLOR); cout << "  LEFT  "; setTextColor(WHITE_COLOR); cout << "hoac"; setTextColor(YELLOW_COLOR); cout << "  A  "; setTextColor(WHITE_COLOR); cout << "de di chuyen Ran qua Trai";
	gotoXY(40, 16);
	setTextColor(WHITE_COLOR); cout << "Nhan"; setTextColor(YELLOW_COLOR); cout << "  RIGHT "; setTextColor(WHITE_COLOR); cout << "hoac"; setTextColor(YELLOW_COLOR); cout << "  D  "; setTextColor(WHITE_COLOR); cout << "de di chuyen Ran qua Phai";
	gotoXY(40, 17);
	setTextColor(WHITE_COLOR); cout << "Nhan"; setTextColor(YELLOW_COLOR); cout << "  Esc   "; setTextColor(WHITE_COLOR); cout << "hoac"; setTextColor(YELLOW_COLOR); cout << "  P  "; setTextColor(WHITE_COLOR); cout << "de tam dung";
	gotoXY(46, 20);
	cout << "Chuc cac ban choi Game vui ve ^^";

	_getch();
	clrscr();
}
void KhungHuongDan()
{
	//trang trí Khung Hướng dẫn
	gotoXY(22, 3); setTextColor(GREEN_COLOR);
	cout << "0    0  0000000  0    0    0    0000000 0000000     000000 0         0     0   0";
	gotoXY(22, 4);
	cout << "0    0  0     0  0   0 0   0       0    0     0     0    0 0        0 0     0 0";
	gotoXY(22, 5);
	cout << "000000  0     0  0  0   0  0       0    0     0     000000 0       00000     0";
	gotoXY(22, 6);
	cout << "0    0  0     0  0 0     0 0       0    0     0     0      0      0     0    0";
	gotoXY(22, 7);
	cout << "0    0  0000000   0       0        0    0000000     0      00000 0       0   0";
	setTextColor(DARK_GREEN_COLOR);

	//vẽ cột ngang trên
	for (int x = TRAI_HD; x <= PHAI_HD; x++)
	{
		gotoXY(x, TREN_HD);
		cout << (char)205;
	}
	// vẽ cột dọc trái
	for (int y = TREN_HD; y <= DUOI_HD; y++)
	{
		gotoXY(TRAI_HD, y);
		cout << (char)186;
		gotoXY(TRAI_HD, TREN_HD);
		cout << (char)201;
	}
	// vẽ cột ngang dưới
	for (int x = TRAI_HD; x <= PHAI_HD; x++)
	{
		gotoXY(TRAI_HD, DUOI_HD);
		cout << (char)200;
		gotoXY(x, DUOI_HD);
		cout << (char)205;
	}
	// vẽ cột dọc phải
	for (int y = TREN_HD; y <= DUOI_HD; y++)
	{
		gotoXY(PHAI_HD, TREN_HD);
		cout << (char)187;
		gotoXY(PHAI_HD, y);
		cout << (char)186;
		gotoXY(PHAI_HD, DUOI_HD);
		cout << (char)188;
	}
}
void C5()
{
	//Giới thiệu Vũ Hoàng Lâm dựa vào code thầy Bảo và áp dụng các bài đã học trên lớp và viết ra con game này.hehe
	// thanks so much
	clrscr();
	KhungAboutUs();
	gotoXY(45, 14);
	setTextColor(BLUE_COLOR);
	cout << "Ban quyen:"; setTextColor(WHITE_COLOR); cout<<" Vu Hoang Lam";
	gotoXY(51, 16);
	setTextColor(YELLOW_COLOR);
	cout << "Lop:"; setTextColor(WHITE_COLOR); cout<<" CDTH18D";
	gotoXY(48, 18);
	setTextColor(RED_COLOR);
	cout << "Truong:"; setTextColor(WHITE_COLOR); cout<<" CDKT Cao Thang";
	_getch();
	clrscr();
}
void KhungAboutUs()
{
	setTextColor(CYAN_COLOR);
	gotoXY(25, 3);
	cout << "    0      0000000   00000000  0      0  0000000    0      0  00000000";
	gotoXY(25, 4);
	cout << "   0 0     0     0   0      0  0      0     0       0      0  0";
	gotoXY(25, 5);
	cout << "  00000    0000000   0      0  0      0     0       0      0  00000000";
	gotoXY(25, 6);
	cout <<" 0     0   0      0  0      0  0      0     0       0      0         0";
	gotoXY(25, 7);
	cout << "0       0  00000000  00000000  00000000     0       00000000  00000000";


}

//Tùy chọn chức năng
void TuyChon(int & yTuychon, int & yDokho, int & yMauran, int & yNL, int & key, int & hard, int & DOKHO, int & dau, int & than, int & mauran, int & chon, char s[], char z[], char b1[], char b2[], char b3[], char b4[], char b5[], char b6[], char b7[], char b8[], char b9[], char b0[], int & scoreDE, int & scoreTB, int & scoreKHO, int & scoreCZ, int & maxDE, int & maxTB, int & maxKHO, int & maxCZ)
{
	//Hàm Tùy chọn các chức năng trong game
	while (1)
	{
		clrscr();
		//KhungTuyChon();
		gotoXY(53, 12);
		setTextColor(RED_COLOR);
		cout << "Chon Do Kho"; // thay đổi độ khó
		gotoXY(53, 14);
		setTextColor(CYAN_COLOR);
		cout << "Doi Mau Ran"; // thay đổi màu rắn
		gotoXY(53, 16);
		setTextColor(YELLOW_COLOR);
		cout << "Nguoi Choi Moi"; // Tạo Người chơi mới (giống kiểu khôi phục cài đặt trong điện thoạt í).
		gotoXY(53, 18);
		setTextColor(GREEN_COLOR);
		cout << "Quay Lai Menu";
		key = inputKey();
		if (key == 'w' || key == 'W' || key == KEY_UP)
		{
			yTuychon = yTuychon - 2;
			if (yTuychon <= TUYCHON_Y_TREN - 1) yTuychon = TUYCHON_Y_DUOI;
		}
		else if (key == 's' || key == 'S' || key == KEY_DOWN)
		{
			yTuychon = yTuychon + 2;
			if (yTuychon >= TUYCHON_Y_DUOI + 1) yTuychon = TUYCHON_Y_TREN;
		}
		setTextColor(WHITE_COLOR);
		gotoXY(TUYCHON_X - 4, yTuychon); cout << (char)175 << (char)175; gotoXY(TUYCHON_X + 16, yTuychon); cout << (char)174 << (char)174;
		//trả về giá trị tương ứng trong phần Tùy chọn
		if (yTuychon == TUYCHON_Y_TREN && key == Enter)
		{
			chon = 1;
			break;
		}
		if (yTuychon == TUYCHON_Y_TREN + 2 && key == Enter)
		{
			chon = 2;
			break;
		}
		if (yTuychon == TUYCHON_Y_TREN + 4 && key == Enter)
		{
			chon = 3;
			break;
		}
		if (yTuychon == TUYCHON_Y_DUOI && key == Enter)
		{
			chon = 4;
			break;
		}
		Sleep(150);
	}
	if (chon == 1) // nếu giá trị trả về là 1 sẽ đi đến Hàm Chọn Độ Khó
	{
		clrscr();
		chondokho(yDokho, yTuychon, yMauran, yNL, key, hard, DOKHO, dau, than, mauran, chon, s, z, b1, b2, b3, b4, b5, b6, b7, b8, b9, b0, scoreDE, scoreTB, scoreKHO, scoreCZ, scoreDE, scoreTB, scoreKHO, scoreCZ);
	}

	else if (chon == 2) //là 2 sẽ đi đến Hàm thay đổi Màu Rắn
	{
		clrscr();
		ChonMauRan(yMauran, yTuychon, yDokho, yNL, key, hard, DOKHO, dau, than, mauran, chon, s, z, b1, b2, b3, b4, b5, b6, b7, b8, b9, b0, maxDE, maxTB, maxKHO, maxCZ, scoreDE, scoreTB, scoreKHO, scoreCZ);
	}
	else if (chon == 3)  // là 3 sẽ đi đến Hàm Tạo Người Chơi mới(NewPlayer)
	{
		NewPlayer(yNL, yTuychon, yDokho, yMauran, key, dau, than, mauran, chon, hard, DOKHO, s, z, b1, b2, b3, b4, b5, b6, b7, b8, b9, b0, scoreDE, scoreTB, scoreKHO, scoreCZ, maxDE, maxTB, maxKHO, maxCZ);
	}
	else if (chon == 4) // là 4 sẽ xóa màn hình và thoát ra ngoài Menu
		clrscr();
}
void KhungTuyChon()
{
	gotoXY(33, 4); setTextColor(DARK_WHITE_COLOR);
	cout << "0000000  000000  0000000 0000000  0000000  00    0  0000000";
	gotoXY(33, 5);
	cout << "0     0  0    0     0       0     0     0  0 0   0  0";
	gotoXY(33, 6);
	cout << "0     0  000000     0       0     0     0  0  0  0  0000000";
	gotoXY(33, 7);
	cout << "0     0  0          0       0     0     0  0   0 0        0";
	gotoXY(33, 8);
	cout << "0000000  0          0    0000000  0000000  0    00  0000000";
}
void NewPlayer(int & yNL, int & yTuychon, int & yDokho, int & yMauran, int & key, int & dau, int & than, int & mauran, int & chon, int & hard, int & DOKHO, char s[], char z[], char b1[], char b2[], char b3[], char b4[], char b5[], char b6[], char b7[], char b8[], char b9[], char b0[], int & scoreDE, int & scoreTB, int & scoreKHO, int & scoreCZ, int & maxDE, int & maxTB, int & maxKHO, int & maxCZ)
{
	//Tạo người chơi mới
	while (1)
	{
		clrscr();
		//KhungNewPlayer();
		gotoXY(NL_X, NL_Y); setTextColor(WHITE_COLOR); cout << "Ban muon tao Nguoi Choi Moi ?";
		gotoXY(NL_YESNO_X, NL_YESNO_TREN); cout << "YES"; gotoXY(NL_YESNO_X, NL_YESNO_TREN + 1); cout << "NO";
		key = inputKey();
		if (key == 'w' || key == 'W' || key == KEY_UP)
		{
			yNL--;
			if (yNL <= NL_YESNO_TREN - 1) yNL = NL_YESNO_TREN + 1;
		}
		else if (key == 's' || key == 'S' || key == KEY_DOWN)
		{
			yNL++;
			if (yNL >= NL_YESNO_TREN + 2) yNL = NL_YESNO_TREN;
		}
		setTextColor(WHITE_COLOR);
		gotoXY(NL_YESNO_X - 4, yNL); cout << (char)175 << (char)175; gotoXY(NL_YESNO_X + 5, yNL); cout << (char)174 << (char)174;
		if (yNL == NL_YESNO_TREN && key == Enter)
		{
			chon = 1;
			break;
		}
		else if (yNL == NL_YESNO_TREN + 1 && key == Enter)
		{
			chon = 2;
			break;
		}
		Sleep(150);
	}
	if (chon == 1)
	{
		while (1)
		{
			clrscr();
			//KhungNewPlayer();
			gotoXY(NL_X-11, NL_Y); setTextColor(WHITE_COLOR); cout << "Tat ca du lieu se bi xoa va lam moi. Ban chac chu ?";
			gotoXY(NL_YESNO_X, NL_YESNO_TREN); cout << "YES"; gotoXY(NL_YESNO_X, NL_YESNO_TREN + 1); cout << "NO";
			key = inputKey();
			if (key == 'w' || key == 'W' || key == KEY_UP)
			{
				yNL--;
				if (yNL <= NL_YESNO_TREN - 1) yNL = NL_YESNO_TREN + 1;
			}
			else if (key == 's' || key == 'S' || key == KEY_DOWN)
			{
				yNL++;
				if (yNL >= NL_YESNO_TREN + 2) yNL = NL_YESNO_TREN;
			}
			setTextColor(WHITE_COLOR);
			gotoXY(NL_YESNO_X - 4, yNL); cout << (char)175 << (char)175; gotoXY(NL_YESNO_X + 5, yNL); cout << (char)174 << (char)174;
			if (yNL == NL_YESNO_TREN && key == Enter)
			{
				chon = 1;
				break;
			}
			else if (yNL == NL_YESNO_TREN + 1 && key == Enter)
			{
				chon = 2;
				break;
			}
			Sleep(150);
		}
			if (chon == 1) // sẽ Xóa toàn bộ dữ liệu và đặt về ban đầu
			{
				clrscr();
				maxDE = 0; maxTB = 0; maxKHO = 0; maxCZ = 0;
				scoreDE = 0; scoreTB = 0; scoreKHO = 0; scoreCZ = 0;
				remove("PlayerName.txt"); // xóa fie Tên người chơi
				remove("Diem DE.txt"); // Xóa file điểm Dễ
				remove("Diem DE cao nhat.txt");
				remove("Diem TB.txt"); //Xóa file điểm Trung Bình
				remove("Diem TB cao nhat.txt");
				remove("Diem KHO.txt"); // Xóa File Điểm Khó
				remove("Diem KHO cao nhat.txt");
				remove("Diem CZ.txt"); // Xóa file điểm crazzy
				remove("Diem CRAZZY cao nhat.txt");
				remove("Dokho.txt"); // Xóa file Độ khó
				remove("Color Ran.txt"); // Xóa file màu rắn
				MenuStart(s, z, b1, b2, b3, b4, b5, b6, b7, b8, b9, b0); // xóa xong sẽ đi tới hàm Menustart(Menu đầu game)
			}
			else if (chon == 2)
			{
				clrscr();
				TuyChon(yTuychon, yDokho, yMauran, yNL, key, hard, DOKHO, dau, than, mauran, chon, s, z, b1, b2, b3, b4, b5, b6, b7, b8, b9, b0, scoreDE, scoreTB, scoreKHO, scoreCZ, maxDE, maxTB, maxKHO, maxCZ);
			}
	}
	else
		TuyChon(yTuychon, yDokho, yMauran, yNL, key, hard, DOKHO, dau, than, mauran, chon, s, z, b1, b2, b3, b4, b5, b6, b7, b8, b9, b0, scoreDE, scoreTB, scoreKHO, scoreCZ, maxDE, maxTB, maxKHO, maxCZ);
}
void KhungNewPlayer()
{
	setTextColor(random(1, 15));
	//vẽ cột ngang trên
	for (int x = TRAI_PL; x <= PHAI_PL; x++)
	{
		gotoXY(x, TREN_PL);
		cout << (char)205;
	}
	//vẽ cột dọc trái
	for (int y = TREN_PL; y <= DUOI_PL; y++)
	{
		gotoXY(TRAI_PL, y);
		cout << (char)186;
		gotoXY(TRAI_PL, TREN_PL);
		cout << (char)201;
	}
	//vẽ cột ngang dưới
	for (int x = TRAI_PL; x <= PHAI_PL; x++)
	{
		gotoXY(x, DUOI_PL);
		cout << (char)205;
		gotoXY(TRAI_PL, DUOI_PL);
		cout << (char)200;
	}
	//vẽ cột dọc phải
	for (int y = TREN_PL; y <= DUOI_PL; y++)
	{
		gotoXY(PHAI_PL, y);
		cout << (char)186;
		gotoXY(PHAI_PL, TREN_PL);
		cout << (char)187;
		gotoXY(PHAI_PL, DUOI_PL);
		cout << (char)188;
	}

}

//Độ khó game
void chondokho(int & yDokho,int yTuychon, int yMauran, int yNL, int & key, int & hard, int DOKHO, int dau, int than, int mauran, int chon, char s[], char z[], char b1[], char b2[], char b3[], char b4[], char b5[], char b6[], char b7[], char b8[], char b9[], char b0[], int maxDE, int maxTB, int maxKHO, int maxCZ, int scoreDE, int scoreTB, int scoreKHO, int scoreCZ)
{
	//tùy chọn độ khó cho game
	while (1)
	{
		clrscr();
		//KhungDokho();
		gotoXY(DOKHO_X, DOKHO_Y_TREN - 2);
		setTextColor(WHITE_COLOR);
		cout << "chon muc do";
		gotoXY(DOKHO_X, DOKHO_Y_TREN);
		setTextColor(BLUE_COLOR);
		cout << "   De";
		gotoXY(DOKHO_X, DOKHO_Y_TREN +2);
		setTextColor(YELLOW_COLOR);
		cout << "Trung Binh";
		gotoXY(DOKHO_X, DOKHO_Y_TREN +4);
		setTextColor(GREEN_COLOR);
		cout << "   kho";
		gotoXY(DOKHO_X, DOKHO_Y_DUOI);
		setTextColor(DARK_RED_COLOR);
		cout << "  Crazy";
		key = inputKey();
		if (key == 'w' || key == 'W' || key == KEY_UP)
		{
			yDokho = yDokho - 2;
			if (yDokho <= DOKHO_Y_TREN -1) yDokho = DOKHO_Y_DUOI;
		}
		else if (key == 's' || key == 'S' || key == KEY_DOWN)
		{
			yDokho = yDokho + 2;
			if (yDokho >= DOKHO_Y_DUOI + 1) yDokho = DOKHO_Y_TREN;
		}
		setTextColor(WHITE_COLOR);
		gotoXY(DOKHO_X - 4, yDokho); cout << (char)175 << (char)175; gotoXY(DOKHO_X + 12, yDokho); cout << (char)174 << (char)174;
		if (yDokho == DOKHO_Y_TREN && key == Enter)
		{
			hard = 1;
			break;
		}
		else if (yDokho == DOKHO_Y_TREN + 2 && key == Enter)
		{
			hard = 2;
			break;
		}
		else if (yDokho == DOKHO_Y_TREN + 4 && key == Enter)
		{
			hard = 3;
			break;
		}
		else if (yDokho == DOKHO_Y_DUOI && key == Enter)
		{
			hard = 4;
			break;
		}
		Sleep(150);
	}
	FileDoKho(hard, DOKHO);
	TuyChon(yTuychon, yDokho, yMauran, yNL, key, hard, DOKHO, dau, than, mauran, chon, s, z, b1, b2, b3, b4, b5, b6, b7, b8, b9, b0, scoreDE, scoreTB, scoreKHO, scoreCZ, maxDE, maxTB, maxKHO, maxCZ);
}
void FileDoKho(int hard, int DOKHO)
{
	//giá trị hard vừa nhập ở Hàm trên sẽ được lưu vào mỗi file riêng tương ứng với giá trị Hard
	if (hard == 1) // hard =1 sẽ là Dễ
	{
		ofstream FileOut;
		FileOut.open("Dokho.txt");
		DOKHO = DE;
		FileOut << DOKHO;
		FileOut.close();
	}
	else if (hard == 2) //hard = 2 sẽ là Trung Bình
	{
		ofstream FileOut;
		FileOut.open("Dokho.txt");
		DOKHO = TB;
		FileOut << DOKHO;
		FileOut.close();
	}
	else if (hard == 3) // hard = 3 sẽ là Khó
	{
		ofstream FileOut;
		FileOut.open("Dokho.txt");
		DOKHO = KHO;
		FileOut << DOKHO;
		FileOut.close();
	}
	else if (hard == 4) // hard =4 sẽ là Crazzy
	{
		ofstream FileOut;
		FileOut.open("Dokho.txt");
		DOKHO = CRAZZY;
		FileOut << DOKHO;
		FileOut.close();
	}
}
int DoKho(int & DOKHO)
{
	//mở và đọc file Độ khó để đưa vào game
	ifstream File;
	File.open("Dokho.txt"); // chưa có dữ liệu => auto là DỄ
	if (File.fail())
		return DE;
	else
		File >> DOKHO;
	File.close();
	return DOKHO;
}
void KhungDokho()
{
	setTextColor(CYAN_COLOR);
	//vẽ cột ngang trên
	for (int x = TRAI_DK; x <= PHAI_DK; x++)
	{
		gotoXY(x, TREN_DK);
		cout << (char)205;
	}
	//vẽ cột dọc trái
	for (int y = TREN_DK; y <= DUOI_DK; y++)
	{
		gotoXY(TRAI_DK, y);
		cout << (char)186;
		gotoXY(TRAI_DK, TREN_DK);
		cout << (char)201;
	}
	//vẽ cột ngang dưới
	for (int x = TRAI_DK; x <= PHAI_DK; x++)
	{
		gotoXY(x, DUOI_DK);
		cout << (char)205;
		gotoXY(TRAI_DK, 23);
		cout << (char)200;
	}
	//vẽ cột dọc phải
	for (int y = TREN_DK; y <= DUOI_DK; y++)
	{
		gotoXY(PHAI_DK, y);
		cout << (char)186;
		gotoXY(PHAI_DK, TREN_DK);
		cout << (char)187;
		gotoXY(PHAI_DK, DUOI_DK);
		cout << (char)188;
	}
}

//Tùy chọn màu rắn
void ChonMauRan(int & yMauran, int yTuychon, int yDokho, int yNL, int & key, int hard, int DOKHO, int dau, int than, int & mauran, int chon, char s[], char z[], char b1[], char b2[], char b3[], char b4[], char b5[], char b6[], char b7[], char b8[], char b9[], char b0[], int maxDE, int maxTB, int maxKHO, int maxCZ, int scoreDE, int scoreTB, int scoreKHO, int scoreCZ)
{
	//tùy chọn màu rắn
	while (1)
	{
		clrscr();
		//KhungMauRan();
		gotoXY(MAURAN_X + 1, MAURAN_Y_TREN - 2); setTextColor(WHITE_COLOR); cout << "Chon Mau Ran";
		gotoXY(MAURAN_X, MAURAN_Y_TREN); setTextColor(RED_COLOR); cout << "Red"; setTextColor(YELLOW_COLOR); cout << "     Yellow";
		gotoXY(MAURAN_X, MAURAN_Y_TREN + 2); setTextColor(WHITE_COLOR); cout << "White"; setTextColor(BLUE_COLOR); cout << "   Blue";
		gotoXY(MAURAN_X, MAURAN_Y_TREN + 4); setTextColor(PINK_COLOR); cout << "Pink"; setTextColor(CYAN_COLOR); cout << "    Cyan";
		gotoXY(MAURAN_X, MAURAN_Y_TREN + 6); setTextColor(GREEN_COLOR); cout << "Green"; setTextColor(DARK_RED_COLOR); cout << "   Red";
		gotoXY(MAURAN_X, MAURAN_Y_TREN + 8); setTextColor(WHITE_COLOR); cout << "White" << "     White";
		gotoXY(MAURAN_X, MAURAN_Y_DUOI);
		gotoXY(MAURAN_X, MAURAN_Y_DUOI); setTextColor(YELLOW_COLOR); cout << "R"; gotoXY(MAURAN_X + 8, MAURAN_Y_DUOI); setTextColor(YELLOW_COLOR); cout << "R";
		gotoXY(MAURAN_X +1, MAURAN_Y_DUOI); setTextColor(RED_COLOR); cout << "a"; gotoXY(MAURAN_X + 9, MAURAN_Y_DUOI); setTextColor(RED_COLOR); cout << "a";
		gotoXY(MAURAN_X +2, MAURAN_Y_DUOI); setTextColor(CYAN_COLOR); cout << "d"; gotoXY(MAURAN_X + 10, MAURAN_Y_DUOI); setTextColor(CYAN_COLOR); cout << "d";
		gotoXY(MAURAN_X +3, MAURAN_Y_DUOI); setTextColor(GREEN_COLOR); cout << "o"; gotoXY(MAURAN_X + 11, MAURAN_Y_DUOI); setTextColor(GREEN_COLOR); cout << "o";
		gotoXY(MAURAN_X +4, MAURAN_Y_DUOI); setTextColor(WHITE_COLOR); cout << "m"; gotoXY(MAURAN_X + 12, MAURAN_Y_DUOI); setTextColor(WHITE_COLOR); cout << "m";
		key = inputKey();
		if (key == 'w' || key == 'W' || key == KEY_UP)
		{
			yMauran = yMauran - 2;
			if (yMauran <= MAURAN_Y_TREN - 1) yMauran = MAURAN_Y_DUOI;
		}
		else if (key == 's' || key == 'S' || key == KEY_DOWN)
		{
			yMauran = yMauran + 2;
			if (yMauran >= MAURAN_Y_DUOI + 1) yMauran = MAURAN_Y_TREN;
		}
		setTextColor(WHITE_COLOR);
		gotoXY(MAURAN_X - 4, yMauran); cout << (char)175 << (char)175; gotoXY(MAURAN_X + 16, yMauran); cout << (char)174 << (char)174;
		if (yMauran == MAURAN_Y_TREN && key == Enter)
		{
			mauran = 1;
			break;
		}
		else if (yMauran == MAURAN_Y_TREN + 2 && key == Enter)
		{
			mauran = 2;
			break;
		}
		else if (yMauran == MAURAN_Y_TREN + 4 && key == Enter)
		{
			mauran = 3;
			break;
		}
		else if (yMauran == MAURAN_Y_TREN + 6 && key == Enter)
		{
			mauran = 4;
			break;
		}
		else if (yMauran == MAURAN_Y_TREN + 8 && key == Enter)
		{
			mauran = 5;
			break;
		}
		else if (yMauran == MAURAN_Y_DUOI && key == Enter)
		{
			mauran = 6;
			break;
		}
		Sleep(150);
	}
	MauRan(dau, than, mauran);
	TuyChon(yTuychon, yDokho, yMauran, yNL, key, hard, DOKHO, dau, than, mauran, chon, s, z, b1, b2, b3, b4, b5, b6, b7, b8, b9, b0, scoreDE, scoreTB, scoreKHO, scoreCZ, maxDE, maxTB, maxKHO, maxCZ);
}
void KhungMauRan()
{
	setTextColor(random(1, 15));
	//vẽ cột ngang trên
	for (int x = 49; x <= 73; x++)
	{
		setTextColor(random(1, 15));
		gotoXY(x, 5);
		cout << (char)205;
	}
	//vẽ cột dọc trái
	for (int y = 5; y <= 22; y++)
	{
		setTextColor(random(1, 15));
		gotoXY(49, y);
		cout << (char)186;
		gotoXY(49, 5);
		cout << (char)201;
	}
	//vẽ cột ngang dưới
	for (int x = 49; x <= 73; x++)
	{
		setTextColor(random(1, 15));
		gotoXY(x, 22);
		cout << (char)205;
		gotoXY(49, 22);
		cout << (char)200;
	}
	//vẽ cột dọc phải
	for (int y = 5; y <= 22; y++)
	{
		setTextColor(random(1, 15));
		gotoXY(73, y);
		cout << (char)186;
		gotoXY(73, 5);
		cout << (char)187;
		gotoXY(73, 22);
		cout << (char)188;
	}
}
void MauRan(int & dau, int & than, int mauran)
{
	//Tương tự Hàm Độ Khó trên. tương ững với mỗi giá trị mauran sẽ được lưu một giá trị màu khác
	if (mauran == 1)
	{
		ofstream FileOut;
		FileOut.open("Color Ran.txt");
		dau = RED_COLOR; than = YELLOW_COLOR;
		FileOut << dau << endl;
		FileOut << than;
		FileOut.close();
	}
	else if (mauran == 2)
	{
		ofstream FileOut;
		FileOut.open("Color Ran.txt");
		dau = BLUE_COLOR; than = WHITE_COLOR;
		FileOut << dau << endl;
		FileOut << than << endl;
		FileOut.close();
	}
	else if (mauran == 3)
	{
		ofstream FileOut;
		FileOut.open("Color Ran.txt");
		dau = PINK_COLOR; than = CYAN_COLOR;
		FileOut << dau << endl;
		FileOut << than << endl;
		FileOut.close();
	}
	else if (mauran == 4)
	{
		ofstream FileOut;
		FileOut.open("Color Ran.txt");
		dau = GREEN_COLOR; than = DARK_RED_COLOR;
		FileOut << dau << endl;
		FileOut << than << endl;
		FileOut.close();
	}
	else if (mauran == 6)
	{
		ofstream FileOut;
		FileOut.open("Color Ran.txt");
		dau = random(1, 15); than = random(1, 15);
		FileOut << dau << endl;
		FileOut << than << endl;
		FileOut.close();
	}
	else if (mauran== 5)
	{
		ofstream FileOut;
		FileOut.open("Color Ran.txt");
		dau = WHITE_COLOR; than = WHITE_COLOR;
		FileOut << dau << endl;
		FileOut << than;
		FileOut.close();
	}
}








//Màn 1
void man1()
{
	vetuong();
	//Vẽ cây trái trên
	for (int y = TUONG_TREN; y <= TUONG_TREN + ((TUONG_DUOI - TUONG_TREN) / 2); y++)
	{
		gotoXY(CAY_TRAI_TREN, TUONG_TREN);
		cout << (char)219;
		gotoXY(CAY_TRAI_TREN, y);
		cout << (char)177;
	}
	//Vẽ cây trái dưới
	for (int y = TUONG_DUOI; y >= TUONG_DUOI - ((TUONG_DUOI - TUONG_TREN) / 2); y--)
	{
		gotoXY(CAY_TRAI_DUOI, TUONG_DUOI);
		cout << (char)219;
		gotoXY(CAY_TRAI_DUOI, y);
		cout << (char)177;
	}
	//vẽ cây phải trên
	for (int y = TUONG_TREN; y <= TUONG_TREN + ((TUONG_DUOI - TUONG_TREN) / 2); y++)
	{
		gotoXY(CAY_PHAI_TREN, TUONG_TREN);
		cout << (char)219;
		gotoXY(CAY_PHAI_TREN, y);
		cout << (char)177;
	}
	//vẽ cây phải dưới
	for (int y = TUONG_DUOI; y >= TUONG_DUOI - ((TUONG_DUOI - TUONG_TREN) / 2); y--)
	{
		gotoXY(CAY_PHAI_DUOI, TUONG_DUOI);
		cout << (char)219;
		gotoXY(CAY_PHAI_DUOI, y);
		cout << (char)177;
	}
}