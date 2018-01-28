//[生成元/Digit Generator]
#define IN "/Users/wudongye/Documents/GitHub/COMPUTER_FIRMWARE_DESIGN_LAB/Input/P0309IN.txt"
#define OUT "/Users/wudongye/Documents/GitHub/COMPUTER_FIRMWARE_DESIGN_LAB/Output/P0309OUT.txt"

#include <iostream>
#include <time.h>

using namespace std;
void redir(void);

int main(void)
{
    redir(); //redirection
    int ans[100001] = {0};
    int m;
    int x, y;
    int T, n;

    for (m = 1; m <= 100000; m++)
    {
        x = y = m;
        while (x > 0)
        {
            y += x % 10;
            x /= 10;
        }
        if (ans[y] == 0)
        {
            ans[y] = m;
        }
    }
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        printf("%d\n", ans[n]);
    }
    return 0; //the end...
}
void redir(void)
{
    freopen(IN, "r", stdin);
    freopen(OUT, "w", stdout);
}