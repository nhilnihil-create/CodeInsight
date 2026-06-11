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
typedef pair<int, int> P;
#define rep(begin, i, end) for (int i = begin; i < (int)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

int main()
{
    ll N, K;
    cin >> N >> K;
    vector<ll> l(N);
    rep(0, i, N)
    {
        cin >> l.at(i);
    }
    sort(all(l));
    reverse(all(l));
    ll ans = 0;
    rep(0, i, K)
    {
        ans += l.at(i);
    }
    cout << ans << endl;
}