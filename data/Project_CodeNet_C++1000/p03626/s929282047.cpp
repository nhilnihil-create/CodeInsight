#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>

using namespace std;
typedef long long ll;

const ll modint = 1000000007;

int main()
{
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    ll ans = 1;
    char last;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            if (s1[i] == s2[i])
            {
                ans = 3;
                last = 'v';
            }
            else
            {
                ans = 6;
                last = 'h';
                i++;
            }
            continue;
        }
        else
        {
            if (s1[i] == s2[i] & 'v' == last)
            {
                ans *= 2;
                ans %= modint;
                last = 'v';
            }
            else if (s1[i] != s2[i] & 'h' == last)
            {
                ans *= 3;
                ans %= modint;
                last = 'h';
                i++;
            }
            else if (s1[i] != s2[i] & 'v' == last)
            {
                ans *= 2;
                ans %= modint;
                last = 'h';
                i++;
            }
            else
            {
                last = 'v';
            }
        }
    }
    cout << ans << endl;
    return 0;
}