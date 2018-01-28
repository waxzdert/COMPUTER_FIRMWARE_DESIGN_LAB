//[猜數字遊戲的提示/Master-Mind Hints]
#define IN "/Users/wudongye/Documents/GitHub/COMPUTER_FIRMWARE_DESIGN_LAB/Input/P0308IN.txt"
#define OUT "/Users/wudongye/Documents/GitHub/COMPUTER_FIRMWARE_DESIGN_LAB/Output/P0308OUT.txt"

#include <iostream>
#include <time.h>

using namespace std;
void redir(void);

int main(void){
    redir(); //redirection
    int n;
    int kase = 0;
    int i;
    int a[1000], b[1000];
    int A, B;
    int d, c1, c2;
    while(scanf("%d", &n) == 1 && n){
        printf("Game %d\n", ++kase);
        for(i=0; i<n; i++){
            scanf("%d", &a[i]);
        }
        while(1){
            A = B = 0;
            for(i=0; i<n; i++){
                scanf("%d", &b[i]);
                if(a[i] == b[i]) A++; //直接統計可得A
            }
            if(b[0] == 0) break; //正常的猜測序列不會有0
            for(d=1; d<=9; d++){
                c1 = c2 =0;
                for(i=0; i<n; i++){ //對每個數字(1-9), 統計二者出現的次數c1和c2
                    if(a[i] == d) c1++;
                    if(b[i] == d) c2++;
                }
                if(c1 <= c2){ //min(c1, c2)就是該數字對B的貢獻
                    B += c1;
                }else{
                    B += c2;
                }
            }
            printf(" (%d,%d)\n", A, B-A); //最後要減去A的部分
        }
    }
    return 0; //the end...
}

void redir(void){
freopen(IN, "r", stdin);
freopen(OUT, "w", stdout);
}