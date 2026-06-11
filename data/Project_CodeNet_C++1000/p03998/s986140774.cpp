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
    vector<string> s(3);
    rep(0, i, 3)
    {
        cin >> s.at(i);
    }

    ll t = 0;
    char ans;
    while (1)
    {
        if (s.at(t).size() == 0)
        {
            ans = 'A' + t;
            break;
        }
        char a = s.at(t).at(0);
        s.at(t) = s.at(t).substr(1, s.at(t).size() - 1);
        t = (ll)(a - 'a');
    }

    cout << ans << endl;
}