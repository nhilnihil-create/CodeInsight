#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <stack>
#include <queue>
#include <iomanip>
using namespace std;
using ll = long long;
using P = pair<int, int>;
static const ll nmax = 1000000010;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    map<ll, int> dic;
    ll ans = 0;
    for (int i = 0; i < n; ++i)
    {
        ++dic[a[i]];
        if (dic[a[i]] == 1)
        {
            ++ans;
        }
        else
        {
            dic[a[i]] = 0;
            --ans;
        }
        
    }

    cout << ans << endl;
    return 0;
}
