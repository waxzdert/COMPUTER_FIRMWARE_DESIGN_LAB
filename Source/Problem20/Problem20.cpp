//[UNIX ls 指令/UNIX ls]
#define IN "/Users/wudongye/Documents/GitHub/COMPUTER_FIRMWARE_DESIGN_LAB/Input/P0512IN.txt"
#define OUT "/Users/wudongye/Documents/GitHub/COMPUTER_FIRMWARE_DESIGN_LAB/Output/P0512OUT.txt"
#include <iostream>
#include <time.h>
#include <math.h>
using namespace std;
void redir(void);
#include <string>
#include <algorithm>
void print(string s, int len, char extra);
int main(void)
{
    redir(); //redirection
    int n;
    int M;
    string filename[100];
    int i;
    int cols, rows;
    int r, c;
    int id;
    while (scanf("%d", &n) == 1)
    {
        M = 0;
        for (i = 0; i < n; i++)
        {
            cin >> filename[i];
            M = max(M, (int)filename[i].length()); //注意轉型: (int)filename[i].length()
        }
        cols = (60 - M) / (M + 2) + 1;      //常數60來自題目: 每列60個字元
        rows = (int)ceil(double(n) / cols); //注意轉型
        print("", 60, '-');
        cout << endl;
        sort(filename, filename + n);
        for (r = 0; r < rows; r++)
        {
            for (c = 0; c < cols; c++)
            {
                id = c * rows + r; //column-major
                if (id < n)
                {
                    print(filename[id], c == cols - 1 ? M : M + 2, ' ');
                }
            }
            cout << endl;
        }
    }
    return 0; //the end...
}
void redir(void)
{
    freopen(IN, "r", stdin);
    freopen(OUT, "w", stdout);
}
//輸出字串s, 長度不足len時補字元extra
void print(string s, int len, char extra)
{
    int i;
    cout << s;
    for (i = 0; i < len - s.length(); i++)
    {
        cout << extra;
    }
}