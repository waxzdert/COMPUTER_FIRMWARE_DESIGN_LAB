//[訊息解碼/Message Decoding]
#define IN "/Users/wudongye/Documents/GitHub/COMPUTER_FIRMWARE_DESIGN_LAB/Input/P0406IN.txt"
#define OUT "/Users/wudongye/Documents/GitHub/COMPUTER_FIRMWARE_DESIGN_LAB/Output/P0406OUT.txt"

#include <iostream>
#include <time.h>

using namespace std;
void redir(void);
int readcodes(void); //建立編碼表
int readint(int c);  //讀取長度為c的01字串, 並將其轉換為整數
int code[8][128];

int main(void)
{
    redir(); //redirection
    int len;
    int v;
    char ch;

    while (readcodes())
    {
        for (;;)
        {
            len = readint(3);
            if (len == 0)
                break;
            for (;;)
            {
                v = readint(len);
                if (v == (1 << len) - 1)
                    break;
                putchar(code[len][v]);
            }
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

//建立編碼表
int readcodes(void)
{
    int len, i;
    char ch;
    memset(code, 0, sizeof(code)); //清空陣列

    while ((ch = getchar()) == '\n')
        ; //跳過分行符號
    code[1][0] = ch;
    for (len = 2; len <= 7; len++)
    {
        for (i = 0; i < (1 << len) - 1; i++)
        {
            ch = getchar();
            if (ch == EOF)
                return 0;
            if (ch == '\n')
                return 1;
            code[len][i] = ch;
        }
    }
    return 1;
}

//讀取長度為c的01字串, 並將其轉換為整數
int readint(int c)
{
    int v = 0;
    int ch;
    while (c--)
    {
        while ((ch = getchar()) == '\n')
            ; //跳過分行符號
        v = v * 2 + ch - '0';
    }
    return v;
}