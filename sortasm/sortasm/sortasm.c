#include <tchar.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int array[10];

int _tmain(int argc, _TCHAR* argv[])
{
	int i = 0, j = 0, temp = 0;
	srand(time(NULL));

	for (i = 0; i < 10; i++) {
		array[i] = rand() % 100;
	}

	printf("\t[Original]\n");
	printf("Original: ");
	for (i = 0; i < 10; i++) {
		printf("%d ", array[i]);
	}

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

	printf("\nSorted:   ");
	for (i = 0; i < 10; i++) {
		printf("%d ", array[i]);
	}

	printf("\n");
	system("pause");

	return 0;
}

