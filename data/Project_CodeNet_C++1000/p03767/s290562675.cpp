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
#define rep(begin, i, end) for (int i = begin; i < (int)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

int main()
{
    ll N;
    cin >> N;
    vector<ll> a(3 * N);
    rep(0, i, 3 * N)
    {
        cin >> a.at(i);
    }
    sort(all(a));
    reverse(all(a));
    ll ans = 0;
    rep(0, i, N)
    {
        ans += a.at(2 * i + 1);
    }
    cout << ans << endl;
}