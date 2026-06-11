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

#define rep(i, a, n) for (ll i = a; i < (ll)n; ++i)
#define INF 10e12
#define MOD 1000000007
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))

using namespace std;
bool is_prime(ll N)
{
    for (ll i = 2; i * i <= N; ++i)
    {
        if (N % i == 0)
            return false;
    }
    return true;
}
vector<ll> soinsubunkai(long long N)
{
    vector<ll> tmp;
    ll num = N;
    for (ll i = 2; i * i <= N; ++i)
    {
        if (N % i == 0)
        {
            ll j = N / i;
            if (is_prime(i))
            {
                while (num % i == 0)
                {
                    tmp.push_back(i);
                    num /= i;
                }
            }
            if (is_prime(j))
            {
                while (num % j == 0)
                {
                    tmp.push_back(j);
                    num /= j;
                }
            }
        }
    }
    return tmp;
}

int main(void)
{
    int a[1000];
    rep(i, 0, 1001) a[i] = 0;
    ll n;
    cin >> n;
    rep(i, 2, n + 1)
    {
        vector<ll> tmp = soinsubunkai(i);
        if (is_prime(i))
            a[i]++;
        else
            rep(j, 0, tmp.size()) a[tmp[j]]++;
    }
    ll ans = 1;
    rep(i, 2, 1001) if (a[i] != 0) ans = (ans * (a[i] + 1)) % MOD;
    cout << ans << endl;
}