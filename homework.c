#include <stdio.h>
#define swap(temp, a, b) ((temp)=(a), (a)=(b), (b)=(temp))

int main (void)
{
	int start;
	printf("************************************************************\n");
	printf("         ���� ������ �ص帮�� ���α׷� �Դϴ�.\n");
	printf("      ������ ���� �� ���ϴ� ���ڸ� ã�Ƶ帳�ϴ�.\n");
	printf("     ������ ���ϽŴٸ� 0�� ������ ���͸� ���ּ���.\n");
	printf("************************************************************\n");
	scanf("%d",&start);
	if(start == 0) 
		select_sort();
}

int select_sort(void)
{
	static int array[10];
	int min, count = 0, find_start;
	int i, temp, j, exchange_count = 0, compare_count = 0, total_exchange = 0, total_compare = 0;
	
	system("cls");
	printf("************************************************************\n");
	printf("         ���� ���� ���μ����� ���� �Ǿ����ϴ�.\n");
	printf("  ������ ���Ͻô� ���ڸ� �Է����ּ���(10�� ������ ����)\n");
	printf(" �׸� �Է��Ͻð� �����ôٸ� 9999�� �Է��� �ֽø� �˴ϴ�.\n");
	printf("************************************************************\n");
	
	for(i = 0; i<10; i++)
	{
		printf("%d��° ���� : ", i+1);
		scanf("%d", &array[i]);
		count++;
		if(array[i] == 9999)
		{
			count--;
			break;
		}
			
	} 
	
	for(j = 0; j<count; j++){
		min = j;
		for (i = j; i<count; i++)
		{
			if (array[min]>array[i])
				min = i;
				compare_count++;
		}
		
		
		if(array[min] != array[j]){
			swap(temp, array[min], array[j]);
			exchange_count++;
		}
		total_exchange = total_exchange + exchange_count;
		total_compare = total_compare + compare_count;
		printf("\t%dpass : \t",j+1);
		
		for (i = 0; i<count; i++){
			printf("%d ", array[i]);
		}
			printf("\t\t�� Ƚ�� : %d \t��ȯ Ƚ�� : %d\n", compare_count, exchange_count );
		
		exchange_count = 0;
		compare_count = 0;
	}
	
	printf("\t���� �Ϸ� : \t");
	for (i = 0; i<count; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\t\t�� �� Ƚ�� : %d \t��ȯ Ƚ�� : %d\n",total_compare ,total_exchange);
	
	printf("\n\n���ϴ� ���ڸ� ã�� �����ôٸ� 0���� ������ ���͸� ���ּ���.\n");
	printf("������ �����Ŵٸ� �ƹ��ų� �����ð� ���͸� �����ø� �˴ϴ�.\n");
	scanf("%d",&find_start);
	
	
}
