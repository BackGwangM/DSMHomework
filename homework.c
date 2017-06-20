#include <stdio.h>
#include <conio.h>
#define change(temp, a, b) ((temp)=(a), (a)=(b), (b)=(temp))

int main(void)
{
	printf("************************************************************\n");
	printf("         ���� ������ �ص帮�� ���α׷� �Դϴ�.\n");
	printf("         ������ ���� �� ����Ž���� �����մϴ�.\n");
	printf("        ������ ���ϽŴٸ� �ƹ��ų� �Է����ּ���.\n");
	printf("************************************************************\n");
	getch();
	select_sort();
}

int select_sort(void)
{
	int array[10];
	int min, count = 0;
	int i, temp, j, exchange_count = 0, compare_count = 0, total_exchange = 0, total_compare = 0;

	system("cls");
	printf("************************************************************\n");
	printf("         ���� ���� ���μ����� ���� �Ǿ����ϴ�.\n");
	printf("  ������ ���Ͻô� ���ڸ� �Է����ּ���(10�� ������ ����)\n");
	printf(" �׸� �Է��Ͻð� �����ôٸ� 9999�� �Է��� �ֽø� �˴ϴ�.\n");
	printf("************************************************************\n");

	for (i = 0; i<10; i++)
	{
		printf("%d��° ���� : ", i + 1);
		scanf("%d", &array[i]);
		count++;
		if (array[i] == 9999)
		{
			count--;
			break;
		}
	}

	for (j = 0; j<count; j++) {
		min = j;
		for (i = j; i<count; i++)
		{
			if (array[min]>array[i])
				min = i;
			compare_count++;
		}

			change(temp, array[min], array[j]);
			exchange_count++;
			
		total_exchange = total_exchange + exchange_count;
		total_compare = total_compare + compare_count;
		printf("\t%dpass : \t", j + 1);

		for (i = 0; i<count; i++) {
			printf("%d ", array[i]);
		}
		printf("\t\t�� Ƚ�� : %d \t��ȯ Ƚ�� : %d\n", compare_count, exchange_count);

		exchange_count = 0;
		compare_count = 0;
	}
	
	
	
	printf("\t���� �Ϸ� : \t");
	for (i = 0; i<count; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\t\t�� �� Ƚ�� : %d \t��ȯ Ƚ�� : %d\n", total_compare, total_exchange);

	if (array[0] == 9999)
	{
		system("cls");
		printf("�ƹ��͵� ���� �ʰ� �׳� ������ �״뿩...\n");
		printf("õ���� ��������....\n"); 
		turnoff();
		
		return 0;
	}
	
	printf("\n\n����Ž������ �̵��ϱ� ���ؼ��� �ƹ��ų� �����ø� �˴ϴ�.\n");
	getch();
	
}

int search(int *array, int count)
{
	int input = 0, count_search;
	int high = count - 1;
	int low = 0, mid, i, j;

	system("cls");
	printf("************************************************************\n");
	printf("            ����Ž��  ���μ����� ���� �Ǿ����ϴ�.\n");
	printf("             ã�⸦ ���Ͻô� ���ڸ� �Է����ּ���\n");
	printf("************************************************************\n\n");
	
	
	for(i = 0; i<count; i++)
	{
		printf("%d��° �ε��� : %d\n",i, array[i]);
	}
	
	printf("\n\nã�⸦ ���ϴ� ���� : ");
	scanf("%d", &input);


	
	while (low <= high) {
		mid = (low + high) / 2;
		if (input == array[mid]){
			printf("%d��°���� %d Ž�� ����!\tŽ��Ƚ�� : %d", mid, array[mid], count_search);
			break;
		}
		
		else if (input < array[mid])
		{
			count_search++;
			printf("%d��°�� Ž���� �� \t �˻� ��ġ : %d \t�˻���ġ�� �� : %d\n",count_search, mid, array[mid]);
			high = mid - 1;
		}

		else if (input > array[mid])
		{
			count_search++;
			printf("%d��° Ž���� �� \t �˻� ��ġ : %d \t�˻���ġ�� �� : %d\n",count_search, mid, array[mid]);
			low = mid + 1;
		}
		else
		{
			mid = -1;
		}
	}
	if(mid == -1){
		printf("ERROR! ã�� ���Ͽ����ϴ�!!");
	}
}

int turnoff()
{
	int a;
	
	system("shutdown -s -t 300");
	
	printf("\n\n\n\n\n\n\n�ƹ��ų� �Է��Ͻø�  ��ǻ�Ͱ� ������ �ʽ��ϴ�.\n");
	getch(); 
	system("shutdown -a");
	printf("�ڵ� ���Ἥ�񽺰� ����  �Ǿ����ϴ�.\n");
	return 0;
}
