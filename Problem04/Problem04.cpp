//[迴文詞/Palindromes]
#define IN "/Users/wudongye/Documents/GitHub/COMPUTER_FIRMWARE_DESIGN_LAB/Input/P0307IN.txt"
#define OUT "/Users/wudongye/Documents/GitHub/COMPUTER_FIRMWARE_DESIGN_LAB/Output/P0307OUT.txt"

#include <iostream>
#include <time.h>

using namespace std;
void redir(void);

char *rev = "A   3  HIL JM O   2TUVWXY51SE Z  8 "; //注意空白字元的數目
char *meg[] = {"not a palindrome", "a regular palindrome",
               "a mirrored string", "a mirrored palindrome"};
char mirrored(char ch); //傳回字元的鏡像

int main(void)
{
    redir(); //redirection

    char s[32];
    int length;
    int p, m;
    int i;
    while (scanf("%s", s) == 1)

    {
        length = strlen(s);
        p = m = 1;
        for (i = 0; i < (double)length / 2; i++)
        { //注意轉型
            if (p && s[i] != s[(length - 1) - i])
            { //short-circuit
                p = 0;
            }
            if (m && mirrored(s[i]) != s[(length - 1) - i])
            {
                m = 0;
            }
        }
        printf("%s -- is %s.\n\n", s, meg[m * 2 + p]);
    }
    return 0; //the end...
}
void redir(void)
{
    freopen(IN, "r", stdin);
    freopen(OUT, "w", stdout);
}

char mirrored(char ch)
{ //傳回字元的鏡像
    if (isalpha(ch))
    {
        return rev[ch - 'A'];
    }
    else
    {
        return rev[ch - '0' + 25];
    }
}