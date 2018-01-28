//[團體佇列/Queue]
#define IN "/Users/wudongye/Documents/GitHub/COMPUTER_FIRMWARE_DESIGN_LAB/Input/P0509IN.txt"
#define OUT "/Users/wudongye/Documents/GitHub/COMPUTER_FIRMWARE_DESIGN_LAB/Output/P0509OUT.txt"
#include <iostream>
#include <time.h>
using namespace std;
void redir(void);
#include <map>
#include <queue>
#include <string>
int main(void)
{
    redir(); //redirection
    int t, n, x;
    int i;
    int t0;
    int kase = 0;
    while (scanf("%d", &t) == 1 && t)
    {                       //t: the number of teams, 0 for quit
        map<int, int> team; //block scope
        for (i = 0; i < t; i++)
        {
            scanf("%d", &n); //n: the number of elements of team i
            while (n--)
            {
                scanf("%d", &x); //x: element
                team[x] = i;
            }
        }
        queue<int> teamQueue;
        queue<int> elementQueue[1000]; //elemnetQueue[i]: queue of elements of team i
        printf("Scenario #%d\n", ++kase);
        while (1)
        {
            string cmd; //block scope
            cin >> cmd;
            if (cmd[0] == 'S')
            { //STOP
                break;
            }
            else if (cmd[0] == 'D')
            { //DEQUEUE
                t0 = teamQueue.front();
                cout << elementQueue[t0].front() << endl;
                elementQueue[t0].pop();
                if (elementQueue[t0].empty())
                {
                    teamQueue.pop();
                }
            }
            else if (cmd[0] == 'E')
            { //ENQUEUE
                scanf("%d", &x);
                t0 = team[x];
                if (elementQueue[t0].empty())
                {
                    teamQueue.push(t0);
                }
                elementQueue[t0].push(x);
            }
        }
        printf("\n");
    }
    return 0; //the end...
}
void redir(void)
{
    freopen(IN, "r", stdin);
    freopen(OUT, "w", stdout);
}