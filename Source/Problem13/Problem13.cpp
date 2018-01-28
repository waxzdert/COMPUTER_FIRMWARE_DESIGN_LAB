//[大理石在那兒？/Where is the Marble?]
#define IN "/Users/wudongye/Documents/GitHub/COMPUTER_FIRMWARE_DESIGN_LAB/Input/P0504IN.txt"
#define OUT "/Users/wudongye/Documents/GitHub/COMPUTER_FIRMWARE_DESIGN_LAB/Output/P0504OUT.txt"
#include <iostream>
#include <time.h>
using namespace std;
void redir(void);
#include <vector>
int main(void)
{
    redir(); //redirection
    int kase = 0;
    int N, Q;
    int i;
    int Z;
    int p;
    while (scanf("%d %d", &N, &Q) == 2 && N)
    {
        vector<int> a; //block scope
        printf("CASE# %d:\n", ++kase);
        for (i = 0; i < N; i++)
        {
            scanf("%d", &Z);
            a.push_back(Z);
        }
        sort(a.begin(), a.end());
        while (Q--)
        {
            scanf("%d", &Z);
            p = lower_bound(a.begin(), a.end(), Z) - a.begin(); //lower_bound() 尋找大於或等於Z的第一個位置
            if (p < a.size() && a[p] == Z)
            {
                printf("%d found at %d\n", Z, p + 1);
            }
            else
            {
                printf("%d not found\n", Z);
            }
        }
    }
    return 0; //the end...
}
void redir(void)
{
    freopen(IN, "r", stdin);
    freopen(OUT, "w", stdout);
}