#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "ctime"

using namespace std;
typedef long long ll;
typedef pair<int, int> Pint;
typedef pair<ll, ll> Pll;
#define rep(begin, i, end) for (ll i = begin; i < (ll)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 998244353;

int main()
{
    ll N;
    cin >> N;
    vector<ll> A(N), B(N);
    rep(0, i, N)
    {
        cin >> A.at(i) >> B.at(i);
    }

    ll ans = 0;
    for (ll i = N - 1; i >= 0; i--)
    {
        if ((A.at(i) + ans) % B.at(i) != 0)
        {
            ans += B.at(i) - (A.at(i) + ans) % B.at(i);
        }
    }

    cout << ans << endl;
}