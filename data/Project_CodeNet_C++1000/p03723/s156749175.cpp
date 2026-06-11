#include <bits/stdc++.h>
using namespace std;
#define int long long
// Big two primes
#define X 1001100011100001111ll
#define mod 1000000007
#define ll long long
#define all(a) a.begin(),a.end()
#define sortall(a) sort(all(a))
#define fo(i, n) for (int i = 0; i < n; i++)
#define fo1(i, n) for (int i = 1; i <= n; i++)
#define loop(i,a,b) for (int i = a; i < b; i++)
#define nloop(i,a,b) for (int i = a ; i>=b;i--)
#define tc(t) int t; cin >> t; while (t--)
#define arrip(a,n)  int a[n]; fo(i, n) cin >> a[i];
#define arrop(n)  fo(i,n) cout<<a[i]<<" ";
#define pb push_back
#define mp make_pair
#define itr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626

#define fio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define rr return 0
#define prec(n) fixed<<setprecision(n)
#define maxpq priority_queue<int>
#define minpq priority_queue<int, vector<int>, greater<int> >
#define inf (int)(1e18)
#define ini(a, i) memset(a, i, sizeof(a))
#define vi vector<int>
#define fi first
#define se second
#define endl "\n"
#define pi pair<int, int>
#define vpi vector<pi>
#define sz(s) s.size()
#define bits(n) __builtin_popcount(n)//Count set bits

const int MAXN = (int)((1e5) + 100);
int gcd(int a, int b) { if (a == 0) return b; return gcd(b % a, a);}
int max(int a, int b) {if (a > b) return a; else return b;}
int min(int a, int b) {if (a < b) return a; else return b;}


bool even(int n)
{
	if (n & 1)
		return false;
	return true;
}
int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("codechefi.txt", "r", stdin);
	freopen("codechefo.txt", "w", stdout);
#endif
	fio;

	int a, b, c;
	cin >> a >> b >> c;
	int cnt = 0;
	while (even(a) && even(b) && even(c))
	{
		int a1, b1, c1;
		a1 = a;
		b1 = b;
		c1 = c;
		a = (c1 / 2) + (b1 / 2);
		b = (a1 / 2) + (c1 / 2);
		c = (a1 / 2) + (b1 / 2);
		if (a == a1 && b == b1 && c == c1) {
			cout << "-1" << endl;
			return 0;
		}
		cnt++;

	}
	cout << cnt << endl;
}