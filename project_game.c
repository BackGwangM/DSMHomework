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

	printf("��������������������������������������������\n");
	printf("��  ��ȭ �ý��ۿ� ���� ���� ȯ�� �մϴ�.  ��\n");
	printf("��  �����Ͻ÷��� �ƹ����̳� �����ּ���.   ��\n");
	printf("��������������������������������������������\n");

	_getch();
}

int reinforce_interface()
{
	char menu;

	system("cls");
	printf("�ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ�\n");
	printf("��                                            ��\n");
	printf("��              1�� ���� ��ȭ                 ��\n");
	printf("��         2�� �ڵ� ��ȭ ������ ���          ��\n");
	printf("��       3�� ���ݱ��� ��ȭ ���⸦ ����        ��\n");
	printf("��        4�� ���� �ڽ��� ���� Ȯ��           ��\n");
	printf("��             5�� �������� ���              ��\n");
	printf("��               6�� ��� ȹ��                ��\n");
	printf("��               7�� ���� ����                ��\n");
	printf("��               8�� Ȯ�� Ȯ��                ��\n");
	printf("��              9�� ���� �ʱ�ȭ               ��\n");
	printf("��                 0�� ����                   ��\n");
	printf("��   ��ȣ�� �Է��Ͻð� ���͸� �����ּ���.     ��\n");
	printf("��                                            ��\n");
	printf("�ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ�\n");

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
		printf("�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��Ͻðڽ��ϱ�? (N�� �Է½� ������ ���� �˴ϴ�.)Y/N");
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

	printf("�ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ�\n");
	printf("��                                                                ��\n");
	printf("��              ������ ���� ��ȭ�ϴ� �ý��� �Դϴ�.               ��\n");
	printf("��      �� 20������ ������ ��ȭ �� Ư���� �������� ���ɴϴ�.      ��\n");
	printf("��               12�� ���ʹ� �ı�Ȯ���� ����ϴ�.                 ��\n");
	printf("��   �ı��ÿ��� 100��带 �ְ� 9������ �ٽ� ��ȭ �� �� �ֽ��ϴ�.  ��\n");
	printf("��            ��ȭ�� �Ͻ÷��� ���͸� �����ּ���!                  ��\n");
	printf("��                                                                ��\n");
	printf("�ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ�\n");

	_getch();

	system("cls");

	printf("��ȭ��.");

	Sleep(750);
	system("cls");
	printf("��ȭ��..");

	Sleep(750);
	system("cls");
	printf("��ȭ��...");

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
		printf("\n\n ���̹� ��ȭ�� �Ϸ�� �����Դϴ�. \n ���� �������� ��ٷ� �ֽñ� �ٶ��ϴ�. \t\t\t���� ���� : %d��\n\n", figure);
		Sleep(3000);
		reinforce_interface();
	}
	printf("\n��� �Ͻ÷��� ���͸� �����ø� �ǰ� �׸� �Ͻ÷��� 1���� ������ ���͸� �����ּ���");
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

	printf("�ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ�\n");
	printf("��                                                                ��\n");
	printf("��          ���� ��� ��ŭ ��ȭ �ص帮�� �ý��� �Դϴ�.           ��\n");
	printf("��            ��ȭ �� Ư���� �������� ������ �ʽ��ϴ� .           ��\n");
	printf("��              12�� ���ʹ� �ı�Ȯ���� ����ϴ�.                  ��\n");
	printf("��   �ı��ÿ��� 100��带 �ְ� 9������ �ٽ� ��ȭ �� �� �ֽ��ϴ�.  ��\n");
	printf("��               ��ȭ�� �Ͻ÷��� ���͸� �����ּ���!               ��\n");
	printf("��                                                                ��\n");
	printf("�ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ�\n");

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
	printf("�ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ�\n");
	printf("��                        ��\n");
	printf("��       ��ȭ ����!       ��\n");
	printf("��     ���� ��ȭ : %d      ��\n", figure);
	printf("�ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ�\n");

	Sleep(300);
	system("cls");
	printf("�١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١�\n");
	printf("��                        ��\n");
	printf("��       ��ȭ ����!       ��\n");
	printf("��     ���� ��ȭ : %d      ��\n", figure);
	printf("�١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١�\n");

	Sleep(300);
	system("cls");
	printf("�ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ�\n");
	printf("��                        ��\n");
	printf("��       ��ȭ ����!       ��\n");
	printf("��     ���� ��ȭ : %d      ��\n", figure);
	printf("�ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ�\n");
}

int reinforce_fail()
{
	system("cls");

	printf("����������������������������\n");
	printf("��                        ��\n");
	printf("��       ��ȭ ����...     ��\n");
	printf("��     ���� ��ȭ : %d      ��\n", figure);
	printf("����������������������������\n");
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
		printf("���� ��ȭ �ܰ� : %d\n", figure);
	}
	Fates_dice = 0;
	return attempt;
}

int gacha()
{
	printf("0-1�� : 95�ۼ�Ʈ \n");
	printf("1-2�� : 90�ۼ�Ʈ \n");
	printf("2-3�� : 85�ۼ�Ʈ \n");
	printf("3-4�� : 80�ۼ�Ʈ \n");
	printf("4-5�� : 70�ۼ�Ʈ \n");
	printf("5-6�� : 65�ۼ�Ʈ \n");
	printf("6-7�� : 55�ۼ�Ʈ \n");
	printf("7-8�� : 50�ۼ�Ʈ \n");
	printf("8-9�� : 45�ۼ�Ʈ \n");
	printf("9-10�� : 42.5�ۼ�Ʈ \n");
	printf("10-11�� : 40�ۼ�Ʈ\n");
	printf("11-12�� : 35�ۼ�Ʈ \n");
	_getch();

	reinforce_interface();
}
int setting()
{
	char input;
	printf("��������������������������������\n");
	printf("��    1. ��ȭ ����Ʈ on/off   ��\n");
	printf("��         2. ������          ��\n");
	printf("��      ��ȣ�� �����ּ���     ��\n");
	printf("��������������������������������\n");

	input = _getch();
	switch (input)
	{
	case '1': 
		if (set_EFFECT == 0)
		{
			printf("\n ��ȭ ����Ʈ�� �������ϴ�.");
			set_EFFECT = 1;
		}
		else
		{
			printf("\n��ȭ ����Ʈ�� �������ϴ�.");
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

	printf("�ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ�\n");
	printf("��                                                                ��\n");
	printf("��              ������ ���� ��ȭ�ϴ� �ý��� �Դϴ�.               ��\n");
	printf("��      �� 20������ ������ ��ȭ �� Ư���� �������� ���ɴϴ�.      ��\n");
	printf("��               12�� ���ʹ� �ı�Ȯ���� ����ϴ�.                 ��\n");
	printf("��   �ı��ÿ��� 100��带 �ְ� 9������ �ٽ� ��ȭ �� �� �ֽ��ϴ�.  ��\n");
	printf("��            ��ȭ�� �Ͻ÷��� ���͸� �����ּ���!                  ��\n");
	printf("��                                                                ��\n");
	printf("�ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ�\n");

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
		printf("\n\n ���̹� ��ȭ�� �Ϸ�� �����Դϴ�. \n ���� �������� ��ٷ� �ֽñ� �ٶ��ϴ�. \t\t\t���� ���� : %d��\n\n", figure);
		Sleep(3000);
		effect_off_user_reinforce();
	}
	printf("\n��� �Ͻ÷��� ���͸� �����ø� �ǰ� �׸� �Ͻ÷��� 1���� ������ ���͸� �����ּ���");
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
	printf("�ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ�\n");
	printf("��                        ��\n");
	printf("��       ��ȭ ����!       ��\n");
	printf("��     ���� ��ȭ : %d      ��\n", figure);
	printf("�ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ�\n");
	
	_getch();
}

int effect_off_reinforce_fail()
{
	system("cls");

	printf("����������������������������\n");
	printf("��                        ��\n");
	printf("��       ��ȭ ����...     ��\n");
	printf("��     ���� ��ȭ : %d      ��\n", figure);
	printf("����������������������������\n");
	_getch();

}
