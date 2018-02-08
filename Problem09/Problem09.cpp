//[劊子手遊戲/Hangman Judge]
#define IN "/Users/wudongye/Documents/GitHub/COMPUTER_FIRMWARE_DESIGN_LAB/Input/P0404IN.txt"
#define OUT "/Users/wudongye/Documents/GitHub/COMPUTER_FIRMWARE_DESIGN_LAB/Output/P0404OUT.txt"

#include <iostream>
#include <time.h>
#include <string>

using namespace std;
void redir(void);

int main(void)
{
    redir(); //redirection
    int rnd; //不要用round命名,以免和函數round()混淆
    string s1, s2;
    int win, lose;
    int left;
    int chance;
    int i, j;
    int bad;

    while (scanf("%d", &rnd) == 1 && rnd != -1)
    {
        cin >> s1 >> s2;
        win = lose = 0;
        left = s1.length();
        chance = 7;
        for (i = 0; i < s2.length(); i++)
        {
            bad = 1;
            for (j = 0; j < s1.length(); j++)
            {
                if (s1[j] == s2[i])
                {
                    left--;
                    s1[j] = ' '; //猜一個已經猜過的字母也算錯
                    bad = 0;
                }
            }
            if (bad)
                chance--;
            if (!chance)
                lose = 1;
            if (!left)
                win = 1;
            if (win || lose)
                break;
        }
        printf("Round %d\n", rnd);
        if (win)
        {
            cout << "You win.\n";
        }
        else if (lose)
        {
            cout << "You lose.\n";
        }
        else
        {
            cout << "You chickened out.\n";
        }
    }
    return 0; //the end...
}

void redir(void)
{
    freopen(IN, "r", stdin);
    freopen(OUT, "w", stdout);
}