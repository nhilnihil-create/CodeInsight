#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

typedef long long ll;

#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
#define INF 10e12
#define MOD 1000000000 + 7
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))

using namespace std;

int main(void)
{
    ll n, x;
    cin >> n >> x;
    ll ans = n;
    ll a = x, b = n - x;
    while (b % a != 0)
    {
        ans += 2 * a * (b / a);
        ll tmp = a;
        a = b % a;
        b = tmp;
    }
    ans += a * (2 * (b / a) - 1);
    cout << ans << endl;
}