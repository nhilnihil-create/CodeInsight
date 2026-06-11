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
const int INF = 1000000000;
int N, Ma, Mb;
vector<int> a, b, c;

int dp(int curr, int wa, int wb, vector<vector<vector<int>>>& memo) {
	if (wa > 0 && wb > 0 && wb * Ma == wa * Mb) {
		return 0;
	}
	if (curr == N) {
		return INF;
	}

	if (memo[curr][wa][wb] >= 0) {
		return memo[curr][wa][wb];
	}

	int skip = dp(curr + 1, wa, wb, memo);
	int take = dp(curr + 1, wa + a[curr], wb + b[curr], memo) + c[curr];
	int ret = min(skip, take);
	memo[curr][wa][wb] = ret;
	return ret;
}
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
		cin >> N >> Ma >> Mb;
		a = vector<int>(N, 0);
		b = vector<int>(N, 0);
		c = vector<int>(N, 0);
		for (int i = 0; i < N; ++i) {
			cin >> a[i] >> b[i] >> c[i];
		}

		vector<vector<vector<int>>> memo(N, vector<vector<int>>(410, vector<int>(410, -1)));
		int ans = dp(0, 0, 0, memo);
		if (ans == INF) {
			cout << -1 << endl;
		}
		else {
			cout << ans << endl;
		}
	}
	return 0;
}