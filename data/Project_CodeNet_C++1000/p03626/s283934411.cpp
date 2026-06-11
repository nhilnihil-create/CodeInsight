#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <climits>
#include <stack>
#include <queue>
#include <set>
#include <cctype>
#include <bitset>
#include <type_traits>

#include <list>
using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define YES(j) cout << (j ? "YES" : "NO") << endl;
#define Yes(j) std::cout << (j ? "Yes" : "No") << endl;
#define yes(j) std::cout << (j ? "yes" : "no") << endl;

int main(void)
{
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    long long ans = 1;
    long long MOD = 1000000007;
    int i = 0;
    while (i < n)
    {
        if (i == 0)
        {
            if (s[i] == t[i])
            {
                ans = 3;
                i++;
            }
            else
            {
                ans = 6;
                i += 2;
            }
        }
        else
        {
            if (s[i] == t[i])
            {
                if (s[i - 1] == t[i - 1])
                {
                    ans = (ans * 2) % MOD;
                }
                i++;
            }
            else
            {
                if (s[i - 1] == t[i - 1])
                {

                    ans = (ans * 2) % MOD;
                }
                else
                {
                    ans = (ans * 3) % MOD;
                }
                i += 2;
            }
        }
    }
    cout << ans << endl;
}