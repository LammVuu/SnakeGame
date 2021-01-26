#include "kmin_console.h"
#include "MyFuntion.h"
#include "Menu.h"
#include "File.h"


void main()
{
	char TenDE[50]; char TenTB[50]; char TenKHO[50]; char TenCZ[50];
	char Ten[50]; char W[] = "Welcome back. ";
	srand(time(NULL));
	khoitao();
	int huong = PHAI; int hard; int DOKHO;  int MauRan; int Dau; int Than; int chon; int dem = 0; int Menu; int key;
	int ytro = MENU_Y_TREN; int yTuychon = TUYCHON_Y_TREN; int yDokho = DOKHO_Y_TREN; int yMauran = MAURAN_Y_TREN; int yNL = NL_YESNO_TREN;
	int MaxDE = 0, MaxTB = 0, MaxKHO = 0, MaxCZ = 0, scoreDE, scoreTB, scoreKHO, scoreCZ;
	char a1[] = "\\\\        //\\\\        // ||////// ||       ||/////// ||///////|| ||\\\\        //|| ||//////    ///////// ||///////||";
	char a2[] = " \\\\      //  \\\\      //  ||       ||       ||        ||       || || \\\\      // || ||              ||    ||       ||";
	char a3[] = "  \\\\    //    \\\\    //   ||////   ||       ||        ||       || ||  \\\\    //  || ||////          ||    ||       ||";
	char a4[] = "   \\\\  //      \\\\  //    ||       ||       ||        ||       || ||   \\\\  //   || ||              ||    ||       ||";
	char a5[] = "    \\\\//        \\\\//     ||////// ||////// ||/////// ||///////|| ||    \\\\//    || ||//////        ||    ||///////||";

	char a6[] = "||////// ||\\\\    ||     //\\\\     ||  // ||//////";
	char a7[] = "||       || \\\\   ||    //  \\\\    || //  ||      ";
	char a8[] = "||////|| ||  \\\\  ||   //||||\\\\   ||\\\\   ||////  ";
	char a9[] = "      || ||   \\\\ ||  //      \\\\  || \\\\  ||      ";
	char a0[] = "//////|| ||    \\\\|| //        \\\\ ||  \\\\ ||//////";
	int color = random(1, 15);
	int xmoi = random(TUONG_TRAI + 1, TUONG_PHAI - 1);
	int ymoi = random(TUONG_TREN + 1, TUONG_DUOI - 1);
	int xbonus = random(TUONG_TRAI + 1, TUONG_PHAI - 1);
	int ybonus = random(TUONG_TREN + 1, TUONG_DUOI - 1);

	Loading();
	MenuStart(Ten, W, a1, a2, a3, a4, a5, a6, a7, a8, a9, a0);
	ChonMenu(ytro, key, Menu);
	while (Menu != 6)
	{
		switch (Menu)
			{
			case 1:
			{
				clrscr();
				LoaiDiem(hard,DOKHO, scoreDE, scoreTB, scoreKHO, scoreCZ);
				vetuong();
				while (1)
				{
					ChayGame(huong, xmoi, ymoi, xbonus, ybonus, dem, Dau, Than, MauRan, Ten, hard, DOKHO, color, scoreDE, scoreTB, scoreKHO, scoreCZ);
					if (xuly() == true)
					{
						khoitao();
						Diem(hard, DOKHO, scoreDE, scoreTB, scoreKHO, scoreCZ, MaxDE, MaxTB, MaxKHO, MaxCZ);
						break;
					}
					Sleep(DoKho(DOKHO));
				}
				clrscr();
				break;
			}
			case 2:
			{
				TuyChon(yTuychon, yDokho, yMauran, yNL, key, hard, DOKHO, Dau, Than, MauRan, chon, Ten, W, a1, a2, a3, a4, a5, a6, a7, a8, a9, a0, scoreDE, scoreTB, scoreKHO, scoreCZ, MaxDE, MaxTB, MaxKHO, MaxCZ);
				break;
			}
			case 3:
			{
				DiemCaoNhat(Ten, hard, MaxDE, MaxTB, MaxKHO, MaxCZ, scoreDE, scoreTB, scoreKHO, scoreCZ);
				break;
			}
			case 4:
			{
				C4();
				break;
			}
			case 5:
			{
				C5();
				break;
			}

			case 6:
				break;
			}
		ChonMenu(ytro, key, Menu);
	}
}





