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

ll solve(ll x , ll y)
{
    if (y == 0)
    {
        return -x;
    }

    return solve(y , x % y) + (x / y) * 2 * y;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(0);

	ll n , x;
	cin >> n >> x;
	cout << n + solve(n - x , x);
}
