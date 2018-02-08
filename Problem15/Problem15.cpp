//[安迪的第一個字典/Andy’s First Dictionary]
#define IN "/Users/wudongye/Documents/GitHub/COMPUTER_FIRMWARE_DESIGN_LAB/Input/P0506IN.txt"
#define OUT "/Users/wudongye/Documents/GitHub/COMPUTER_FIRMWARE_DESIGN_LAB/Output/P0506OUT.txt"
#include <iostream>
#include <time.h>
using namespace std;
void redir(void);
#include <string>
#include <sstream>
#include <set>
int main(void)
{
    redir(); //redirection
    string s, buf;
    int i;
    set<string> dict;
    set<string>::iterator it; //反覆運算器
    while (cin >> s)
    { //遇EOF結束
        for (i = 0; i < s.length(); i++)
        {
            if (isalpha(s[i]))
            {
                s[i] = tolower(s[i]);
            }
            else
            {
                s[i] = ' '; //把非字母的字元變成空格
            }
        }
        stringstream ss(s); //block scope
        while (ss >> buf)
        {
            dict.insert(buf);
        }
    }
    for (it = dict.begin(); it != dict.end(); ++it)
    { //列出所有的元素
        cout << *it << endl;
    }
    return 0; //the end...
}
void redir(void)
{
    freopen(IN, "r", stdin);
    freopen(OUT, "w", stdout);
}
