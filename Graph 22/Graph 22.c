#include <stdio.h>
#include <math.h>

int main() {
	int cou, i, tick;
	int n;
	scanf("%d", &n);
	if (n <= 4) {
		printf("n is low");
	}
	else if ((n % 2) == 1) {
		printf("n is odd");
	}
	else {
		i = n/2;
		cou = 1;
		while (cou <= i) {
			for(tick = 1; tick <= n; tick++) {
				if ((tick == i + ((cou-1)%i) + 1) || (tick == i + ((cou)%i) + 1) || (tick == i + ((cou+1)%i) + 1)) {
					printf("1");
				}
				else {
					printf("0");
				}
			}
			printf("\n");
			cou = cou + 1;
		}
		while (cou <= n) {
			for(tick = 1; tick <= n; tick++) {
				if ((tick == ((cou-1)%i) + 1) || (tick == ((cou-2)%i) + 1) || (tick == ((cou-3)%i) + 1)) {
					printf("1");
				}
				else {
					printf("0");
				}
			}
			printf("\n");
			cou = cou + 1;
		}
	}
	scanf("%d", &n);
}