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
    long long n, a, b;
    cin >> n >> a >> b;
    long long ans = 0;
    int pos = 0;
    REP(i, n)
    {
        int x;
        cin >> x;
        if (i == 0)
        {
            pos = x;
        }
        else
        {
            ans += min(a * (x - pos), b);
            pos = x;
        }
    }
    cout << ans << endl;
}