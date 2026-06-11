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
    ll N, M, K;
    cin >> N >> M >> K;
    rep(0, i, N + 1)
    {
        rep(0, j, M + 1)
        {
            ll sum;
            sum = M * i + N * j - 2 * max(i, j) * min(i, j);
            if (sum == K)
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
}