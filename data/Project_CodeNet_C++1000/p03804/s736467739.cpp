/*
 ▓█████▄  ▄████▄  ▓██   ██▓ ██▓███   ██░ ██ ▓█████  ██▀███
▒██▀ ██▌▒██▀ ▀█   ▒██  ██▒▓██░  ██▒▓██░ ██▒▓█   ▀ ▓██ ▒ ██▒
 ░██   █▌▒▓█    ▄   ▒██ ██░▓██░ ██▓▒▒██▀▀██░▒███   ▓██ ░▄█ ▒
 ░▓█▄   ▌▒▓▓▄ ▄██▒  ░ ▐██▓░▒██▄█▓▒ ▒░▓█ ░██ ▒▓█  ▄ ▒██▀▀█▄
 ░▒████▓ ▒ ▓███▀ ░  ░ ██▒▓░▒██▒ ░  ░░▓█▒░██▓░▒████▒░██▓ ▒██▒
  ▒▒▓  ▒ ░ ░▒ ▒  ░   ██▒▒▒ ▒▓▒░ ░  ░ ▒ ░░▒░▒░░ ▒░ ░░ ▒▓ ░▒▓░
  ░ ▒  ▒   ░  ▒    ▓██ ░▒░ ░▒ ░      ▒ ░▒░ ░ ░ ░  ░  ░▒ ░ ▒░
  ░ ░  ░ ░         ▒ ▒ ░░  ░░        ░  ░░ ░   ░     ░░   ░
    ░    ░ ░       ░ ░               ░  ░  ░   ░  ░   ░
  ░      ░         ░ ░
*/
//focus less on how much problem you should solve within a fixed time and focus more on getting the problem solved and
//learning something from it
#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define rep(i,a,b) for(ll i=a; i<b; i++)
#define per(i,a,b) for(ll i=a; i>=b; i--)
#define ll long long int
#define ld long double
#define vi vector<ll>
#define pi pair<ll,ll>
#define vii vector <pair<ll,ll> >
#define sedes set <ll, greater <ll> >
#define seasc set <ll>
#define pb push_back
#define mkp make_pair
#define ff first
#define ss second
#define MOD 1000000007
#define prec(n) fixed<<setprecision(n)
#define maxpq priority_queue<int>
#define minpq priority_queue<int, vector<int>, greater<int> >
#define umap unordered_map<ll, ll>
#define map map<ll, ll>
#define autoit(x,it) for(auto it = x.begin(); it != x.end(); it++)
#define mems(a, i) memset(a, i, sizeof(a))
#define endl '\n'
#define all(v) v.begin(),v.end()
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define deba(a) cout << #a << " " <<a << endl;
int main()
{
	fast;
#ifndef ONLINE_JUDGE
	freopen("D:\\input.txt", "r", stdin);
	freopen("D:\\output.txt", "w", stdout);
#endif
	int t = 1;
	// cin >> t;
	while (t--)
	{
		ll n, m;
		cin >> n >> m;
		vector<string> a(n), b(m);
		rep(i, 0, n)
		cin >> a[i];
		rep(i, 0, m)
		cin >> b[i];
		// cout << a[0];
		bool ans = true;
		rep(i, 0, n - m)
		{
			rep(j, 0, n - m)
			{
				ans = true;
				ll x = 0;
				rep(l, i, i + m)
				{
					ll y = 0;
					rep(k, j, j + m)
					{
						// deba(a[l][k]);
						if (a[l][k] != b[x][y])
						{
							ans = false;
							break;
						}
						y++;
					}
					x++;
				}
				if (ans)
				{
					cout << "Yes";
					return 0;
				}

			}
		}
		if (ans)
			cout << "Yes";
		else
			cout << "No";
	}
	return 0;
}