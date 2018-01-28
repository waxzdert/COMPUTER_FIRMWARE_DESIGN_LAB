//[集合堆疊電腦/The SetStack Computer]
#define IN "/Users/wudongye/Documents/GitHub/COMPUTER_FIRMWARE_DESIGN_LAB/Input/P0508IN.txt"
#define OUT "/Users/wudongye/Documents/GitHub/COMPUTER_FIRMWARE_DESIGN_LAB/Output/P0508OUT.txt"
#include <iostream>
#include <time.h>
using namespace std;
void redir(void);
#include <string>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <algorithm> //set_union(), set_intersection()
#include <iterator>  //inserter()
typedef set<int> Set;
map<Set, int> IdCache; //Set -> ID
vector<Set> SetCache;  //ID -> Set
#define ALL(x) x.begin(), x.end()
#define INS(x) inserter(x, x.begin())
int ID(Set x);
int main(void)
{
    redir(); //redirection
    /* Work Space*/
    int T, n;
    stack<int> s; //SetID
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        while (n--)
        {
            string op; //block scope
            cin >> op;
            if (op[0] == 'P')
            {          //PUSH
                Set x; //block scope
                s.push(ID(x));
            }
            else if (op[0] == 'D')
            { //DUP
                s.push(s.top());
            }
            else
            {
                Set x1, x2, x; //block scope
                x1 = SetCache[s.top()];
                s.pop();
                x2 = SetCache[s.top()];
                s.pop();
                if (op[0] == 'U')
                { //UNION
                    set_union(ALL(x1), ALL(x2), INS(x));
                }
                else if (op[0] == 'I')
                { //INTERSECT
                    set_intersection(ALL(x1), ALL(x2), INS(x));
                }
                else
                { //ADD
                    x = x2;
                    x.insert(ID(x1));
                }
                s.push(ID(x));
            }
            cout << SetCache[s.top()].size() << endl;
        }
        cout << "***" << endl;
    }
    return 0; //the end...
}
void redir(void)
{
    freopen(IN, "r", stdin);
    freopen(OUT, "w", stdout);
}
int ID(Set x)
{
    if (IdCache.count(x))
    {
        return IdCache[x];
    }
    SetCache.push_back(x);
    return IdCache[x] = SetCache.size() - 1;
}