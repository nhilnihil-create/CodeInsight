#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;

#define pb push_back
#define mp make_pair
#define pf push_front
#define ff first
#define ss second
#define vll vector < ll >
#define vvll vector < vll >
#define vld vector < ld >
#define pll pair < ll,ll > 
#define pld pair < ld,ld > 
#define vpll vector < pll >
#define vpld vector < pld >
#define all(X) X.begin(),X.end()
#define endl "\n"
#define sz(x) ((ll)((x).size()))
vll emptyVector;
const ll MAX = 1e5 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const ld pi = 3.141592653589793238462643383279502884197169399375105;

ll binaryExpo(ll x, ll n)
{
	if(n == 0)
		return 1;
	if(n % 2 == 0)
		return binaryExpo((x*x) % MOD, n/2);
	return (x*binaryExpo((x*x) % MOD, n/2)) % MOD;
}

ll gcd(ll a, ll b)
{
	if(b == 0)
		return a;
	return gcd(b, a % b);
}
/*-------------------------------------------		CODE STARTS FROM HERE		------------------------------------------*/

void solve(void)
{
	int n, k;
	cin >> n >> k;
	ll a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];

	int ans = -1;
	for(int i = 1; i < n; i++)
	{
		if(a[i] + a[i - 1] >= k)
		{
			ans = i;
			break;
		}
	}

	if(ans == -1)
	{
		cout << "Impossible" << endl;
		return ;
	}

	cout << "Possible" << endl;
	for(int i = 1; i < ans; i++)
		cout << i << endl;

	for(int i = n - 1; i > ans; i--)
		cout << i << endl;

	cout << ans << endl;

	

}


int main(void)
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);

	// int t;
	// cin >> t;
	// while(t--)
	{	
		solve();
	}




	return 0;
}