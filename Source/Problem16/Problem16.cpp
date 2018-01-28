//[反片語/Anagrams]
#define IN "/Users/wudongye/Documents/GitHub/COMPUTER_FIRMWARE_DESIGN_LAB/Input/P0507IN.txt"
#define OUT "/Users/wudongye/Documents/GitHub/COMPUTER_FIRMWARE_DESIGN_LAB/Output/P0507OUT.txt"
#include <iostream>
#include <time.h>
using namespace std;
void redir(void);
#include <string>
#include <vector>
#include <algorithm>
#include <map>
string normalize(string &s);
int main(void)
{
    redir(); //redirection
    string s, n;
    vector<string> words, ans;
    map<string, int> cnt;
    int i;
    while (cin >> s)
    {
        if (s[0] == '#')
        {
            break;
        }
        words.push_back(s);
        n = normalize(s);
        if (!cnt.count(n))
        {
            cnt[n] = 0;
        }
        cnt[n]++;
    }
    for (i = 0; i < words.size(); i++)
    {
        if (cnt[normalize(words[i])] == 1)
        {
            ans.push_back(words[i]);
        }
    }
    sort(ans.begin(), ans.end());
    for (i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    return 0; //the end...
}
void redir(void)
{
    freopen(IN, "r", stdin);
    freopen(OUT, "w", stdout);
}
//把每個單字標準化(轉為小寫字母再按字母排序)
string normalize(string &s)
{
    string ans = s;
    int i;
    for (i = 0; i < s.length(); i++)
    {
        ans[i] = tolower(ans[i]);
    }
    sort(ans.begin(), ans.end());
    return ans;
}