#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0;
}
typedef long long int ll;

#define EPS (1e-7)
#define INF (1 << 30)
#define LLINF (1LL << 60)
#define PI (acos(-1))
#define MOD (1000000007)
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

ll search(ll n)
{
    ll sum = 0;
    for (ll i = 1; i <= n; i++)
    {
        sum += i;
        if (sum >= n)
        {
            return i;
        }
    }
}

vector<ll> ans;

void dfs(ll n)
{
    if (n == 1 || n == 2)
    {
        ans.push_back(n);
        return;
    }
    ll mx = search(n);
    ll next = n - mx;
    ans.push_back(mx);
    dfs(next);
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    dfs(n);
    for (auto a : ans)
    {
        cout << a << endl;
    }
}