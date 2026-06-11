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
typedef long long ll;

int main(void)
{
    int n;
    cin >> n;
    int a[n];
    int b[n];
    REP(i, n)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    long long ans = 0;
    long long tmp = 0;
    long long sum = 0;
    // start with plus
    rep(i, 0, n)
    {
        if (i % 2 == 0)
        {
            // プラス
            sum += a[i];
            if (sum <= 0)
            {
                tmp += abs(sum - 1);
                sum = 1;
            }
        }
        else
        {
            // マイナス
            sum += a[i];
            if (sum >= 0)
            {
                tmp += abs(sum + 1);
                sum = -1;
            }
        }
    }
    ans = tmp;
    tmp = 0;
    sum = 0;
    // start with -
    rep(i, 0, n)
    {
        if (i % 2 != 0)
        {
            // +
            sum += a[i];
            if (sum <= 0)
            {
                tmp += abs(sum - 1);
                sum = 1;
            }
        }
        else
        {
            // -
            sum += a[i];
            if (sum >= 0)
            {
                tmp += abs(sum + 1);
                sum = -1;
            }
        }
    }

    ans = min(ans, tmp);
    cout << ans << endl;
}