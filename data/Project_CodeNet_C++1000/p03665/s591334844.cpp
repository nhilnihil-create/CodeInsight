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
    ll N, P, odd = 0, even = 0;
    cin >> N >> P;
    vector<ll> A(N);
    rep(0, i, N)
    {
        cin >> A.at(i);
        if (A.at(i) % 2 == 0)
        {
            even++;
        }
        else
        {
            odd++;
        }
    }
    if (odd == 0)
    {
        if (P == 0)
        {
            cout << ((ll)1 << even) << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
    else
    {
        cout << ((ll)1 << (N - 1)) << endl;
    }
}