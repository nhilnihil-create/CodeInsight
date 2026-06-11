#include <iostream>
#include <string>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <iomanip>
#include <vector>
#include <functional>
#include <algorithm>
#include <cstdio>
#include <random>
#include <ctime>
#include <cstdlib>
#include <unordered_map>
#include <string.h>
#include <iostream>

using namespace std;
typedef long long ll;
typedef pair<int, int> Pint;
typedef pair<ll, ll> Pll;
#define rep(begin, i, end) for (ll i = begin; i < (ll)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

int main()
{
    int N;
    cin >> N;
    vector<int> s(N);
    int ans = 0;
    rep(0, i, N)
    {
        cin >> s.at(i);
        ans += s.at(i);
    }
    sort(all(s));
    if (ans % 10 == 0)
    {
        rep(0, i, N)
        {
            if (s.at(i) % 10 != 0)
            {
                ans -= s.at(i);
                cout << ans << endl;
                return 0;
            }
        }
        cout << 0 << endl;
    }
    else
    {
        cout << ans << endl;
    }
}