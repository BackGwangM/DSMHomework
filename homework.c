#include <stdio.h>
#define swap(temp, a, b) ((temp)=(a), (a)=(b), (b)=(temp))

int main(void)
{
	printf("***************************************************************************\n");
	printf("               ���� ������ �ص帮�� ���α׷� �Դϴ�.\n");
	printf("               ������ ���� �� ����Ž���� �����մϴ�.\n");
	printf("      ������ ���ϽŴٸ� �ƹ��ų� �����ð� ���͸� �����ּ���.\n");
	printf("***************************************************************************\n");
	
	getchar();
	select_sort();
}

int select_sort(void)
{
	int array[10];
	int min, count = 0, find_start;
	int i, temp, j = 1, exchange_count = 0, compare_count = 0, total_exchange = 0, total_compare = 0;

	system("cls");
	printf("***************************************************************************\n");
	printf("               ���� ���� ���μ����� ���� �Ǿ����ϴ�.\n");
	printf("        ������ ���Ͻô� ���ڸ� �Է����ּ���(10�� ������ ����)\n");
	printf("       �׸� �Է��Ͻð� �����ôٸ� 9999�� �Է��� �ֽø� �˴ϴ�.\n");
	printf("***************************************************************************\n");

	for (i = 0; i<10; i++)
	{
		printf("%d��° ���� : ", i+1);
		scanf("%d", &array[i]);
		count++;
		if (array[i] == 9999)
		{
			count--;
			break;
		}

	}

	for (i = 0; i<count; i++) {
			
		compare_count++;
				
		}

		if (array[min] != array[j]) {
			swap(temp, array[min], array[j]);
			exchange_count++;
		}
		total_exchange = total_exchange + exchange_count;
		total_compare = total_compare + compare_count;
		printf("\t%dpass : \t", j);

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

	printf("\n\n\n***************************************************************************\n");
	printf("    ����Ž������ �̵��ϰ� �ʹٸ�  1�� �����ð� ���͸� �����ּ���.\n");
	printf("                 ������ �����Ŵٸ� ���ø� �˴ϴ�.\n");
	printf("***************************************************************************\n");
	scanf("%d", &find_start);
	
	if(find_start == 1) 
	search(array, count);
	
	else
	return 0;


}

int search(int *array, int count)
{
	int input = 0, count_search;
	int high = count - 1;
	int low = 0, mid, i,j;

	system("cls");
	printf("***************************************************************************\n");
	printf("                 ����Ž��  ���μ����� ���� �Ǿ����ϴ�.\n");
	printf("                 ã�⸦ ���Ͻô� ���ڸ� �Է����ּ���\n");
	printf("***************************************************************************\n");
	
	
	for(i = 0; i<count/3; i++)
	{
		printf("%d��° �ε��� �� : %d\t", i, array[i]);
	}
		printf("\n");
	for(i = 3; i<count/3*2; i++)
	{
		printf("%d��° �ε��� �� : %d\t", i, array[i]);
	}
		printf("\n");
	for(i = 6; i<count; i++)
	{
		printf("%d��° �ε��� �� : %d\t", i, array[i]);
	}
		printf("\n");
	
	printf("ã�⸦ ���ϴ� ���� : ");
	scanf("%d", &input);


	
	while (low <= high) {
		mid = (low + high) / 2;
		if (input == array[mid]){
			count_search++;
			printf("%d��°���� %d Ž�� ����!\tŽ��Ƚ�� : %d", mid, array[mid], count_search);
			break;
		}
		
		else if (input < array[mid])
		{
			count_search++;
			high = mid - 1;
		}

		else if (input > array[mid])
		{
			count_search++;
			low = mid + 1;
		}
		else
		{
			printf("ERROR! ã�� ���Ͽ����ϴ�!!");
		}
}
}
