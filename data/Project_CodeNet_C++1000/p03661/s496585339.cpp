#include<iostream>
#include<vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
#define P pair<int, int>
using namespace std;
const ll inf = 1e18;
const int maxN = 2e5 + 10;
int n;
ll a[maxN];
 
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    ll ans = inf, total_sum = 0, cur_sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        total_sum += a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        cur_sum += a[i];
        if (i < n)
        {
            ans = min(ans, abs(cur_sum - (total_sum - cur_sum)));
        }
    }
    cout << ans<< endl;
    return 0;
}
  