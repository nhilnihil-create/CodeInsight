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
    ll N, C, K;
    cin >> N >> C >> K;
    vector<ll> T(N);
    rep(0, i, N)
    {
        cin >> T.at(i);
    }
    sort(all(T));

    ll due = T.at(0) + K, wait = 0, send = 0, ans = 0;
    rep(0, i, N)
    {
        if (due == T.at(i))
        {
            wait++;
            if (wait > C)
            {
                ans += wait / C;
                send += (wait / C) * C;
                wait = wait % C;
            }
            else
            {
                ans++;
                send += wait;
                wait = 0;
            }
            if (send < N)
            {
                due = T.at(send) + K;
            }
        }
        else if (due < T.at(i))
        {
            if (wait > C)
            {
                ans += wait / C;
                send += (wait / C) * C;
                wait = wait % C;
            }
            else
            {
                ans++;
                send += wait;
                wait = 0;
            }
            if (send < N)
            {
                due = T.at(send) + K;
            }
            wait++;
        }
        else
        {
            wait++;
        }
    }

    if (wait != 0)
    {
        ans += (wait + C - 1) / C;
    }
    cout << ans << endl;
}