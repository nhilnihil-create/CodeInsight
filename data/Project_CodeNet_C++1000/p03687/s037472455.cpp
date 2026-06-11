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
    string s;
    cin >> s;
    int N = s.size(), ans = N;
    rep(0, i, 26)
    {
        char a = (char)((int)'a' + i);
        int r = 0, l, d = 0;
        rep(0, j, N)
        {
            if (s.at(j) == a)
            {
                l = j;
                d = max(d, l - r);
                r = l + 1;
            }
        }
        d = max(d, N - r);
        ans = min(ans, d);
    }
    cout << ans << endl;
}