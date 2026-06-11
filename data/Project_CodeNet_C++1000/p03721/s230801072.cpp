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
const int MOD = 1000000007;

int main()
{
    ll N, K;
    cin >> N >> K;
    vector<Pll> p(N);
    ll a, b;
    rep(0, i, N)
    {
        cin >> a >> b;
        p.at(i) = make_pair(a, b);
    }
    sort(all(p));
    ll num = 0;
    rep(0, i, N)
    {
        num += p.at(i).second;
        if (num >= K)
        {
            cout << p.at(i).first << endl;
            return 0;
        }
    }
}