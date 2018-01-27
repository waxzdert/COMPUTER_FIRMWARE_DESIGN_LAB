#define IN "P0205IN.txt"
#define OUT "P0205OUT.txt"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "stdafx.h"

using namespace std;
void redir(void); //Redirection

int main(void) {
	int n, count;
	long long nLong;

	while (scanf_s("%d", &n) == 1) {
		nLong = n;

		count = 0;
		while (nLong > 1) {
			++count;
			if (nLong % 2 == 1) {
				nLong = nLong * 3 + 1;
			}
			else {
				nLong /= 2;
			}
		}
		printf("%d\n", count);
	}
	freopen("CON", "r", stdin); //Cancel the redirect
	freopen("CON", "w", stdout);
	printf("Time used = %.2f\n", (double)clock() / CLK_TCK); //Return program execution time
	system("pause");
	return 0;
}

void redir(void)
{
	freopen(IN, "r", stdin);
	freopen(OUT, "w", stdout);
}