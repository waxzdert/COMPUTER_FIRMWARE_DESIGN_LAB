//[WERTYU]
#define IN "/Users/wudongye/Documents/GitHub/COMPUTER_FIRMWARE_DESIGN_LAB/Input/P0306IN.txt"
#define OUT "/Users/wudongye/Documents/GitHub/COMPUTER_FIRMWARE_DESIGN_LAB/Output/P0306OUT.txt"

#include <iostream>
#include <time.h>

using namespace std;
void redir(void);

int main(void){
    redir(); //redirection
    char s[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJHKL;'ZXCVBNM,./"; //注意脫逃字元
    int i, c;
    while((c = getchar()) != EOF){
        for(i=1; s[i] && s[i] != c; i++);
        
        if(s[i]){
            putchar(s[i-1]); //寫入一個字元到標準輸出
        }else{
            putchar(c);
        }
    }
    return 0; //the end...
}

void redir(void){
    freopen(IN, "r", stdin);
    freopen(OUT, "w", stdout);
}