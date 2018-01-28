//[3n+1問題/The 3n+1Problem]
#define IN "/Users/wudongye/Documents/GitHub/COMPUTER_FIRMWARE_DESIGN_LAB/Input/P0205IN.txt"
#define OUT "/Users/wudongye/Documents/GitHub/COMPUTER_FIRMWARE_DESIGN_LAB/Output/P0205OUT.txt"
#include <iostream>
#include <time.h>

using namespace std;
void redir(void);

int main(void){
    redir(); //redirection
    int n, count;
    long long nLong;

    while(scanf("%d", &n) == 1){
        nLong = n; //promotion rule
        count = 0;
            while(nLong > 1){
                ++count;
                if(nLong % 2 == 1){
                    nLong = nLong*3 + 1;
                }else{
                    nLong /= 2;
                }
            }
        printf("%d\n", count);
    }
    return 0; 
}

void redir(void){
freopen(IN, "r", stdin);
freopen(OUT, "w", stdout);
}