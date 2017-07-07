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

int figure = 0;
int gold = 1000;
int set_EFFECT = 0;

int main(void)
{
	start_interface();
	reinforce_interface();
}

int start_interface()
{

	printf("┌────────────────────┐\n");
	printf("│  강화 시스템에 오신 것을 환영 합니다.  │\n");
	printf("│  시작하시려면 아무것이나 눌러주세요.   │\n");
	printf("└────────────────────┘\n");

	_getch();
}

int reinforce_interface()
{
	char menu;

	system("cls");
	printf("★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆\n");
	printf("☆                                            ★\n");
	printf("★              1번 직접 강화                 ☆\n");
	printf("☆         2번 자동 강화 아이템 사용          ★\n");
	printf("★       3번 지금까지 강화 무기를 저장        ☆\n");
	printf("☆        4번 현재 자신의 무기 확인           ★\n");
	printf("★             5번 보스와의 대련              ☆\n");
	printf("★               6번 골드 획득                ☆\n");
	printf("☆               7번 게임 종료                ★\n");
	printf("★               8번 확률 확인                ☆\n");
	printf("☆              9번 무기 초기화               ★\n");
	printf("★                 0번 설정                   ☆\n");
	printf("☆   번호를 입력하시고 엔터를 눌러주세요.     ★\n");
	printf("☆                                            ★\n");
	printf("★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆\n");

	scanf("%s", &menu);

	switch (menu)
	{
	case '1': 
	if(set_EFFECT == 0)
		user_reinforce();
	else if(set_EFFECT == 1)
		effect_off_user_reinforce();
	 break;
	case '2': auto_reinforce(); break;

	case '3': save(); break;

	case '4': weapon(); break;

	case '5': boss(); break;

	case '6': get_gold(); break;
	case '7': turn_off(); break;
	case '8': gacha(); break;
	case '9': figure = 0; reinforce_interface(); break;
	case '0' : setting(); break;

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
	printf("★              유저가 직접 강화하는 시스템 입니다.               ☆\n");
	printf("☆      총 20강까지 있으며 강화 중 특별한 아이템이 나옵니다.      ★\n");
	printf("★               12강 부터는 파괴확률이 생깁니다.                 ☆\n");
	printf("☆   파괴시에는 100골드를 주고 9강부터 다시 강화 할 수 있습니다.  ★\n");
	printf("★            강화를 하시려면 엔터를 눌러주세요!                  ☆\n");
	printf("☆                                                                ★\n");
	printf("★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆\n");

	_getch();

	system("cls");

	printf("강화중.");

	Sleep(750);
	system("cls");
	printf("강화중..");

	Sleep(750);
	system("cls");
	printf("강화중...");

	if (figure < 6)
	{
		reinforce_5();
	}

	else if (figure < 12)
	{
		reinforce_11();


	}
	else if (figure < 17)
		reinforce_16();
	else if (figure < 20)
		reinforce_20();


	else
	{
		printf("\n\n ※이미 강화가 완료된 무기입니다. \n 다음 컨텐츠를 기다려 주시기 바랍니다. \t\t\t현재 무기 : %d강\n\n", figure);
		Sleep(3000);
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
	printf("★          일정 골드 만큼 강화 해드리는 시스템 입니다.           ☆\n");
	printf("☆            강화 중 특별한 아이템이 나오지 않습니다 .           ★\n");
	printf("★              12강 부터는 파괴확률이 생깁니다.                  ☆\n");
	printf("☆   파괴시에는 100골드를 주고 9강부터 다시 강화 할 수 있습니다.  ★\n");
	printf("★               강화를 하시려면 엔터를 눌러주세요!               ☆\n");
	printf("☆                                                                ★\n");
	printf("★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆\n");

	_getch();


	i = reinforce();


	printf("%d", i);

	_getch();
	reinforce_interface();
}
int save()
{

}
int weapon()
{

}
int boss()
{

}
int get_gold()
{

}
int turn_off()
{

}

int reinforce_5()
{
	srand(time(NULL));
	int Fates_dice = rand() % (1000 + 1);
	switch (figure)
	{
	case 0:
		if (Fates_dice < 950)
		{
			figure++;
			reinforce_success();
		}
		else
			reinforce_fail();
		break;
	case 1:
		if (Fates_dice < 900)
		{
			figure++;
			reinforce_success();
		}
		else
			reinforce_fail();
		break;
	case 2:
		if (Fates_dice < 850)
		{
			figure++;
			reinforce_success();
		}
		else
			reinforce_fail();
		break;
	case 3:
		if (Fates_dice < 800)
		{
			figure++;
			reinforce_success();
		}
		else
			reinforce_fail();
		break;
	case 4:
		if (Fates_dice < 700)
		{
			figure++;
			reinforce_success();
		}
		else
			reinforce_fail();
		break;
	case 5:
		if (Fates_dice < 650)
		{
			figure++;
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
	srand(time(NULL));
	int Fates_dice = rand() % (1000 + 1);
	switch (figure)
	{
	case 6:
		if (Fates_dice < 550)
		{
			figure++;
			reinforce_success();
		}
		else
		{
			figure--;
			reinforce_fail();
		}
		break;
	case 7:
		if (Fates_dice < 500)
		{
			figure++;
			reinforce_success();
		}
		else
		{
			figure--;
			reinforce_fail();
		}
		break;
	case 8:
		if (Fates_dice < 450)
		{
			figure++;
			reinforce_success();
		}
		else
		{
			figure--;
			reinforce_fail();
		}
		break;
	case 9:
		if (Fates_dice < 425)
		{
			figure++;
			reinforce_success();
		}
		else
		{
			figure--;
			reinforce_fail();
		}
		break;
	case 10:
		if (Fates_dice < 400)
		{
			figure++;
			reinforce_success();
		}
		else
		{
			figure--;
			reinforce_fail();
		}
	case 11:
		if (Fates_dice < 350)
		{
			figure++;
			reinforce_success();
		}
		else
		{
			figure--;
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
	printf("☆     현재 강화 : %d      ★\n", figure);
	printf("★☆★☆★☆★☆★☆★☆★☆\n");

	Sleep(300);
	system("cls");
	printf("☆★☆★☆★☆★☆★☆★☆★\n");
	printf("★                        ☆\n");
	printf("☆       강화 성공!       ★\n");
	printf("★     현재 강화 : %d      ☆\n", figure);
	printf("☆★☆★☆★☆★☆★☆★☆★\n");

	Sleep(300);
	system("cls");
	printf("★☆★☆★☆★☆★☆★☆★☆\n");
	printf("☆                        ★\n");
	printf("★       강화 성공!       ☆\n");
	printf("☆     현재 강화 : %d      ★\n", figure);
	printf("★☆★☆★☆★☆★☆★☆★☆\n");
}

int reinforce_fail()
{
	system("cls");

	printf("┌────────────┐\n");
	printf("│                        │\n");
	printf("│       강화 실패...     │\n");
	printf("│     현재 강화 : %d      │\n", figure);
	printf("└────────────┘\n");
	Sleep(1000);

}

int reinforce()
{
	srand(time(NULL));
	int Fates_dice;
	int attempt = 0;
	while (figure<12)
	{
		Fates_dice = rand() % (1000 + 1);
		attempt++;
		switch (figure)
		{
		case 0:
			if (Fates_dice < 950)
				figure++;
			break;

		case 1:
			if (Fates_dice < 900)
				figure++;
			break;

		case 2:
			if (Fates_dice < 850)
				figure++;
			break;

		case 3:
			if (Fates_dice < 800)
				figure++;
			break;

		case 4:
			if (Fates_dice < 700)
				figure++;
			break;

		case 5:
			if (Fates_dice < 650)
				figure++;
			break;

		case 6:
			if (Fates_dice < 550)
				figure++;
			else
				figure--;
			break;

		case 7:
			if (Fates_dice < 500)
				figure++;
			else
				figure--;
			break;

		case 8:
			if (Fates_dice < 450)
				figure++;
			else
				figure--;
			break;
		case 9:
			if (Fates_dice < 425)
				figure++;
			else
				figure--;
			break;
		case 10:
			if (Fates_dice < 400)
				figure++;
			else
				figure--;
			break;
		case 11:
			if (Fates_dice < 350)
				figure++;
			else
				figure--;
			break;
		default:
			break;

		}
		printf("현재 강화 단계 : %d\n", figure);
	}
	Fates_dice = 0;
	return attempt;
}

int gacha()
{
	printf("0-1강 : 95퍼센트 \n");
	printf("1-2강 : 90퍼센트 \n");
	printf("2-3강 : 85퍼센트 \n");
	printf("3-4강 : 80퍼센트 \n");
	printf("4-5강 : 70퍼센트 \n");
	printf("5-6강 : 65퍼센트 \n");
	printf("6-7강 : 55퍼센트 \n");
	printf("7-8강 : 50퍼센트 \n");
	printf("8-9강 : 45퍼센트 \n");
	printf("9-10강 : 42.5퍼센트 \n");
	printf("10-11강 : 40퍼센트\n");
	printf("11-12강 : 35퍼센트 \n");
	_getch();

	reinforce_interface();
}
int setting()
{
	char input;
	printf("┌──────설정──────┐\n");
	printf("│    1. 강화 이펙트 on/off   │\n");
	printf("│         2. 나가기          │\n");
	printf("│      번호를 눌러주세요     │\n");
	printf("└──────────────┘\n");

	input = _getch();
	switch (input)
	{
	case '1': 
		if (set_EFFECT == 0)
		{
			printf("\n 강화 이펙트가 꺼졌습니다.");
			set_EFFECT = 1;
		}
		else
		{
			printf("\n강화 이펙트가 켜졌습니다.");
			set_EFFECT = 0;
			
		}
		 break;
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
	printf("☆                                                                ★\n");
	printf("★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆\n");

	_getch();


	if (figure < 6)
	{
		effect_off_reinforce_5();
	}

	else if (figure < 12)
	{
		effect_off_reinforce_11();


	}
	else if (figure < 17)
		effect_off_reinforce_16();
	else if (figure < 20)
		effect_off_reinforce_20();


	else
	{
		printf("\n\n ※이미 강화가 완료된 무기입니다. \n 다음 컨텐츠를 기다려 주시기 바랍니다. \t\t\t현재 무기 : %d강\n\n", figure);
		Sleep(3000);
		effect_off_user_reinforce();
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
	srand(time(NULL));
	int Fates_dice = rand() % (1000 + 1);
	switch (figure)
	{
	case 0:
		if (Fates_dice < 950)
		{
			figure++;
			effect_off_reinforce_success();
		}
		else
			effect_off_reinforce_fail();
		break;
	case 1:
		if (Fates_dice < 900)
		{
			figure++;
			effect_off_reinforce_success();
		}
		else
			effect_off_reinforce_fail();
		break;
	case 2:
		if (Fates_dice < 850)
		{
			figure++;
			effect_off_reinforce_success();
		}
		else
			effect_off_reinforce_fail();
		break;
	case 3:
		if (Fates_dice < 800)
		{
			figure++;
			effect_off_reinforce_success();
		}
		else
			effect_off_reinforce_fail();
		break;
	case 4:
		if (Fates_dice < 700)
		{
			figure++;
			effect_off_reinforce_success();
		}
		else
			effect_off_reinforce_fail();
		break;
	case 5:
		if (Fates_dice < 650)
		{
			figure++;
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
	srand(time(NULL));
	int Fates_dice = rand() % (1000 + 1);
	switch (figure)
	{
	case 6:
		if (Fates_dice < 550)
		{
			figure++;
			effect_off_reinforce_success();
		}
		else
		{
			figure--;
			effect_off_reinforce_fail();
		}
		break;
	case 7:
		if (Fates_dice < 500)
		{
			figure++;
			effect_off_reinforce_success();
		}
		else
		{
			figure--;
			effect_off_reinforce_fail();
		}
		break;
	case 8:
		if (Fates_dice < 450)
		{
			figure++;
			effect_off_reinforce_success();
		}
		else
		{
			figure--;
			effect_off_reinforce_fail();
		}
		break;
	case 9:
		if (Fates_dice < 425)
		{
			figure++;
			effect_off_reinforce_success();
		}
		else
		{
			figure--;
			effect_off_reinforce_fail();
		}
		break;
	case 10:
		if (Fates_dice < 400)
		{
			figure++;
			effect_off_reinforce_success();
		}
		else
		{
			figure--;
			effect_off_reinforce_fail();
		}
	case 11:
		if (Fates_dice < 350)
		{
			figure++;
			effect_off_reinforce_success();
		}
		else
		{
			figure--;
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
	printf("☆     현재 강화 : %d      ★\n", figure);
	printf("★☆★☆★☆★☆★☆★☆★☆\n");
	
	_getch();
}

int effect_off_reinforce_fail()
{
	system("cls");

	printf("┌────────────┐\n");
	printf("│                        │\n");
	printf("│       강화 실패...     │\n");
	printf("│     현재 강화 : %d      │\n", figure);
	printf("└────────────┘\n");
	_getch();

}
