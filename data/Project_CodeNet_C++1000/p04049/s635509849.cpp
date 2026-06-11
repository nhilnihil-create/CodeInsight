#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pll pair <ll , ll>

#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define mp make_pair

#define X first
#define Y second

#define LB(x) ((x) & -(x))
#define BIT(a , b) (((a)>>(b)) & 1)

const ll maxn = 2e3 + 10;

vector <ll> vertex[maxn];

ll dfs(ll v , ll k , ll p)
{
    if (k < 0) return 0;
    if (k == 0) return 1;

    ll sum = 1;
    for (ll i = 0; i < vertex[v].size(); i++)
    {
        if (vertex[v][i] != p)
        {
            sum += dfs(vertex[v][i] , k - 1 , v);
        }
    }

    return sum;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(0);

	ll n , k , ans = 0;
	cin >> n >> k;

	for (ll i = 0; i < (n - 1); i++)
    {
        ll v , u;
        cin >> v >> u;

        vertex[v].pb(u);
        vertex[u].pb(v);
    }

	for (ll i = 1; i <= n; i++)
    {
        ll res = 1 , w = 0;
        for (ll j = 0; j < vertex[i].size(); j++)
        {
            ll x = dfs(vertex[i][j] , (k / 2) - 1 , i);
            if (k & 1) w = max(w , dfs(vertex[i][j] , (k / 2) , i) - x);
            res += x;
        }
        res += w;
        ans = max(ans , res);
    }

    cout << n - ans;
}

/*
10 7
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
*/
