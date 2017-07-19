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


int Data[7] = { 0, 2000, 0, 0, 0, 0, 0};			//��ȭ, ���, ����Ʈ on/off, �ڵ� ��ȭ�� , ���� ����, ���� ����, ��ȭ �õ� Ƚ�� 



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
	printf("�ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ�"); printf("----------------------------���� ����� ����----------------------------\n");
	printf("��                                            ��"); printf("\t��ȭ ����\t%d\t||\t\t���\t%d\n", Data[0], Data[1]);
	printf("��              1�� ���� ��ȭ                 ��"); printf("\t�ڵ� ��ȭ��\t%d\t||\t\n", Data[3], Data[4]);
	printf("��         2�� �ڵ� ��ȭ ������ ���          ��\n"); 
	printf("��        3�� ���ݱ����� �����͸� ����        ��"); printf("-------------------------------���� ��Ȳ--------------------------------\n");
	printf("��                4�� �����                  ��"); printf("\t����\t%d\t\t||\t\t����\t%d\n", Data[4], Data[5]);
	printf("��            5�� ���� ����, ����             ��\n");
	printf("��               6�� Ȯ�� Ȯ��                ��\n");
	printf("��              7�� ���� �ʱ�ȭ               ��\n");
	printf("��                 9�� ����                   ��\n");
	printf("��               0�� ���� ����                ��\n");
	printf("��   ��ȣ�� �Է��Ͻð� ���͸� �����ּ���.     ��\n");
	printf("��                                            ��\n");
	printf("�ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ�\n");

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
		printf("�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��Ͻðڽ��ϱ�? (N�� �Է½� ������ ���� �˴ϴ�.)Y/N");
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

	printf("�ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ�\n");
	printf("��                                                                ��\n");
	printf("��         ��ȭ �ý����Դϴ�. ��ȭ���� 150��尡 �ʿ��մϴ�.      ��\n");
	printf("��      �� 20������ ������ ��ȭ �� Ư���� �������� ���ɴϴ�.      ��\n");
	printf("��               12�� ���ʹ� �ı�Ȯ���� ����ϴ�.                 ��\n");
	printf("��   �ı��ÿ��� 100��带 �ְ� 9������ �ٽ� ��ȭ �� �� �ֽ��ϴ�.  ��\n");
	printf("��              ��ȭ�� �Ͻ÷��� �ƹ��ų� ��������                 ��\n");
	printf("��             ���� ��ȭ : %d ��� : %d ���� : %d              ��\n", Data[0], Data[1], Data[5]);
	printf("��                                                                ��\n");
	printf("�١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١�\n");

	getch();
	
	system("cls");
	printf("��ȭ��.");

	Sleep(750);
	system("cls");
	printf("��ȭ��..");

	Sleep(750);
	system("cls");
	printf("��ȭ��...");

	if (Data[1]<150 && Data[5]<150)
	{
		printf("\n\n\n �ذ�尡 �����մϴ�.");
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
		printf("\n\n ���̹� ��ȭ�� �Ϸ�� �����Դϴ�. \n ���� �������� ��ٷ� �ֽñ� �ٶ��ϴ�. \t\t\t���� ���� : %d��\n\n", Data[0]);
		_getch();
		reinforce_interface();
	}
	printf("\n��� �Ͻ÷��� ���͸� �����ø� �ǰ� �׸� �Ͻ÷��� 1���� ������ ���͸� �����ּ���");
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

	printf("�ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ�\n");
	printf("��                                                                ��\n");
	printf("��         ��ȭ�ϴٰ� ���� �ڵ���ȭ���� ����� �� �ֽ��ϴ�.       ��\n");
	printf("��            ��ȭ �� Ư���� �������� ������ �ʽ��ϴ�.            ��\n");
	printf("��                 20������ ��ȭ �� �� �ֽ��ϴ�.                  ��\n");
	printf("��         �� �� �õ��� �ڵ���ȭ�ǰ� 10��尡 ���˴ϴ�.         ��\n");
	printf("��               ��ȭ�� �Ͻ÷��� ���͸� �����ּ���!               ��\n");
	printf("��           ���� ��ȭ �ܰ� : %d       �ڵ���ȭ�� : %d              ��\n", Data[0], Data[3]);
	if(Data[4] != 0)
		printf("��             ������ ȿ���� ���� Ȯ���� �������ϴ�.              ��\n");
	else
	{
		printf("��                                                                ��\n");
	}
	printf("�١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١�\n");

	_getch();
	if (Data[3] != 0)
	{
		Data[3]--;
		printf("\n\n���Ͻô� ��ȭ ��ġ : ");
		scanf("%d", &input);
		i = reinforce(input);
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

	FILE *fp = fopen("save.dat", "wb");
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
	int Fates_dice = rand() % (400 + 1);

	system("cls");

	weapon_interface();

	_getch();

	get_golds = (140 * Data[0]) + (Fates_dice*Data[0]);

	if (Fates_dice<100 && Data[0] != 0)
	{
		printf("\n\n������� ���ε��� ����� ���⿡ ������ �����ϴ�.\n\n");
		printf("�縮�� || ����� ����\n");
		printf("�� ����� ���� �� ������ �̸� ��� ���� �׷�?\n");
	}
	else if (Fates_dice<350 && Data[0] != 0)
	{
		printf("\n\n������� ���ε��� ����� ���Ⱑ �׷����� �̶�� ���մϴ�.\n\n");
		printf("���� || ����\n");
		printf("�� ���� �׷������ε� ��� ��ǰ�ΰ�? ����� �̷��� �����ٵ�..\n");
	}


	else if (Fates_dice<401 && Data[0] != 0)
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
		printf("\n\n�ȸ� %d��尡 ���ɴϴ�. �Ĵ� ���Դϴ�...", get_golds);
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

int reinforce(int re)
{
	int Fates_dice;
	int attempt = 0;

	printf("\n\n**��ȭ ����**\n\n");
	
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
		printf("\n���� ��ȭ �ܰ� : %d\n", Data[0]);

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
		printf("\n���� ��ȭ �ܰ� : %d\n", Data[0]);

	}
	Fates_dice = 0;
	return attempt;
	}
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
	printf("�� 3. ���̺� ������ �ҷ�����  ��\n");
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
			Data[4] = 0;
			Data[5] = 0;
			Data[6] = 0;
			

			Sleep(2000);
			save();
		}

		else
		{
			printf("��ſ� �ð� ��������!\n");
			Sleep(2000);
			reinforce_interface();
		}
		case '3' :
		{
			printf("\n\n3�ʵ� ���̺� �����͸� �ҷ��ɴϴ�.\n");
			Sleep(1000);
			printf("\n2�ʵ� ���̺� �����͸� �ҷ��ɴϴ�.\n");
			Sleep(1000);
			printf("\n1�ʵ� ���̺� �����͸� �ҷ��ɴϴ�.\n");
			Sleep(1000);
			FILE *fp = fopen("save.dat", "rb");
			if (fp == NULL) {
			printf("�Ϸ� �Ǿ����ϴ�.");
			getch();
			start();
			}
			fread(&Data, sizeof(Data), 1, fp);
			fclose(fp);
			printf("�Ϸ� �Ǿ����ϴ�.");
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

	printf("�ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ�\n");
	printf("��                                                                ��\n");
	printf("��              ������ ���� ��ȭ�ϴ� �ý��� �Դϴ�.               ��\n");
	printf("��      �� 20������ ������ ��ȭ �� Ư���� �������� ���ɴϴ�.      ��\n");
	printf("��               12�� ���ʹ� �ı�Ȯ���� ����ϴ�.                 ��\n");
	printf("��   �ı��ÿ��� 100��带 �ְ� 9������ �ٽ� ��ȭ �� �� �ֽ��ϴ�.  ��\n");
	printf("��            ��ȭ�� �Ͻ÷��� ���͸� �����ּ���!                  ��\n");
	printf("��             ���� ��ȭ : %d ��� : %d ���� : %d                 ��\n", Data[0], Data[1], Data[5]);
	printf("��                                                                ��\n");
	printf("�١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١�\n");

	_getch();

	if (Data[1]<150 && Data[5]<150)
	{
		printf("\n\n\n �ذ�尡 �����մϴ�.");
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
	
	
	printf("�ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ�\n");
	printf("��                                                                ��");  printf("\t\t������ �ݾ� : %d ��� : %d  ���� �ݾ�: %d\n", Data[4], Data[1], Data[5]);
	printf("��                      ���࿡ ���̽��ϴ�.                        ��\n");
	printf("��                  ���� �� ������ �����մϴ�.                    ��\n");
	printf("��   ����ݾ� ��ȯ��  ���� �ݾ� + ����ݾ��� 10%c�� �ּž� �մϴ�. ��\n", '%');
	printf("��        ���� �ÿ��� ��ȭ Ƚ�� 10���� 3%c�� ���ڰ� ���Դϴ�.      ��\n", '%');
	printf("��             ������ 1�� || ������ 2�� || 3������ ��ȯ           ��\n");
	printf("��       �� ���� ������ �ڵ� ��ȭ���� ��ȭ Ȯ���� �پ� ��ϴ�.    ��\n");
	printf("��                                                                ��\n");
	printf("��      ��ȭ �� �ݾ��� ���� ��� ������ �ݾ׿��� ���������ϴ�.    ��\n");
	printf("��                                                                ��\n");	
	printf("�١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١�\n");
	
	
	
	scanf("%d", &input);
	switch(input)
	{
		case 1 : borrow(); break;
		case 2 : saving(); break;
		case 3 : return_borrow(); break; 
		default : printf("\n\n�߸� �Է��ϼ̽��ϴ�."); Sleep(750); reinforce_interface(); break; 
	}
	
}

int borrow()
{
	int borrow_money = 0;
	int input;
	printf("\n\n\n ���� â���Դϴ�. ���Ͻô� �ݾ��� �Է��� ���͸� �����ּ���\n");
	printf("         1ȸ ���� �ѵ� �ݾ��� 5,000,000�� �Դϴ�.\n\n");
	printf("���� ���� �� : ");
	scanf("%d", &borrow_money);
	
	if(borrow_money<=5000000)
	{
		printf("���� ������ ���� %d�� �Դϴ�. ���� ���� �Ͻðڽ��ϱ�?\n", borrow_money);
		printf("     ������ 1���� �����ð� ���͸� �����ʽÿ�.\n\n");
		printf("���� Ȯ�� ��ȣ (1���� �����ø� �˴ϴ�.) : ");
		scanf("%d", &input);
		
		if(input == 1)
		{
			Data[4] = Data[4] + borrow_money+ borrow_money*0.1;
			Data[1] = Data[1] + borrow_money;
			reinforce_interface();
			
		}
		else
		{
			printf("\n����ϼ̽��ϴ�.");
			Sleep(750);
			getch();
			bank();
		}
	}
	else
		{
			printf("\n�ʹ� ū ���� �Է� �ϼ̽��ϴ�. �ʱ�ȭ������ ���ϴ�.");
			Sleep(750);
			getch();
			bank();
		}
}
int saving()
{
	int money = 0; 
	printf("\n\n\n ���� â�� �Դϴ�. ���� ���� �ݾ��� %d�� �Դϴ�.\n", Data[5]);
	printf("      ��ȭȽ���� 10�� ����� �Ǹ� 3%c�� ���ڰ� ���Դϴ�.\n", '%');
	printf("           ���� �������� %d�� �Դϴ�.\n",Data[1]);
	
	printf("������ �ݾ� : ");
	scanf("%d", &money);
	
	if(Data[1] < money)
	{
		printf("���� ���� �ݾ׺��� ū ���Դϴ�. ���� �ʱ�ȭ������ ���ư��ϴ�.");
		getch();
		bank(); 
	}
	else if(Data[1] > money)
	{
		printf("%d���� �����մϴ�.", money);
		Data[1] = Data[1] - money;
		Data[5] = Data[5] + money;
		getch();
		reinforce_interface();
	}
	else
	{
		printf("�߸� �Է��ϼ̽��ϴ�.");
		getch();
		bank(); 
	}
}
int return_borrow()
{
	int return_money = 0;
	int input;
	printf("\n\n\n ���� ��ȯ â���Դϴ�. �ݾ��� �Է��� ���͸� �����ּ���\n");
	printf("        1ȸ ���� �ѵ� �ݾ��� ���� ���� �ݾ��� %d�� �Դϴ�.\n\n", Data[4]);
	printf("��ȯ �� �� : ");
	scanf("%d", &return_money);
	
	if(return_money<=Data[4])
	{
		printf("               ���� ��ȯ �Ͻ� ���� %d�� �Դϴ�.\n", return_money);
		printf("     ���� �ִ� ��ȯ �Ͻ� ���� %d�� ���� ���� �˴ϴ�.\n\n", Data[4]);
		printf("             ������ 1���� �����ð� ���͸� �����ʽÿ�.\n\n");
		printf("��ȯ Ȯ�� ��ȣ (1���� �����ø� �˴ϴ�.) : ");
		scanf("%d", &input);
		
		if(input == 1)
		{
			Data[4] = Data[4] - return_money;
			Data[1] = Data[1] - return_money;
			reinforce_interface();
		}
		else
		{
			printf("\n����ϼ̽��ϴ�.");
			Sleep(750);
			getch();
			bank();
		}
	}
	else
		{
			printf("\n�ʹ� ū ���� �Է� �ϼ̽��ϴ�. ���� �ʱ�ȭ������ ���ϴ�.");
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

int effect_off_reinforce_broken()
{
	system("cls");

	printf("��  ���Ⱑ ���� ���� �̱��� ���ϰ� �ı��Ǿ����ϴ�. 100���� 9���� ���⸦ �� �� �ֽ��ϴ�. ��");
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
