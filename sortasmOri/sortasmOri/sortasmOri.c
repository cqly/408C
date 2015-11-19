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

	__asm
	{
	mov         dword ptr [i],0  
	mov         dword ptr [j],0  
	mov         dword ptr [temp],0  


	mov         dword ptr [i],0  
	jmp         ToLabel1  

ToLabel7:
	mov         eax,dword ptr [i]  
	add         eax,1  
	mov         dword ptr [i],eax  

ToLabel1:
	cmp         dword ptr [i],0Ah  
	jge         ToLabel2

	mov         dword ptr [j],0  
	jmp         ToLabel3 

ToLabel6:
	mov         ecx,dword ptr [j]  
	add         ecx,1  
	mov         dword ptr [j],ecx  

ToLabel3:
	cmp         dword ptr [j],0Ah  
	jge         ToLabel5
	
	mov         edx,dword ptr [i]  
	mov         eax,dword ptr [j]  
	mov         ecx,dword ptr [array+edx*4]  
	cmp         ecx,dword ptr [array+eax*4]  
	jle         ToLabel4

	mov         edx,dword ptr [i]  
	mov         eax,dword ptr [array+edx*4]  
	mov         dword ptr [temp],eax  
			
	mov         ecx,dword ptr [i]  
	mov         edx,dword ptr [j]  
	mov         eax,dword ptr [array+edx*4]  
	mov         dword ptr [array+ecx*4],eax  
			
	mov         ecx,dword ptr [j]  
	mov         edx,dword ptr [temp]  
	mov         dword ptr [array+ecx*4],edx  

ToLabel4:
	jmp        ToLabel6 
	
ToLabel5:
	jmp         ToLabel7 

ToLabel2:
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

