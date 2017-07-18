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


int Data[4] = { 0, 2000, 0, 0 };			//��ȭ, ���, ����Ʈ on/off, �ڵ� ��ȭ�� 



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

	printf("��������������������������������������������\n");
	printf("��  ��ȭ �ý��ۿ� ���� ���� ȯ�� �մϴ�.  ��\n");
	printf("��  �����Ͻ÷��� �ƹ����̳� �����ּ���.   ��\n");
	printf("��������������������������������������������\n");

	_getch();


	reinforce_interface();
}

int reinforce_interface()
{
	char menu;

	system("cls");
	printf("�ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ�\n");
	printf("��                                            ��\n");
	printf("��              1�� ���� ��ȭ                 ��\n");
	printf("��         2�� �ڵ� ��ȭ ������ ���          ��\n");
	printf("��        3�� ���ݱ����� �����͸� ����        ��\n");
	printf("��      4�� ���� �ڽ��� ���� Ȯ��, ��ż�     ��\n");
	printf("��               5�� ���� ����                ��\n");
	printf("��               6�� Ȯ�� Ȯ��                ��\n");
	printf("��              7�� ���� �ʱ�ȭ               ��\n");
	printf("��                 0�� ����                   ��\n");
	printf("��   ��ȣ�� �Է��Ͻð� ���͸� �����ּ���.     ��\n");
	printf("��                                            ��\n");
	printf("�ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ�\n");

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
	printf("��         ��ȭ �ý����Դϴ�. ��ȭ���� 150��尡 �ʿ��մϴ�.      ��\n");
	printf("��      �� 20������ ������ ��ȭ �� Ư���� �������� ���ɴϴ�.      ��\n");
	printf("��               12�� ���ʹ� �ı�Ȯ���� ����ϴ�.                 ��\n");
	printf("��   �ı��ÿ��� 100��带 �ְ� 9������ �ٽ� ��ȭ �� �� �ֽ��ϴ�.  ��\n");
	printf("��              ��ȭ�� �Ͻ÷��� ���͸� �����ּ���!                ��\n");
	printf("��                  ���� ��ȭ : %d ��� : %d                     ��\n", Data[0], Data[1]);
	printf("��                                                                ��\n");
	printf("�١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١�\n");

	_getch();

	system("cls");
	printf("��ȭ��.");

	Sleep(750);
	system("cls");
	printf("��ȭ��..");

	Sleep(750);
	system("cls");
	printf("��ȭ��...");

	if (Data[1]<150)
	{
		printf("\n\n\n �ذ�尡 �����մϴ�.");
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
		printf("\n\n ���̹� ��ȭ�� �Ϸ�� �����Դϴ�. \n ���� �������� ��ٷ� �ֽñ� �ٶ��ϴ�. \t\t\t���� ���� : %d��\n\n", Data[0]);
		_getch();
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
	printf("��         ��ȭ�ϴٰ� ���� �ڵ���ȭ���� ����� �� �ֽ��ϴ�.       ��\n");
	printf("��            ��ȭ �� Ư���� �������� ������ �ʽ��ϴ�.            ��\n");
	printf("��                 12������ ��ȭ �� �� �ֽ��ϴ�.                  ��\n");
	printf("��         �ڵ���ȭ�ǰ� �ڵ���ȭ Ƚ���� 50��尡 ���˴ϴ�.      ��\n");
	printf("��               ��ȭ�� �Ͻ÷��� ���͸� �����ּ���!               ��\n");
	printf("��           ���� ��ȭ �ܰ� : %d       �ڵ���ȭ�� : %d              ��\n", Data[0], Data[3]);
	printf("��                                                                ��\n");
	printf("�١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١�\n");

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
		printf("\n\n�������� �ʰ� ��ʴϴ�.\n\n");
		_getch();
		reinforce_interface();
	}

}
int save()
{
	system("cls");

	printf("�ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ�\n");
	printf("��                                            ��\n");
	printf("��     ���̺� �����͸� ���� �� �ֽ��ϴ�.      ��\n");
	printf("��    ���� ���ᳪ �޴����� ���Ǽ� �ֽ��ϴ�.   ��\n");
	printf("��     ���� ����� �ڵ����� �ҷ� �ɴϴ�.      ��\n");
	printf("��       save.dat������ ������ ������.        ��\n");
	printf("��                                            ��\n");
	printf("�١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١�\n");

	_getch();

	FILE *fp = fopen("sava.dat", "wb");
	if (fp == NULL)
		return 0;

	fwrite(&Data, sizeof(Data), 1, fp);
	fclose(fp);


	printf("�Ϸ� �Ǿ����ϴ�.\n\n");
	_getch();
	reinforce_interface();
}

int weapon_interface()
{
	printf("�١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ�\n");
	printf("��                                                  ��\n");
	printf("��               ����忡 ���̽��ϴ�.               ��\n");
	printf("��      ���ݱ��� ��ȭ�� ���⸦ �� �� �ֽ��ϴ�.      ��\n");
	printf("��    �� �ڿ� �ٷ� �ٸ� ���⸦ ��ȭ�� �� �ֽ��ϴ�.  ��\n");
	printf("��                                                  ��\n");
	printf("��            �Ľ÷��� 1���� �����ּ���!            ��\n");
	printf("��                                                  ��\n");
	printf("�١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ�\n");
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
		printf("\n\n������� ���ε��� ����� ���⿡ ������ �����ϴ�.\n\n");
		printf("�縮�� || ����� ����\n");
		printf("�� ����� ���� �� ������ �̸� ��� ���� �׷�?\n");
	}
	else if (Fates_dice<101 && Data[0] !=0)
	{
		printf("\n\n������� ���ε��� ����� ���Ⱑ �׷����� �̶�� ���մϴ�.\n\n");
		printf("���� || ����\n");
		printf("�� ���� �׷������ε� ��� ��ǰ�ΰ�? ����� �̷��� �����ٵ�..\n");
	}
		
		 
	else if (Fates_dice<151 && Data[0] !=0)
		{
			printf("\n\n������� ���ε� ��ΰ� ����� ���⸦ ��� �;� �մϴ�.\n\n");
			printf("���ʸ��� || Ȯ�� ��ȭ�� ����\n");
			printf("��� ����...? �̷��� ��ȭ�� ����� �ִٴ�... ���� ����, ����ҰԿ� ����\n");
		}
		
		if (Data[0] == 0)
		{
			printf("\n\n�ȸ� %d��尡 ���ɴϴ�. �Ĵ� ���Դϴ�.", get_golds);
			Sleep(1000);
			system("cls");
			weapon_interface();
			printf("\n\n�ȸ� %d��尡 ���ɴϴ�. �Ĵ� ���Դϴ�..", get_golds);
			Sleep(1000);
			system("cls");
			weapon_interface();
			printf("\n\n�ȸ� %d��尡 ���ɴϴ�. �Ĵ� ���Դϴ�...", get_golds );
			Sleep(1000);
			Data[0] = 0;
			Data[1] = Data[1] + get_golds;
			reinforce_interface();
		}
		else
			{
			Sleep(3000);
			printf("\n�ȸ� %d��尡 ���ɴϴ�. �Ĵ� ���Դϴ�.", get_golds);
			Sleep(1000);
			system("cls");
			weapon_interface();
			printf("\n�ȸ� %d��尡 ���ɴϴ�. �Ĵ� ���Դϴ�..", get_golds);
			Sleep(1000);
			system("cls");
			weapon_interface();
			printf("\n�ȸ� %d��尡 ���ɴϴ�. �Ĵ� ���Դϴ�...", get_golds);
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
	printf("�ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ�\n");
	printf("��                        ��\n");
	printf("��       ��ȭ ����!       ��\n");
	printf("��     ���� ��ȭ : %d      ��\n", Data[0]);
	printf("�ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ�\n");

	Sleep(300);
	system("cls");
	printf("�١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١�\n");
	printf("��                        ��\n");
	printf("��       ��ȭ ����!       ��\n");
	printf("��     ���� ��ȭ : %d      ��\n", Data[0]);
	printf("�١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١�\n");

	Sleep(300);
	system("cls");
	printf("�ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ�\n");
	printf("��                        ��\n");
	printf("��       ��ȭ ����!       ��\n");
	printf("��     ���� ��ȭ : %d      ��\n", Data[0]);
	printf("�ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ�\n");
}

int reinforce_fail()
{
	system("cls");

	printf("����������������������������\n");
	printf("��                        ��\n");
	printf("��       ��ȭ ����...     ��\n");
	printf("��     ���� ��ȭ : %d      ��\n", Data[0]);
	printf("����������������������������\n");
	Sleep(1000);

}

int reinforce()
{
	int Fates_dice;
	int attempt = 0;

	printf("\n\n**��ȭ ����**\n\n");
	if(Data[1]<50)
	{
		printf("��尡 �����մϴ�."); 
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
		printf("\n���� ��ȭ �ܰ� : %d\n", Data[0]);
	
	}
	Fates_dice = 0;
	return attempt;
}

int gacha()
{
	printf("0-1�� : 95�ۼ�Ʈ 		�ڵ���æƮ�� : 30�ۼ�Ʈ\n");
	printf("1-2�� : 90�ۼ�Ʈ  		�ڵ���æƮ�� : 30�ۼ�Ʈ\n");
	printf("2-3�� : 85�ۼ�Ʈ  		�ڵ���æƮ�� : 31�ۼ�Ʈ\n");
	printf("3-4�� : 80�ۼ�Ʈ  		�ڵ���æƮ�� : 32�ۼ�Ʈ\n");
	printf("4-5�� : 70�ۼ�Ʈ  		�ڵ���æƮ�� : 32�ۼ�Ʈ\n");
	printf("5-6�� : 65�ۼ�Ʈ  		�ڵ���æƮ�� : 32�ۼ�Ʈ\n");
	printf("6-7�� : 55�ۼ�Ʈ  		�ڵ���æƮ�� : 25�ۼ�Ʈ\n");
	printf("7-8�� : 50�ۼ�Ʈ  		�ڵ���æƮ�� : 25�ۼ�Ʈ\n");
	printf("8-9�� : 45�ۼ�Ʈ  		�ڵ���æƮ�� : 25�ۼ�Ʈ\n");
	printf("9-10�� : 42.5�ۼ�Ʈ  	�ڵ���æƮ�� : 20�ۼ�Ʈ\n");
	printf("10-11�� : 40�ۼ�Ʈ 		�ڵ���æƮ�� : 20�ۼ�Ʈ\n");
	printf("11-12�� : 35�ۼ�Ʈ 		�ڵ���æƮ�� : 20�ۼ�Ʈ\n");
	_getch();

	reinforce_interface();
}
int setting()
{
	char input, input1;
	printf("��������������������������������\n");
	printf("��   1. ��ȭ ����Ʈ on/off    ��\n");
	printf("��         2. �ʱ�ȭ          ��\n");
	printf("��      ��ȣ�� �����ּ���     ��\n");
	printf("��������������������������������\n");

	input = _getch();
	switch (input)
	{
	case '1':
		if (Data[2] == 0)
		{
			printf("\n ��ȭ ����Ʈ�� �������ϴ�.");
			Data[2] = 1;
		}
		else
		{
			printf("\n��ȭ ����Ʈ�� �������ϴ�.");
			Data[2] = 0;

		}
		break;

	case '2':
		printf("�������������ʱ�ȭ��������������\n");
		printf("�� ���� �ʱ�ȭ �Ͻðڽ��ϱ�?  ��\n");
		printf("��   1���� �����ø� �˴ϴ�.   ��\n");
		printf("��������������������������������\n");

		input1 = _getch();

		if (input1 == '1')
		{
			printf("\n�ʱ�ȭ �Ǿ����ϴ�. �ʱ�ȭ �� �����͸� ���� �մϴ�.");
			Data[0] = 0;
			Data[1] = 2000;
			Data[2] = 0;
			Data[3] = 0;

			Sleep(2000);
			save();
		}

		else
		{
			printf("��ſ� �ð� ��������!\n");
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

	printf("�ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ�\n");
	printf("��                                                                ��\n");
	printf("��              ������ ���� ��ȭ�ϴ� �ý��� �Դϴ�.               ��\n");
	printf("��      �� 20������ ������ ��ȭ �� Ư���� �������� ���ɴϴ�.      ��\n");
	printf("��               12�� ���ʹ� �ı�Ȯ���� ����ϴ�.                 ��\n");
	printf("��   �ı��ÿ��� 100��带 �ְ� 9������ �ٽ� ��ȭ �� �� �ֽ��ϴ�.  ��\n");
	printf("��            ��ȭ�� �Ͻ÷��� ���͸� �����ּ���!                  ��\n");
	printf("��                  ���� ��ȭ : %d ��� : %d                     ��\n", Data[0], Data[1]);
	printf("��                                                                ��\n");
	printf("�١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١�\n");

	_getch();

	if (Data[1]<150)
	{
		printf("\n\n\n �ذ�尡 �����մϴ�.");
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
		printf("\n\n ���̹� ��ȭ�� �Ϸ�� �����Դϴ�. \n ���� �������� ��ٷ� �ֽñ� �ٶ��ϴ�. \t\t\t���� ���� : %d��\n\n", Data[0]);
		_getch();
		reinforce_interface();
	}

	else if (Data[1]<149) {
		printf("\n\n\n �ذ�尡 �����մϴ�.");
		_getch();
		reinforce_interface();
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
	printf("�ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ�\n");
	printf("��                        ��\n");
	printf("��       ��ȭ ����!       ��\n");
	printf("��     ���� ��ȭ : %d      ��\n", Data[0]);
	printf("�ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ�\n");

	_getch();
}

int effect_off_reinforce_fail()
{
	system("cls");

	printf("����������������������������\n");
	printf("��                        ��\n");
	printf("��       ��ȭ ����...     ��\n");
	printf("��     ���� ��ȭ : %d      ��\n", Data[0]);
	printf("����������������������������\n");
	_getch();

}
int get_auto_Enchant()
{
	Data[3]++;

	system("cls");
	printf("�ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ�\n");
	printf("��                        ��\n");
	printf("��       ��ȭ ����!       ��\n");
	printf("��   �ڵ� ��æƮ�� ȹ��!  ��\n");
	printf("�ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ�\n");

	Sleep(300);
	system("cls");
	printf("�١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١�\n");
	printf("��                        ��\n");
	printf("��       ��ȭ ����!       ��\n");
	printf("��   �ڵ� ��æƮ�� ȹ��!  ��\n");
	printf("�١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١�\n");

	Sleep(300);
	system("cls");
	printf("�ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ�\n");
	printf("��                        ��\n");
	printf("��       ��ȭ ����!       ��\n");
	printf("��   �ڵ� ��æƮ�� ȹ��!  ��\n");
	printf("�ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ�\n");

	_getch();
}
