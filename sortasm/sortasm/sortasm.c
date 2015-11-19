#include <tchar.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int array[10];

int _tmain(int argc, _TCHAR* argv[])
{
	int i = 0, j = 0, temp = 0;
	srand(time(NULL));
	clock_t start, end;
	double diff;

	for (i = 0; i < 10; i++) {
		array[i] = rand() % 100;
	}

	printf("Original: ");
	for (i = 0; i < 10; i++) {
		printf("%d ", array[i]);
	}

	start = clock();

	for( i = 0; i < 10; i++)
	{
		for( j = 0; j < 10; j++)
		{
			if ( array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}

	end = clock();

	printf("\nSorted:   ");
	for (i = 0; i < 10; i++) {
		printf("%d ", array[i]);
	}
	
	diff = (double)(end - start) / CLOCKS_PER_SEC;
	printf("\nTime: %f seconds\n", diff);

	system("pause");

	return 0;
}

