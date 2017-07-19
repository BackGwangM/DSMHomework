#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h> 

int start_interface();
int reinforce_interface();
int user_reinforce();
int auto_reinforce();
int save();
int weapon();
int boss();
int get_gold();
int turn_off();
int reinforce();
int gacha();
int setting();
int effect_off_user_reinforce();


int Data[7] = { 0, 2000, 0, 0, 0, 0, 0};			//강화, 골드, 이펙트 on/off, 자동 강화권 , 은행 대출, 은행 저축, 강화 시도 횟수 



int main(void)
{
	FILE *fp = fopen("save.dat", "rb");
	if (fp == NULL) {
		start();
	}
	fread(&Data, sizeof(Data), 1, fp);
	fclose(fp);
	start();
}

int start()
{
	srand((unsigned)time(NULL));

	system("cls");
	printf("┌────────────────────┐\n");
	printf("│  강화 시스템에 오신 것을 환영 합니다.  │\n");
	printf("│  시작하시려면 아무것이나 눌러주세요.   │\n");
	printf("└────────────────────┘\n");

	_getch();


	reinforce_interface();
}

int reinforce_interface()
{
	
	char menu;
	system("cls");
	printf("★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆"); printf("----------------------------현재 당신의 상태----------------------------\n");
	printf("☆                                            ★"); printf("\t강화 상태\t%d\t||\t\t골드\t%d\n", Data[0], Data[1]);
	printf("★              1번 직접 강화                 ☆"); printf("\t자동 강화권\t%d\t||\t\n", Data[3], Data[4]);
	printf("☆         2번 자동 강화 아이템 사용          ★\n"); 
	printf("★        3번 지금까지의 데이터를 저장        ☆"); printf("-------------------------------은행 현황--------------------------------\n");
	printf("☆                4번 경매장                  ★"); printf("\t대출\t%d\t\t||\t\t예금\t%d\n", Data[4], Data[5]);
	printf("★            5번 은행 대출, 저축             ☆\n");
	printf("☆               6번 확률 확인                ★\n");
	printf("★              7번 무기 초기화               ☆\n");
	printf("☆                 9번 설정                   ★\n");
	printf("★               0번 게임 종료                ☆\n");
	printf("★   번호를 입력하시고 엔터를 눌러주세요.     ☆\n");
	printf("☆                                            ★\n");
	printf("★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆\n");

	menu = getch();

	switch (menu)
	{
	case '1':
		if (Data[2] == 0)
			user_reinforce();
		else if (Data[2] == 1)
			effect_off_user_reinforce();
		break;
	case '2': auto_reinforce(); break;

	case '3': save(); break;

	case '4': weapon(); break;
	case '0': turn_off(); break;
	case '6': gacha(); break;
	case '7': Data[0] = 0; reinforce_interface(); break;
	case '9': setting(); break;
	case '5': bank(); break;

	default:
		printf("잘못 입력하셨습니다. 다시 입력하시겠습니까? (N을 입력시 게임이 종료 됩니다.)Y/N");
		scanf("%s", &menu);
		if (menu == 'Y' || 'y')
			start();
		else
			return 0;
		break;
	}

}

int user_reinforce()
{
	char input1;
	char input2;
	int i = Data[6] % 10;
	int j = Data[6] / 10;
	
	if(i != 0)
	{
		Data[5] = Data[5] + Data[5]*(j*0.3);
		Data[6] = 0;
	}
	system("cls");

	printf("★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆\n");
	printf("☆                                                                ★\n");
	printf("★         강화 시스템입니다. 강화에는 150골드가 필요합니다.      ☆\n");
	printf("☆      총 20강까지 있으며 강화 중 특별한 아이템이 나옵니다.      ★\n");
	printf("★               12강 부터는 파괴확률이 생깁니다.                 ☆\n");
	printf("☆   파괴시에는 100골드를 주고 9강부터 다시 강화 할 수 있습니다.  ★\n");
	printf("★              강화를 하시려면 아무거나 누르세요                 ☆\n");
	printf("☆             현재 강화 : %d 골드 : %d 저축 : %d              ★\n", Data[0], Data[1], Data[5]);
	printf("★                                                                ☆\n");
	printf("☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★\n");

	getch();
	
	system("cls");
	printf("강화중.");

	Sleep(750);
	system("cls");
	printf("강화중..");

	Sleep(750);
	system("cls");
	printf("강화중...");

	if (Data[1]<150 && Data[5]<150)
	{
		printf("\n\n\n ※골드가 부족합니다.");
		Sleep(500);
		_getch();
		reinforce_interface();
	}

	else if (Data[0] < 6)
	{
		reinforce_5();
		if(Data[1]>149)
			Data[1] = Data[1] - 150;
		if(Data[5]>149 && Data[1]<150)
			Data[5] = Data[5] - 150;
		Data[6]++;
	}

	else if (Data[0] < 12)
	{
		reinforce_11();
		if(Data[1]>149)
			Data[1] = Data[1] - 150;
		if(Data[5]>149 && Data[1]<150)
			Data[5] = Data[5] - 150;
		Data[6]++;

	}
	else if (Data[0] < 17)
	{
		reinforce_16();
		if(Data[1]>149)
			Data[1] = Data[1] - 150;
		if(Data[5]>149 && Data[1]<150)
			Data[5] = Data[5] - 150;
		Data[6]++;
	}

	else if (Data[0] < 20)
	{
		reinforce_20();
		if(Data[1]>149)
			Data[1] = Data[1] - 150;
		if(Data[5]>149 && Data[1]<150)
			Data[5] = Data[5] - 150;
		Data[6]++;
	}

	else if (Data[0] >= 20)
	{
		printf("\n\n ※이미 강화가 완료된 무기입니다. \n 다음 컨텐츠를 기다려 주시기 바랍니다. \t\t\t현재 무기 : %d강\n\n", Data[0]);
		_getch();
		reinforce_interface();
	}
	printf("\n계속 하시려면 엔터를 누르시면 되고 그만 하시려면 1번을 누르고 엔터를 눌러주세요");
	input2 = _getch();
	if (input2 == '1')
	{
		reinforce_interface();
	}
	else
		user_reinforce();
	
	reinforce_interface();
}
int auto_reinforce()
{
	int i = 0;
	int input = 0;
	system("cls");

	printf("★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆\n");
	printf("☆                                                                ★\n");
	printf("★         강화하다가 나온 자동강화권을 사용할 수 있습니다.       ☆\n");
	printf("☆            강화 중 특별한 아이템이 나오지 않습니다.            ★\n");
	printf("★                 20강까지 강화 할 수 있습니다.                  ☆\n");
	printf("☆         한 번 시도시 자동강화권과 10골드가 사용됩니다.         ★\n");
	printf("★               강화를 하시려면 엔터를 눌러주세요!               ☆\n");
	printf("☆           현재 강화 단계 : %d       자동강화권 : %d              ★\n", Data[0], Data[3]);
	if(Data[4] != 0)
		printf("★             대출의 효과로 인해 확률이 낮아집니다.              ☆\n");
	else
	{
		printf("★                                                                ☆\n");
	}
	printf("☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★\n");

	_getch();
	if (Data[3] != 0)
	{
		Data[3]--;
		printf("\n\n원하시는 강화 수치 : ");
		scanf("%d", &input);
		i = reinforce(input);
		printf("%d", i);

		_getch();
		reinforce_interface();
	}

	else
	{
		printf("\n\n보유하지 않고 계십니다.\n\n");
		_getch();
		reinforce_interface();
	}

}
int save()
{
	system("cls");

	printf("★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆\n");
	printf("☆                                            ★\n");
	printf("★     세이브 데이터를 만들 수 있습니다.      ☆\n");
	printf("☆    게임 종료나 메뉴에서 오실수 있습니다.   ★\n");
	printf("★     게임 실행시 자동으로 불러 옵니다.      ☆\n");
	printf("☆       save.dat파일을 지우지 마세요.        ★\n");
	printf("★                                            ☆\n");
	printf("☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★\n");

	_getch();

	FILE *fp = fopen("save.dat", "wb");
	if (fp == NULL)
		return 0;

	fwrite(&Data, sizeof(Data), 1, fp);
	fclose(fp);


	printf("완료 되었습니다.\n\n");
	_getch();
	reinforce_interface();
}

int weapon_interface()
{
	printf("☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆\n");
	printf("★                                                  ★\n");
	printf("☆               경매장에 오셨습니다.               ☆\n");
	printf("★      지금까지 강화한 무기를 팔 수 있습니다.      ★\n");
	printf("☆    판 뒤에 바로 다른 무기를 강화할 수 있습니다.  ☆\n");
	printf("★                                                  ★\n");
	printf("☆            파시려면 1번을 눌러주세요!            ☆\n");
	printf("★                                                  ★\n");
	printf("☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆\n");
}

int weapon()
{

	char input;
	int get_golds;
	int Fates_dice = rand() % (400 + 1);

	system("cls");

	weapon_interface();

	_getch();

	get_golds = (140 * Data[0]) + (Fates_dice*Data[0]);

	if (Fates_dice<100 && Data[0] != 0)
	{
		printf("\n\n경매장의 상인들이 당신의 무기에 관심이 없습니다.\n\n");
		printf("사리스 || 경매장 관리\n");
		printf("살 사람도 없는 것 같은데 이만 장사 접지 그래?\n");
	}
	else if (Fates_dice<350 && Data[0] != 0)
	{
		printf("\n\n경매장의 상인들이 당신의 무기가 그럭저럭 이라고 말합니다.\n\n");
		printf("윌리 || 상인\n");
		printf("이 무기 그럭저럭인데 당신 작품인가? 나라면 이렇게 안할텐데..\n");
	}


	else if (Fates_dice<401 && Data[0] != 0)
	{
		printf("\n\n경매장의 상인들 모두가 당신의 무기를 사고 싶어 합니다.\n\n");
		printf("오필리아 || 확률 강화의 명인\n");
		printf("당신 뭐죠...? 이렇게 강화에 재능이 있다니... 다음 무기, 기대할게요 〉〈\n");
	}

	if (Data[0] == 0)
	{
		printf("\n\n팔면 %d골드가 나옵니다. 파는 중입니다.", get_golds);
		Sleep(1000);
		system("cls");
		weapon_interface();
		printf("\n\n팔면 %d골드가 나옵니다. 파는 중입니다..", get_golds);
		Sleep(1000);
		system("cls");
		weapon_interface();
		printf("\n\n팔면 %d골드가 나옵니다. 파는 중입니다...", get_golds);
		Sleep(1000);
		Data[0] = 0;
		Data[1] = Data[1] + get_golds;
		reinforce_interface();
	}
	else
	{
		Sleep(3000);
		printf("\n팔면 %d골드가 나옵니다. 파는 중입니다.", get_golds);
		Sleep(1000);
		system("cls");
		weapon_interface();
		printf("\n팔면 %d골드가 나옵니다. 파는 중입니다..", get_golds);
		Sleep(1000);
		system("cls");
		weapon_interface();
		printf("\n팔면 %d골드가 나옵니다. 파는 중입니다...", get_golds);
		Sleep(1000);
		Data[0] = 0;
		Data[1] = Data[1] + get_golds;
	}
	reinforce_interface();
}
int turn_off()
{
	return 0;
}

int reinforce_5()
{
	int Fates_dice = rand() % (1000 + 1);
	switch (Data[0])
	{
	case 0:
		if (Fates_dice < 950)
		{
			Data[0]++;
			if (Fates_dice < 300)
				get_auto_Enchant();
			else
				reinforce_success();
		}
		else
			reinforce_fail();
		break;
	case 1:
		if (Fates_dice < 900)
		{
			Data[0]++;
			if (Fates_dice < 201)
				get_auto_Enchant();
			else
				reinforce_success();
		}
		else
			reinforce_fail();
		break;
	case 2:
		if (Fates_dice < 850)
		{
			Data[0]++;
			if (Fates_dice < 201)
				get_auto_Enchant();
			else
				reinforce_success();
		}
		else
			reinforce_fail();
		break;
	case 3:
		if (Fates_dice < 800)
		{
			Data[0]++;
			if (Fates_dice < 201)
				get_auto_Enchant();
			else
				reinforce_success();
		}
		else
			reinforce_fail();
		break;
	case 4:
		if (Fates_dice < 700)
		{
			Data[0]++;
			if (Fates_dice < 201)
				get_auto_Enchant();
			else
				reinforce_success();
		}
		else
			reinforce_fail();
		break;
	case 5:
		if (Fates_dice < 650)
		{
			Data[0]++;
			if (Fates_dice < 201)
				get_auto_Enchant();
			else
				reinforce_success();
		}
		else
			reinforce_fail();
		break;
	default:
		break;
	}


}
int reinforce_11()
{
	int Fates_dice = rand() % (1000 + 1);
	switch (Data[0])
	{
	case 6:
		if (Fates_dice < 550)
		{
			Data[0]++;
			if (Fates_dice < 201)
				get_auto_Enchant();
			else
				reinforce_success();
		}
		else
		{
			Data[0]--;
			reinforce_fail();
		}
		break;
	case 7:
		if (Fates_dice < 500)
		{
			Data[0]++;
			if (Fates_dice < 201)
				get_auto_Enchant();
			else
				reinforce_success();
		}
		else
		{
			Data[0]--;
			reinforce_fail();
		}
		break;
	case 8:
		if (Fates_dice < 450)
		{
			Data[0]++;
			if (Fates_dice < 201)
				get_auto_Enchant();
			else
				reinforce_success();
		}
		else
		{
			Data[0]--;
			reinforce_fail();
		}
		break;
	case 9:
		if (Fates_dice < 425)
		{
			Data[0]++;
			if (Fates_dice < 201)
				get_auto_Enchant();
			else
				reinforce_success();
		}
		else
		{
			Data[0]--;
			reinforce_fail();
		}
		break;
	case 10:
		if (Fates_dice < 400)
		{
			Data[0]++;
			if (Fates_dice < 201)
				get_auto_Enchant();
			else
				reinforce_success();
		}
		else
		{
			Data[0]--;
			reinforce_fail();
		}
	case 11:
		if (Fates_dice < 350)
		{
			Data[0]++;
			if (Fates_dice < 201)
				get_auto_Enchant();
			else
				reinforce_success();
		}
		else
		{
			Data[0]--;
			reinforce_fail();
		}

		break;
	default:
		break;
	}

}
int reinforce_16()
{
	int Fates_dice = rand() % (1000 + 1);
	switch (Data[0])
	{
	case 12:
		if (Fates_dice < 351)
		{
			Data[0]++;
			if (Fates_dice < 100)
				get_auto_Enchant();
			else
				reinforce_success();
		}
		else if (Fates_dice < 401)
		{
			effect_off_reinforce_broken();
		}
		else
		{
			Data[0]--;
			reinforce_fail();
		}
		break;
	case 13:
		if (Fates_dice < 351)
		{
			Data[0]++;
			if (Fates_dice < 100)
				get_auto_Enchant();
			else
				reinforce_success();
		}
		else if (Fates_dice < 411)
		{
			effect_off_reinforce_broken();
		}
		else
		{
			Data[0]--;
			reinforce_fail();
		}
		break;
	case 14:
		if (Fates_dice < 351)
		{
			Data[0]++;
			if (Fates_dice < 100)
				get_auto_Enchant();
			else
				reinforce_success();
		}
		else if (Fates_dice < 421)
		{
			effect_off_reinforce_broken();
		}
		else
		{
			Data[0]--;
			reinforce_fail();
		}
		break;
	case 15:
		if (Fates_dice < 351)
		{
			Data[0]++;
			if (Fates_dice < 100)
				get_auto_Enchant();
			else
				reinforce_success();
		}
		else if (Fates_dice < 431)
		{
			effect_off_reinforce_broken();
		}
		else
		{
			Data[0]--;
			reinforce_fail();
		}
		break;
	case 16:
		if (Fates_dice < 351)
		{
			Data[0]++;
			if (Fates_dice < 100)
				get_auto_Enchant();
			else
				reinforce_success();
		}
		else if (Fates_dice < 441)
		{
			effect_off_reinforce_broken();
		}
		else
		{
			Data[0]--;
			reinforce_fail();
		}
		break;
	case 17:
		if (Fates_dice < 351)
		{
			Data[0]++;
			if (Fates_dice < 100)
				get_auto_Enchant();
			else
				effect_off_reinforce_success();
		}
		else if (Fates_dice < 451)
		{
			effect_off_reinforce_broken();
		}
		else
		{
			Data[0]--;
			effect_off_reinforce_fail();
		}
		break;
	default:
		break;
	}
}

int reinforce_20()
{
	int Fates_dice = rand() % (1000 + 1);
	switch (Data[0])
	{
	case 18:
		if (Fates_dice < 301)
		{
			Data[0]++;
			if (Fates_dice < 100)
				get_auto_Enchant();
			else
				reinforce_success();
		}
		else if (Fates_dice < 401)
		{
			effect_off_reinforce_broken();
		}
		else
		{
			Data[0]--;
			reinforce_fail();
		}
		break;
	case 19:
		if (Fates_dice < 301)
		{
			Data[0]++;
			if (Fates_dice < 100)
				get_auto_Enchant();
			else
				reinforce_success();
		}
		else if (Fates_dice < 401)
		{
			effect_off_reinforce_broken();
		}
		else
		{
			Data[0]--;
			reinforce_fail();
		}
		break;
	default:
		break;
	}
}
int reinforce_success()
{
	system("cls");
	printf("★☆★☆★☆★☆★☆★☆★☆\n");
	printf("☆                        ★\n");
	printf("★       강화 성공!       ☆\n");
	printf("☆     현재 강화 : %d      ★\n", Data[0]);
	printf("★☆★☆★☆★☆★☆★☆★☆\n");

	Sleep(300);
	system("cls");
	printf("☆★☆★☆★☆★☆★☆★☆★\n");
	printf("★                        ☆\n");
	printf("☆       강화 성공!       ★\n");
	printf("★     현재 강화 : %d      ☆\n", Data[0]);
	printf("☆★☆★☆★☆★☆★☆★☆★\n");

	Sleep(300);
	system("cls");
	printf("★☆★☆★☆★☆★☆★☆★☆\n");
	printf("☆                        ★\n");
	printf("★       강화 성공!       ☆\n");
	printf("☆     현재 강화 : %d      ★\n", Data[0]);
	printf("★☆★☆★☆★☆★☆★☆★☆\n");
}

int reinforce_fail()
{
	system("cls");

	printf("┌────────────┐\n");
	printf("│                        │\n");
	printf("│       강화 실패...     │\n");
	printf("│     현재 강화 : %d      │\n", Data[0]);
	printf("└────────────┘\n");
	Sleep(1000);

}

int reinforce(int re)
{
	int Fates_dice;
	int attempt = 0;

	printf("\n\n**강화 내용**\n\n");
	
	if(Data[4] == 0)
	{
		while (Data[0]<re && Data[1]>9)
	{
		Fates_dice = rand() % (1000 + 1);
		attempt++;
		Data[1] = Data[1]-10;
		switch (Data[0])
		{
		case 0:
			if (Fates_dice < 950)
				Data[0]++;
			break;

		case 1:
			if (Fates_dice < 900)
				Data[0]++;
			break;

		case 2:
			if (Fates_dice < 850)
				Data[0]++;
			break;

		case 3:
			if (Fates_dice < 800)
				Data[0]++;
			break;

		case 4:
			if (Fates_dice < 700)
				Data[0]++;
			break;

		case 5:
			if (Fates_dice < 650)
				Data[0]++;
			break;

		case 6:
			if (Fates_dice < 550)
				Data[0]++;
			else
				Data[0]--;
			break;

		case 7:
			if (Fates_dice < 500)
				Data[0]++;
			else
				Data[0]--;
			break;

		case 8:
			if (Fates_dice < 450)
				Data[0]++;
			else
				Data[0]--;
			break;
		case 9:
			if (Fates_dice < 425)
				Data[0]++;
			else
				Data[0]--;
			break;
		case 10:
			if (Fates_dice < 400)
				Data[0]++;
			else
				Data[0]--;
			break;
		case 11:
			if (Fates_dice < 350)
				Data[0]++;
			else
				Data[0]--;
			break;
		case 12:
		if (Fates_dice < 351)
			Data[0]++;
		else if (Fates_dice < 401)
		{
			effect_off_reinforce_broken();
			break;
		}
			
		else
			Data[0]--;
		break;
	case 13:
		if (Fates_dice < 351)
			Data[0]++;
		else if (Fates_dice < 411)	
		{
			effect_off_reinforce_broken();
			break;
		}
		else
			Data[0]--;
		break;
	case 14:
		if (Fates_dice < 351)
			Data[0]++;
		else if (Fates_dice < 421)
		{
			effect_off_reinforce_broken();
			break;
		}
		else
			Data[0]--;
		break;
	case 15:
		if (Fates_dice < 351)
			Data[0]++;
		else if (Fates_dice < 431)
		{
			effect_off_reinforce_broken();
			break;
		}
		else
		{
			Data[0]--;
		}
		break;
	case 16:
		if (Fates_dice < 351)
		{
			Data[0]++;
		}
		else if (Fates_dice < 441)
		{
			effect_off_reinforce_broken();
			break;
		}
		else
			Data[0]--;
		break;
	case 17:
		if (Fates_dice < 351)
		{
			Data[0]++;
		}
		else if (Fates_dice < 451)
		{
			effect_off_reinforce_broken();
			break;
		}
		else
		{
			Data[0]--;
		}
		break;
	case 18:
		if (Fates_dice < 301)
		{
			Data[0]++;
		}
		else if (Fates_dice < 401)
		{
			effect_off_reinforce_broken();
			break;
		}
		else
		{
			Data[0]--;
		}
		break;
	case 19:
		if (Fates_dice < 301)
		{
			Data[0]++;
		}
		else if (Fates_dice < 401)
		{
			effect_off_reinforce_broken();
			break;
		}
		else
		{
			Data[0]--;
		}
		break;
		default:
			break;
		}
		printf("\n현재 강화 단계 : %d\n", Data[0]);

	}
	Fates_dice = 0;
	return attempt;
	}
	
	else
	{
		while (Data[0]<re)
	{
		Fates_dice = rand() % (1000 + 1);
		attempt++;
		switch (Data[0])
		{
		case 0:
			if (Fates_dice < 850)
				Data[0]++;
			break;

		case 1:
			if (Fates_dice < 800)
				Data[0]++;
			break;

		case 2:
			if (Fates_dice < 750)
				Data[0]++;
			break;

		case 3:
			if (Fates_dice < 700)
				Data[0]++;
			break;

		case 4:
			if (Fates_dice < 600)
				Data[0]++;
			break;

		case 5:
			if (Fates_dice < 550)
				Data[0]++;
			break;

		case 6:
			if (Fates_dice < 450)
				Data[0]++;
			else
				Data[0]--;
			break;

		case 7:
			if (Fates_dice < 400)
				Data[0]++;
			else
				Data[0]--;
			break;

		case 8:
			if (Fates_dice < 350)
				Data[0]++;
			else
				Data[0]--;
			break;
		case 9:
			if (Fates_dice < 325)
				Data[0]++;
			else
				Data[0]--;
			break;
		case 10:
			if (Fates_dice < 300)
				Data[0]++;
			else
				Data[0]--;
			break;
		case 11:
			if (Fates_dice < 250)
				Data[0]++;
			else
				Data[0]--;
			break;
		case 12:
		if (Fates_dice < 301)
		{
			Data[0]++;
		}
		else if (Fates_dice < 351)
		{
			effect_off_reinforce_broken();
		}
		else
		{
			Data[0]--;
		}
		break;
	case 13:
		if (Fates_dice < 301)
		{
			Data[0]++;
		}
		else if (Fates_dice < 361)
		{
			effect_off_reinforce_broken();
			break;
		}
		else
		{
			Data[0]--;
		}
		break;
	case 14:
		if (Fates_dice < 301)
		{
			Data[0]++;
		}
		else if (Fates_dice < 371)
		{
			effect_off_reinforce_broken();
		}
		else
		{
			Data[0]--;
		}
		break;
	case 15:
		if (Fates_dice < 301)
		{
			Data[0]++;
		}
		else if (Fates_dice < 381)
		{
			effect_off_reinforce_broken();
		}
		else
		{
			Data[0]--;
		}
		break;
	case 16:
		if (Fates_dice < 301)
		{
			Data[0]++;
		}
		else if (Fates_dice < 391)
		{
			effect_off_reinforce_broken();
		}
		else
		{
			Data[0]--;
		}
		break;
	case 17:
		if (Fates_dice < 301)
		{
			Data[0]++;
		}
		else if (Fates_dice < 401)
		{
			effect_off_reinforce_broken();
		}
		else
		{
			Data[0]--;
		}
		case 18:
		if (Fates_dice < 251)
		{
			Data[0]++;
		}
		else if (Fates_dice < 351)
		{
			effect_off_reinforce_broken();
		}
		else
		{
			Data[0]--;
		}
		break;
	case 19:
		if (Fates_dice < 251)
		{
			Data[0]++;
		}
		else if (Fates_dice < 351)
		{
			effect_off_reinforce_broken();
		}
		else
		{
			Data[0]--;
		}
		break;
		default:
			break;

		}
		printf("\n현재 강화 단계 : %d\n", Data[0]);

	}
	Fates_dice = 0;
	return attempt;
	}
}

int gacha()
{
	printf("0-1강 : 95퍼센트 		자동인챈트권 : 30퍼센트\n");
	printf("1-2강 : 90퍼센트  		자동인챈트권 : 30퍼센트\n");
	printf("2-3강 : 85퍼센트  		자동인챈트권 : 31퍼센트\n");
	printf("3-4강 : 80퍼센트  		자동인챈트권 : 32퍼센트\n");
	printf("4-5강 : 70퍼센트  		자동인챈트권 : 32퍼센트\n");
	printf("5-6강 : 65퍼센트  		자동인챈트권 : 32퍼센트\n");
	printf("6-7강 : 55퍼센트  		자동인챈트권 : 25퍼센트\n");
	printf("7-8강 : 50퍼센트  		자동인챈트권 : 25퍼센트\n");
	printf("8-9강 : 45퍼센트  		자동인챈트권 : 25퍼센트\n");
	printf("9-10강 : 42.5퍼센트  	자동인챈트권 : 20퍼센트\n");
	printf("10-11강 : 40퍼센트 		자동인챈트권 : 20퍼센트\n");
	printf("11-12강 : 35퍼센트 		자동인챈트권 : 20퍼센트\n");
	_getch();

	reinforce_interface();
}
int setting()
{
	char input, input1;
	printf("┌──────설정──────┐\n");
	printf("│   1. 강화 이펙트 on/off    │\n");
	printf("│         2. 초기화          │\n");
	printf("│ 3. 세이브 데이터 불러오기  │\n");
	printf("│      번호를 눌러주세요     │\n");
	printf("└──────────────┘\n");

	input = _getch();
	switch (input)
	{
	case '1':
		if (Data[2] == 0)
		{
			printf("\n 강화 이펙트가 꺼졌습니다.");
			Data[2] = 1;
		}
		else
		{
			printf("\n강화 이펙트가 켜졌습니다.");
			Data[2] = 0;

		}
		break;

	case '2':
		printf("┌─────초기화──────┐\n");
		printf("│ 정말 초기화 하시겠습니까?  │\n");
		printf("│   1번을 누르시면 됩니다.   │\n");
		printf("└──────────────┘\n");

		input1 = _getch();

		if (input1 == '1')
		{
			printf("\n초기화 되었습니다. 초기화 된 데이터를 저장 합니다.");
			Data[0] = 0;
			Data[1] = 2000;
			Data[2] = 0;
			Data[3] = 0;
			Data[4] = 0;
			Data[5] = 0;
			Data[6] = 0;
			

			Sleep(2000);
			save();
		}

		else
		{
			printf("즐거운 시간 보내세요!\n");
			Sleep(2000);
			reinforce_interface();
		}
		case '3' :
		{
			printf("\n\n3초뒤 세이브 데이터를 불러옵니다.\n");
			Sleep(1000);
			printf("\n2초뒤 세이브 데이터를 불러옵니다.\n");
			Sleep(1000);
			printf("\n1초뒤 세이브 데이터를 불러옵니다.\n");
			Sleep(1000);
			FILE *fp = fopen("save.dat", "rb");
			if (fp == NULL) {
			printf("완료 되었습니다.");
			getch();
			start();
			}
			fread(&Data, sizeof(Data), 1, fp);
			fclose(fp);
			printf("완료 되었습니다.");
			getch();
			start();
		} 
	default:
		reinforce_interface();
		break;
	}
	_getch();
	reinforce_interface();
}

int effect_off_user_reinforce()
{
	char input;
	int i = Data[6] % 10;
	int j = Data[6] / 10;
	
	if(i != 0)
	{
		Data[5] = Data[5] + Data[5]*(j*0.3);
		Data[6] = 0;
	}
	system("cls");

	printf("★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆\n");
	printf("☆                                                                ★\n");
	printf("★              유저가 직접 강화하는 시스템 입니다.               ☆\n");
	printf("☆      총 20강까지 있으며 강화 중 특별한 아이템이 나옵니다.      ★\n");
	printf("★               12강 부터는 파괴확률이 생깁니다.                 ☆\n");
	printf("☆   파괴시에는 100골드를 주고 9강부터 다시 강화 할 수 있습니다.  ★\n");
	printf("★            강화를 하시려면 엔터를 눌러주세요!                  ☆\n");
	printf("☆             현재 강화 : %d 골드 : %d 저축 : %d                 ★\n", Data[0], Data[1], Data[5]);
	printf("★                                                                ☆\n");
	printf("☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★\n");

	_getch();

	if (Data[1]<150 && Data[5]<150)
	{
		printf("\n\n\n ※골드가 부족합니다.");
		_getch();
		reinforce_interface();
	}
	else if (Data[0] < 6)
	{
		effect_off_reinforce_5();
		if(Data[1]>149)
			Data[1] = Data[1] - 150;
		if(Data[5]>149 && Data[1]<150)
			Data[5] = Data[5] - 150;
		Data[6]++;
	}

	else if (Data[0] < 12)
	{
		effect_off_reinforce_11();
		if(Data[1]>149)
			Data[1] = Data[1] - 150;
		if(Data[5]>149 && Data[1]<150)
			Data[5] = Data[5] - 150;
		Data[6]++;

	}
	else if (Data[0] < 17)
	{
		effect_off_reinforce_16();
		if(Data[1]>149)
			Data[1] = Data[1] - 150;
		if(Data[5]>149 && Data[1]<150)
			Data[5] = Data[5] - 150;
		Data[6]++;
	}

	else if (Data[0] < 20)
	{
		effect_off_reinforce_20();
		if(Data[1]>149)
			Data[1] = Data[1] - 150;
		if(Data[5]>149 && Data[1]<150)
			Data[5] = Data[5] - 150;
		Data[6]++;
	}

	else if (Data[0] >= 20)
	{
		printf("\n\n ※이미 강화가 완료된 무기입니다. \n 다음 컨텐츠를 기다려 주시기 바랍니다. \t\t\t현재 무기 : %d강\n\n", Data[0]);
		_getch();
		reinforce_interface();
	}

	else if (Data[1]<149) {
		printf("\n\n\n ※골드가 부족합니다.");
		_getch();
		reinforce_interface();
	}
	printf("\n계속 하시려면 엔터를 누르시면 되고 그만 하시려면 1번을 누르고 엔터를 눌러주세요");
	input = _getch();
	if (input == '1')
	{
		reinforce_interface();
	}

	effect_off_user_reinforce();
}

int effect_off_reinforce_5()
{
	int Fates_dice = rand() % (1000 + 1);
	switch (Data[0])
	{
	case 0:
		if (Fates_dice < 950)
		{
			Data[0]++;
			if (Fates_dice < 201)
				get_auto_Enchant();
			else
				effect_off_reinforce_success();
		}
		else
			effect_off_reinforce_fail();
		break;
	case 1:
		if (Fates_dice < 900)
		{
			Data[0]++;
			if (Fates_dice < 201)
				get_auto_Enchant();
			else
				effect_off_reinforce_success();
		}
		else
			effect_off_reinforce_fail();
		break;
	case 2:
		if (Fates_dice < 850)
		{
			Data[0]++;
			if (Fates_dice < 201)
				get_auto_Enchant();
			else
				effect_off_reinforce_success();
		}
		else
			effect_off_reinforce_fail();
		break;
	case 3:
		if (Fates_dice < 800)
		{
			Data[0]++;
			if (Fates_dice < 201)
				get_auto_Enchant();
			else
				effect_off_reinforce_success();
		}
		else
			effect_off_reinforce_fail();
		break;
	case 4:
		if (Fates_dice < 700)
		{
			Data[0]++;
			if (Fates_dice < 201)
				get_auto_Enchant();
			else
				effect_off_reinforce_success();
		}
		else
			effect_off_reinforce_fail();
		break;
	case 5:
		if (Fates_dice < 650)
		{
			Data[0]++;
			if (Fates_dice < 201)
				get_auto_Enchant();
			else
				effect_off_reinforce_success();
		}
		else
			effect_off_reinforce_fail();
		break;
	default:
		break;
	}


}
int effect_off_reinforce_11()
{
	int Fates_dice = rand() % (1000 + 1);
	switch (Data[0])
	{
	case 6:
		if (Fates_dice < 550)
		{
			Data[0]++;
			if (Fates_dice < 201)
				get_auto_Enchant();
			else
				effect_off_reinforce_success();
		}
		else
		{
			Data[0]--;
			effect_off_reinforce_fail();
		}
		break;
	case 7:
		if (Fates_dice < 500)
		{
			Data[0]++;
			if (Fates_dice < 201)
				get_auto_Enchant();
			else
				effect_off_reinforce_success();
		}
		else
		{
			Data[0]--;
			effect_off_reinforce_fail();
		}
		break;
	case 8:
		if (Fates_dice < 450)
		{
			Data[0]++;
			if (Fates_dice < 201)
				get_auto_Enchant();
			else
				effect_off_reinforce_success();
		}
		else
		{
			Data[0]--;
			effect_off_reinforce_fail();
		}
		break;
	case 9:
		if (Fates_dice < 425)
		{
			Data[0]++;
			if (Fates_dice < 201)
				get_auto_Enchant();
			else
				effect_off_reinforce_success();
		}
		else
		{
			Data[0]--;
			effect_off_reinforce_fail();
		}
		break;
	case 10:
		if (Fates_dice < 400)
		{
			Data[0]++;
			if (Fates_dice < 201)
				get_auto_Enchant();
			else
				effect_off_reinforce_success();
		}
		else
		{
			Data[0]--;
			effect_off_reinforce_fail();
		}
		break;
	case 11:
		if (Fates_dice < 350)
		{
			Data[0]++;
			if (Fates_dice < 201)
				get_auto_Enchant();
			else
				effect_off_reinforce_success();
		}
		else
		{
			Data[0]--;
			effect_off_reinforce_fail();
		}
		break;
	default:
		break;
	}
}
int bank()
{
	system("cls");
	int input = 0;
	
	
	printf("★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆\n");
	printf("☆                                                                ★");  printf("\t\t대출한 금액 : %d 골드 : %d  저축 금액: %d\n", Data[4], Data[1], Data[5]);
	printf("★                      은행에 오셨습니다.                        ☆\n");
	printf("☆                  대출 및 저축이 가능합니다.                    ★\n");
	printf("★   대출금액 반환시  대출 금액 + 대출금액의 10%c를 주셔야 합니다. ☆\n", '%');
	printf("☆        저축 시에는 강화 횟수 10번당 3%c의 이자가 쌓입니다.      ★\n", '%');
	printf("★             대출은 1번 || 저축은 2번 || 3번대출 상환           ☆\n");
	printf("☆       ※ 빚이 있으면 자동 강화권의 강화 확률이 줄어 듭니다.    ★\n");
	printf("★                                                                ☆\n");
	printf("☆      강화 시 금액이 없을 경우 저축한 금액에서 빠져나갑니다.    ★\n");
	printf("★                                                                ☆\n");	
	printf("☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★\n");
	
	
	
	scanf("%d", &input);
	switch(input)
	{
		case 1 : borrow(); break;
		case 2 : saving(); break;
		case 3 : return_borrow(); break; 
		default : printf("\n\n잘못 입력하셨습니다."); Sleep(750); reinforce_interface(); break; 
	}
	
}

int borrow()
{
	int borrow_money = 0;
	int input;
	printf("\n\n\n 대출 창구입니다. 원하시는 금액을 입력후 엔터를 눌러주세요\n");
	printf("         1회 대출 한도 금액은 5,000,000원 입니다.\n\n");
	printf("대출 받을 돈 : ");
	scanf("%d", &borrow_money);
	
	if(borrow_money<=5000000)
	{
		printf("대출 받으실 돈은 %d원 입니다. 정말 대출 하시겠습니까?\n", borrow_money);
		printf("     맞으면 1번을 누르시고 엔터를 누르십시오.\n\n");
		printf("대출 확인 번호 (1번을 누르시면 됩니다.) : ");
		scanf("%d", &input);
		
		if(input == 1)
		{
			Data[4] = Data[4] + borrow_money+ borrow_money*0.1;
			Data[1] = Data[1] + borrow_money;
			reinforce_interface();
			
		}
		else
		{
			printf("\n취소하셨습니다.");
			Sleep(750);
			getch();
			bank();
		}
	}
	else
		{
			printf("\n너무 큰 값을 입력 하셨습니다. 초기화면으로 갑니다.");
			Sleep(750);
			getch();
			bank();
		}
}
int saving()
{
	int money = 0; 
	printf("\n\n\n 저축 창구 입니다. 현재 저축 금액은 %d원 입니다.\n", Data[5]);
	printf("      강화횟수가 10의 배수가 되면 3%c의 이자가 쌓입니다.\n", '%');
	printf("           현재 소지금은 %d원 입니다.\n",Data[1]);
	
	printf("저축할 금액 : ");
	scanf("%d", &money);
	
	if(Data[1] < money)
	{
		printf("현재 소지 금액보다 큰 값입니다. 은행 초기화면으로 돌아갑니다.");
		getch();
		bank(); 
	}
	else if(Data[1] > money)
	{
		printf("%d원을 저축합니다.", money);
		Data[1] = Data[1] - money;
		Data[5] = Data[5] + money;
		getch();
		reinforce_interface();
	}
	else
	{
		printf("잘못 입력하셨습니다.");
		getch();
		bank(); 
	}
}
int return_borrow()
{
	int return_money = 0;
	int input;
	printf("\n\n\n 대출 상환 창구입니다. 금액을 입력후 엔터를 눌러주세요\n");
	printf("        1회 대출 한도 금액은 현재 대출 금액은 %d원 입니다.\n\n", Data[4]);
	printf("상환 할 돈 : ");
	scanf("%d", &return_money);
	
	if(return_money<=Data[4])
	{
		printf("               대출 상환 하실 돈은 %d원 입니다.\n", return_money);
		printf("     남아 있는 상환 하실 돈은 %d원 으로 예상 됩니다.\n\n", Data[4]);
		printf("             맞으면 1번을 누르시고 엔터를 누르십시오.\n\n");
		printf("상환 확인 번호 (1번을 누르시면 됩니다.) : ");
		scanf("%d", &input);
		
		if(input == 1)
		{
			Data[4] = Data[4] - return_money;
			Data[1] = Data[1] - return_money;
			reinforce_interface();
		}
		else
		{
			printf("\n취소하셨습니다.");
			Sleep(750);
			getch();
			bank();
		}
	}
	else
		{
			printf("\n너무 큰 값을 입력 하셨습니다. 은행 초기화면으로 갑니다.");
			Sleep(750);
			getch();
			bank();
		}
}
int effect_off_reinforce_16()
{
	int Fates_dice = rand() % (1000 + 1);
	switch (Data[0])
	{
	case 12:
		if (Fates_dice < 351)
		{
			Data[0]++;
			if (Fates_dice < 100)
				get_auto_Enchant();
			else
				effect_off_reinforce_success();
		}
		else if (Fates_dice < 401)
		{
			effect_off_reinforce_broken();
		}
		else
		{
			Data[0]--;
			effect_off_reinforce_fail();
		}
		break;
	case 13:
		if (Fates_dice < 351)
		{
			Data[0]++;
			if (Fates_dice < 100)
				get_auto_Enchant();
			else
				effect_off_reinforce_success();
		}
		else if (Fates_dice < 411)
		{
			effect_off_reinforce_broken();
		}
		else
		{
			Data[0]--;
			effect_off_reinforce_fail();
		}
		break;
	case 14:
		if (Fates_dice < 351)
		{
			Data[0]++;
			if (Fates_dice < 100)
				get_auto_Enchant();
			else
				effect_off_reinforce_success();
		}
		else if (Fates_dice < 421)
		{
			effect_off_reinforce_broken();
		}
		else
		{
			Data[0]--;
			effect_off_reinforce_fail();
		}
		break;
	case 15:
		if (Fates_dice < 351)
		{
			Data[0]++;
			if (Fates_dice < 100)
				get_auto_Enchant();
			else
				effect_off_reinforce_success();
		}
		else if (Fates_dice < 431)
		{
			effect_off_reinforce_broken();
		}
		else
		{
			Data[0]--;
			effect_off_reinforce_fail();
		}
		break;
	case 16:
		if (Fates_dice < 351)
		{
			Data[0]++;
			if (Fates_dice < 100)
				get_auto_Enchant();
			else
				effect_off_reinforce_success();
		}
		else if (Fates_dice < 441)
		{
			effect_off_reinforce_broken();
		}
		else
		{
			Data[0]--;
			effect_off_reinforce_fail();
		}
		break;
	case 17:
		if (Fates_dice < 351)
		{
			Data[0]++;
			if (Fates_dice < 100)
				get_auto_Enchant();
			else
				effect_off_reinforce_success();
		}
		else if (Fates_dice < 451)
		{
			effect_off_reinforce_broken();
		}
		else
		{
			Data[0]--;
			effect_off_reinforce_fail();
		}
		break;
	default:
		break;
	}
}
int effect_off_reinforce_20()
{
	int Fates_dice = rand() % (1000 + 1);
	switch (Data[0])
	{
	case 18:
		if (Fates_dice < 301)
		{
			Data[0]++;
			if (Fates_dice < 100)
				get_auto_Enchant();
			else
				effect_off_reinforce_success();
		}
		else if (Fates_dice < 401)
		{
			effect_off_reinforce_broken();
		}
		else
		{
			Data[0]--;
			effect_off_reinforce_fail();
		}
		break;
	case 19:
		if (Fates_dice < 301)
		{
			Data[0]++;
			if (Fates_dice < 100)
				get_auto_Enchant();
			else
				effect_off_reinforce_success();
		}
		else if (Fates_dice < 401)
		{
			effect_off_reinforce_broken();
		}
		else
		{
			Data[0]--;
			effect_off_reinforce_fail();
		}
		break;
	default:
		break;
	}
}

int effect_off_reinforce_success()
{
	system("cls");
	printf("★☆★☆★☆★☆★☆★☆★☆\n");
	printf("☆                        ★\n");
	printf("★       강화 성공!       ☆\n");
	printf("☆     현재 강화 : %d      ★\n", Data[0]);
	printf("★☆★☆★☆★☆★☆★☆★☆\n");

	_getch();
}

int effect_off_reinforce_fail()
{
	system("cls");

	printf("┌────────────┐\n");
	printf("│                        │\n");
	printf("│       강화 실패...     │\n");
	printf("│     현재 강화 : %d      │\n", Data[0]);
	printf("└────────────┘\n");
	_getch();
	
	
}

int effect_off_reinforce_broken()
{
	system("cls");

	printf("〔  무기가 강한 힘을 이기지 못하고 파괴되었습니다. 100골드로 9강인 무기를 살 수 있습니다. 〕");
	getch();
	if (Data[1]>100)
	{
		Data[0] = 9;
		Data[1] = Data[1] - 100;
		reinforce_interface();
	}
	else
	{
		bank();
		effect_off_reinforce_broken();
	}
}
int get_auto_Enchant()
{
	Data[3]++;

	system("cls");
	printf("★☆★☆★☆★☆★☆★☆★☆\n");
	printf("☆                        ★\n");
	printf("★       강화 성공!       ☆\n");
	printf("☆   자동 인챈트권 획득!  ★\n");
	printf("★☆★☆★☆★☆★☆★☆★☆\n");

	Sleep(300);
	system("cls");
	printf("☆★☆★☆★☆★☆★☆★☆★\n");
	printf("★                        ☆\n");
	printf("☆       강화 성공!       ★\n");
	printf("★   자동 인챈트권 획득!  ☆\n");
	printf("☆★☆★☆★☆★☆★☆★☆★\n");

	Sleep(300);
	system("cls");
	printf("★☆★☆★☆★☆★☆★☆★☆\n");
	printf("☆                        ★\n");
	printf("★       강화 성공!       ☆\n");
	printf("☆   자동 인챈트권 획득!  ★\n");
	printf("★☆★☆★☆★☆★☆★☆★☆\n");

	_getch();
}
