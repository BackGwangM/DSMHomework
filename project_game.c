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


int Data[4] = { 0, 2000, 0, 0 };			//강화, 골드, 이펙트 on/off, 자동 강화권 



int main(void)
{

	FILE *fp = fopen("sava.dat", "rb");
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
	printf("★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆\n");
	printf("☆                                            ★\n");
	printf("★              1번 직접 강화                 ☆\n");
	printf("☆         2번 자동 강화 아이템 사용          ★\n");
	printf("★        3번 지금까지의 데이터를 저장        ☆\n");
	printf("☆      4번 현재 자신의 무기 확인, 경매소     ★\n");
	printf("★               5번 게임 종료                ☆\n");
	printf("☆               6번 확률 확인                ★\n");
	printf("★              7번 무기 초기화               ☆\n");
	printf("☆                 0번 설정                   ★\n");
	printf("★   번호를 입력하시고 엔터를 눌러주세요.     ☆\n");
	printf("☆                                            ★\n");
	printf("★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆\n");

	scanf("%s", &menu);

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
	case '5': turn_off(); break;
	case '6': gacha(); break;
	case '7': Data[0] = 0; reinforce_interface(); break;
	case '0': setting(); break;

	default:
		printf("잘못 입력하셨습니다. 다시 입력하시겠습니까? (N을 입력시 게임이 종료 됩니다.)Y/N");
		scanf("%s", &menu);
		if (menu == 'Y')
			reinforce_interface();
		else
			return 0;
		break;
	}

}

int user_reinforce()
{
	char input;
	system("cls");

	printf("★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆\n");
	printf("☆                                                                ★\n");
	printf("★         강화 시스템입니다. 강화에는 150골드가 필요합니다.      ☆\n");
	printf("☆      총 20강까지 있으며 강화 중 특별한 아이템이 나옵니다.      ★\n");
	printf("★               12강 부터는 파괴확률이 생깁니다.                 ☆\n");
	printf("☆   파괴시에는 100골드를 주고 9강부터 다시 강화 할 수 있습니다.  ★\n");
	printf("★              강화를 하시려면 엔터를 눌러주세요!                ☆\n");
	printf("☆                  현재 강화 : %d 골드 : %d                     ★\n", Data[0], Data[1]);
	printf("★                                                                ☆\n");
	printf("☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★\n");

	_getch();

	system("cls");
	printf("강화중.");

	Sleep(750);
	system("cls");
	printf("강화중..");

	Sleep(750);
	system("cls");
	printf("강화중...");

	if (Data[1]<150)
	{
		printf("\n\n\n ※골드가 부족합니다.");
		_getch();
		reinforce_interface();
	}

	else if (Data[0] < 6 )
	{
		reinforce_5();
		Data[1] = Data[1] - 150;
	}

	else if (Data[0] < 12)
	{
		reinforce_11();
		Data[1] = Data[1] - 150;

	}
	else if (Data[0] < 17)
	{
		reinforce_16();
		Data[1] = Data[1] - 150;
	}

	else if (Data[0] < 20)
	{
		reinforce_20();
		Data[1] = Data[1] - 150;
	}



	else if (Data[0] >= 20)
	{
		printf("\n\n ※이미 강화가 완료된 무기입니다. \n 다음 컨텐츠를 기다려 주시기 바랍니다. \t\t\t현재 무기 : %d강\n\n", Data[0]);
		_getch();
		reinforce_interface();
	}
	printf("\n계속 하시려면 엔터를 누르시면 되고 그만 하시려면 1번을 누르고 엔터를 눌러주세요");
	input = _getch();
	if (input == '1')
	{
		reinforce_interface();
	}

	user_reinforce();
}
int auto_reinforce()
{
	int i = 0;
	system("cls");

	printf("★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆\n");
	printf("☆                                                                ★\n");
	printf("★         강화하다가 나온 자동강화권을 사용할 수 있습니다.       ☆\n");
	printf("☆            강화 중 특별한 아이템이 나오지 않습니다.            ★\n");
	printf("★                 12강까지 강화 할 수 있습니다.                  ☆\n");
	printf("☆         자동강화권과 자동강화 횟수당 50골드가 사용됩니다.      ★\n");
	printf("★               강화를 하시려면 엔터를 눌러주세요!               ☆\n");
	printf("☆           현재 강화 단계 : %d       자동강화권 : %d              ★\n", Data[0], Data[3]);
	printf("★                                                                ☆\n");
	printf("☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★\n");

	_getch();

	if (Data[3] != 0)
	{
		Data[3]--;
		i = reinforce();


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

	FILE *fp = fopen("sava.dat", "wb");
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
	int Fates_dice = rand() % (150 + 1);

	system("cls");

	weapon_interface();
	_getch();
	
	get_golds = (120 * Data[0]) + (Fates_dice*Data[0]);
	
		if (Fates_dice<51 && Data[0] !=0)
	{
		printf("\n\n경매장의 상인들이 당신의 무기에 관심이 없습니다.\n\n");
		printf("사리스 || 경매장 관리\n");
		printf("살 사람도 없는 것 같은데 이만 장사 접지 그래?\n");
	}
	else if (Fates_dice<101 && Data[0] !=0)
	{
		printf("\n\n경매장의 상인들이 당신의 무기가 그럭저럭 이라고 말합니다.\n\n");
		printf("윌리 || 상인\n");
		printf("이 무기 그럭저럭인데 당신 작품인가? 나라면 이렇게 안할텐데..\n");
	}
		
		 
	else if (Fates_dice<151 && Data[0] !=0)
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
			printf("\n\n팔면 %d골드가 나옵니다. 파는 중입니다...", get_golds );
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
	printf("%d", Fates_dice);
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
	printf("%d", Fates_dice);
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

}
int reinforce_20()
{

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

int reinforce()
{
	int Fates_dice;
	int attempt = 0;

	printf("\n\n**강화 내용**\n\n");
	if(Data[1]<50)
	{
		printf("골드가 부족합니다."); 
	}
	while (Data[0]<12 && Data[1]>49)
	{
		Data[1] = Data[1] - 50;
		Fates_dice = rand() % (1000 + 1);
		attempt++;
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
		default:
			break;

		}
		printf("\n현재 강화 단계 : %d\n", Data[0]);
	
	}
	Fates_dice = 0;
	return attempt;
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

			Sleep(2000);
			save();
		}

		else
		{
			printf("즐거운 시간 보내세요!\n");
			Sleep(2000);
			reinforce_interface();
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
	system("cls");

	printf("★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆\n");
	printf("☆                                                                ★\n");
	printf("★              유저가 직접 강화하는 시스템 입니다.               ☆\n");
	printf("☆      총 20강까지 있으며 강화 중 특별한 아이템이 나옵니다.      ★\n");
	printf("★               12강 부터는 파괴확률이 생깁니다.                 ☆\n");
	printf("☆   파괴시에는 100골드를 주고 9강부터 다시 강화 할 수 있습니다.  ★\n");
	printf("★            강화를 하시려면 엔터를 눌러주세요!                  ☆\n");
	printf("☆                  현재 강화 : %d 골드 : %d                     ★\n", Data[0], Data[1]);
	printf("★                                                                ☆\n");
	printf("☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★\n");

	_getch();

	if (Data[1]<150)
	{
		printf("\n\n\n ※골드가 부족합니다.");
		_getch();
		reinforce_interface();
	} 
	else if (Data[0] < 6)
	{
		effect_off_reinforce_5();
		Data[1] = Data[1] - 150;
	}

	else if (Data[0] < 12)
	{
		effect_off_reinforce_11();
		Data[1] = Data[1] - 150;

	}
	else if (Data[0] < 17)
	{
		effect_off_reinforce_16();
		Data[1] = Data[1] - 150;
	}

	else if (Data[0] < 20)
	{
		effect_off_reinforce_20();
		Data[1] = Data[1] - 150;
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
	printf("%d", Fates_dice);
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
	printf("%d", Fates_dice);
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
int effect_off_reinforce_16()
{

}
int effect_off_reinforce_20()
{

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
