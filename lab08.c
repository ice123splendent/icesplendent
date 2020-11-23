// EE231002 Lab08. Poker Hands
// 109061101, 王柏涵
// Date: 11/23/2020

#include <stdio.h>
#include <stdlib.h>

void Permu(int A[5]);

int main(void)
{
	int i, j = 10;
	int repeat = 0;
	int temp;
	int A[5];
	int P[9] = {0};						// poker catergory
	
	do {
		for (i = 0; i < 5; i++) {
			A[i] = (rand() / 1000) % 52;
		}
			
		Permu(A);
		
		for (i = 0; (A[i + 1] - A[i]) && i < 5; i++);
		
		printf("check point\n============\n");
		
		if (i < 5) {
			j++;
	//		repeat++;
		} else { 	
			for (i = 0; A[i + 1] - A[i] == 1 && i < 4; i++); 
				if (i == 4) {
					P[0]++;
				} else if (A[0] % 13 == 10 || A[0] % 13 == 11 
										   || A[0] % 13 == 12) {
					P[0]--;
				} else if (i == 3 && A[0] % 13 == 9 && A[4] % 13 == 12) {
					P[0]++;
				}
			
			for (i = 0; i < 5; i++) {
				printf("A[%d] = %d, %d\n", i, A[i], P[0]);
			}

		}
	}while (--j);

	printf("there are %d straight flush\n", P[0]);
	
	return 0;
}

void Permu(int A[5])
{
	int temp;
	int i;

	for (i = 0; i < 5; i++) {
		if (A[i] < A[i - 1]) {
			temp = A[i];
			A[i] = A[i - 1];
			A[i - 1] = temp;
			Permu(A);
		}
	}
	return;
}





