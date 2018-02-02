#define IN "/Users/wudongye/Documents/GitHub/COMPUTER_FIRMWARE_DESIGN_LAB/Input/P0403IN.txt"
#define OUT "/Users/wudongye/Documents/GitHub/COMPUTER_FIRMWARE_DESIGN_LAB/Output/P0403OUT.txt"

#include <iostream>
#include <time.h>
#include <algorithm>

using namespace std;
void redir(void);

int main(void)
{
    redir(); //redirection
    char stringA[101], stringB[101];
    int countA[26], countB[26];
    int len;
    int i;
    bool ans;
    while (cin >> stringA)
    {
        cin >> stringB;
        for (i = 0; i < 26; i++)
        {
            countA[i] = countB[i] = 0;
        }
        len = strlen(stringA);
        for (i = 0; i < len; i++)
        {
            countA[stringA[i] - 'A']++;
            countB[stringB[i] - 'A']++;
        }
        sort(countA, countA + 26); //sort A[0], A[1], ..., A[25]
        sort(countB, countB + 26); //sort B[0], B[1], ..., B[25]
        ans = true;
        for (i = 0; i < 26; i++)
        {
            if (countA[i] != countB[i])
            {
                ans = false;
                break;
            }
        }
        cout << (ans ? "YES" : "NO") << endl;
    }
    return 0; //the end...
}

void redir(void)
{
    freopen(IN, "r", stdin);
    freopen(OUT, "w", stdout);
}