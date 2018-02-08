//[TeX中的引號/TeX Quotes]
#define IN "/Users/wudongye/Documents/GitHub/COMPUTER_FIRMWARE_DESIGN_LAB/Input/P0305IN.txt"
#define OUT "/Users/wudongye/Documents/GitHub/COMPUTER_FIRMWARE_DESIGN_LAB/Output/P0305OUT.txt"

#include <iostream>
#include <time.h>

using namespace std;
void redir(void);

int main(void)
{
    redir(); //redirection

    char c;
    int flag = 1; //1 for left, 0 for right
    while ((c = getchar()) != EOF)
    {
        if (c == '"')
        {
            printf("%s", flag ? "``" : "''");
            flag = !flag;
        }
        else
        {
            printf("%c", c);
        }
    }
    return 0; //the end...
}

void redir(void)
{
    freopen(IN, "r", stdin);
    freopen(OUT, "w", stdout);
}