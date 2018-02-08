//[救濟金發放/The Dole Queue]
#define IN "/Users/wudongye/Documents/GitHub/COMPUTER_FIRMWARE_DESIGN_LAB/Input/P0405IN.txt"
#define OUT "/Users/wudongye/Documents/GitHub/COMPUTER_FIRMWARE_DESIGN_LAB/Output/P0405OUT.txt"

#include <iostream>
#include <time.h>

using namespace std;
void redir(void);

int a[20];
int n;
int go(int p, int d, int t);

int main(void)
{
    redir(); //redirection
    int i;
    int left;
    int pA, //for A
        pB; //for B
    int k, m;

    while (scanf("%d%d%d", &n, &k, &m) == 3 && n)
    {
        for (i = 1; i <= n; i++)
        {
            a[i] = i;
        }
        left = n;
        pA = n; //預備位置(回撥1步)
        pB = 1;
        while (left)
        {
            pA = go(pA, 1, k);
            pB = go(pB, -1, m);
            printf("%3d", pA);
            left--;

            if (pB != pA)
            {
                printf("%3d", pB);
                left--;
            }
            a[pA] = a[pB] = 0; //pA, pB 離開隊伍

            if (left)
                printf(",");
        }
        printf("\n");
    }
    return 0; //the end...
}

void redir(void)
{
    freopen(IN, "r", stdin);
    freopen(OUT, "w", stdout);
}
//***************************************
/* Work Space*/
int go(int p, int d, int t)
{
    while (t--)
    {
        do
        {
            p = p + d;
            if (p == (n + 1))
                p = 1;
            if (p == 0)
                p = n;
        } while (a[p] == 0); //0 表早已離開隊伍
    }
    return p;
}