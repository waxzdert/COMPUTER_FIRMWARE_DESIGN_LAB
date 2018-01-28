/*
Problem01【3n+1 問題/The 3n+1 Problem】
對於任意大於1 的自然數n，若n 為奇數，則將n 變為3n+1，否則變為n 的
一半。經過若干次這樣的變換，一定會使n 變為1。例如3 → 10 → 5 → 16 → 8 →4 → 2 → 1。
輸入n，輸出變換的次數。n ≤ 109。(Page 2-7, 類似UVa100)
---------------------------------------------------------
輸入：				輸出：
3					7
22					15
987654321			180
*/

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

	while (scanf("%d", &n) == 1) {
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