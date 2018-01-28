//[醜數/Ugly Numbers](進階)
#define IN "/Users/wudongye/Documents/GitHub/COMPUTER_FIRMWARE_DESIGN_LAB/Input/P0510IN.txt"
#define OUT "/Users/wudongye/Documents/GitHub/COMPUTER_FIRMWARE_DESIGN_LAB/Output/P0510OUT.txt"
#include <iostream>
#include <time.h>
using namespace std;
void redir(void);
#include <queue>
#include <vector>
#include <set>
int main(void)
{
    redir();                      //redirection
    priority_queue<long long> pq; //愈小的(整數)優先權愈低
    set<long long> s;
    int i;
    long long x, x0;
    int coef[] = {2, 3, 5}; //2x, 3x, 5x
    int j;
    int end;

    scanf("%d", &end);
    pq.push(-1);
    s.insert(-1);
    for (i = 1;; i++)
    {
        x = pq.top();
        pq.pop();
        if (i == end)
        {
            cout << "The " << end << "'th ugly number is " << -x << endl;
            break;
        }
        for (j = 0; j < sizeof(coef) / sizeof(int); j++)
        {
            x0 = x * coef[j]; //compute 2x, 3x, 5x
            if (!s.count(x0))
            {
                s.insert(x0);
                pq.push(x0);
            }
        }
    }
    return 0; //the end...
}
void redir(void)
{
    freopen(IN, "r", stdin);
    freopen(OUT, "w", stdout);
}