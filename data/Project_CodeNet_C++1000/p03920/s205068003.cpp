#include <algorithm>
#include <complex>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)
using namespace std;
typedef long long int lli;
typedef pair<lli, lli> P;
lli MOD = 1000000007;
lli sum(lli a)
{
    return a * (a + 1) / 2;
}

int main()
{
    lli n;
    cin >> n;
    lli up = n, low = 0;
    while (up - low > 1) {
        lli mid = (up + low) / 2;
        if (sum(mid) >= n) {
            up = mid;
        } else {
            low = mid;
        }
    }
    lli s = sum(up) - n;
    for (int i = 1; i <= up; i++) {
        if (i == s)
            continue;
        cout << i << endl;
    }
}
