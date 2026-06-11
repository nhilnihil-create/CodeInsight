#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>

using namespace std;
typedef long long ll;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    int left = 0;
    int addleft = 0;
    for (int i = 0; i < n; i++)
    {
        if ('(' == s[i])
        {
            left++;
        }
        else
        {
            if (left > 0)
            {
                left--;
            }
            else
            {
                addleft++;
            }
        }
    }
    string addstr1 = "", addstr2 = "";
    for (int i = 0; i < addleft; i++)
    {
        addstr1 += '(';
    }
    for (int i = 0; i < left; i++)
    {
        addstr2 += ')';
    }
    string ans = addstr1 + s + addstr2;
    cout << ans << endl;
    return 0;
}