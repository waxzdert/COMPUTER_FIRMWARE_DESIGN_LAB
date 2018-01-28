//[環狀序列/Circular Sequenc]
#define IN "/Users/wudongye/Documents/GitHub/COMPUTER_FIRMWARE_DESIGN_LAB/Input/P0310IN.txt"
#define OUT "/Users/wudongye/Documents/GitHub/COMPUTER_FIRMWARE_DESIGN_LAB/Output/P0310OUT.txt"

#include <iostream>
#include <time.h>

using namespace std;
void redir(void);
int less_ans(char *s, int p, int q);

int main(void)
{
    redir(); //redirection
    int T;
    char s[101];
    int ans;
    int n;
    int i;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%s", s);
        ans = 0;
        n = strlen(s);
        for (i = 1; i < n; i++)
        {
            if (less_ans(s, i, ans))
            {
                ans = i;
            }
        }
        for (i = 0; i < n; i++)
        {
            putchar(s[(ans + i) % n]);
        }
        putchar('\n');
    }
    return 0; //the end...
}

void redir(void)
{
    freopen(IN, "r", stdin);
    freopen(OUT, "w", stdout);
}

int less_ans(char *s, int p, int q)
{
    int n;
    int i;
    n = strlen(s);
    for (i = 0; i < n; i++)
    {
        if (s[(p + i) % n] != s[(q + i) % n])
        {
            return s[(p + i) % n] < s[(q + i) % n];
        }
    }
    return 0;
}