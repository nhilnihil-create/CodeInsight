#include <bits/stdc++.h>
#define rep(i, a) for (int i = (int)0; i < (int)a; ++i)
#define rrep(i, a) for (int i = (int)a - 1; i >= 0; --i)
#define REP(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define RREP(i, a, b) for (int i = (int)a - 1; i >= b; --i)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define popcount __builtin_popcount
using ll = long long;
constexpr ll mod = 1e9 + 7;
constexpr ll INF = 1LL << 60;


template <class T>
inline bool chmin(T &a, T b)
{
	if (a > b)
	{
		a = b;
		return true;
	}
	return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
	if (a < b)
	{
		a = b;
		return true;
	}
	return false;
}

ll gcd(ll n, ll m)
{
	ll tmp;
	while (m != 0)
	{
		tmp = n % m;
		n = m;
		m = tmp;
	}
	return n;
}

ll lcm(ll n, ll m)
{
	return abs(n) / gcd(n, m) * abs(m); //gl=xy
}

using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<ll>a(n);
	rep(i,n)cin>>a[i];
	ll ans=0;
	queue<ll>q;
	rep(i,n){
		if(a[i]%2){
			ans+=a[i]/2;
			a[i]=1;
		}
		else{
			ans+=max(0LL,a[i]/2-1);
			if(a[i]>=2)a[i]=2;
		}
		rep(j,a[i])q.emplace(i+1);
	}
	while(q.size()>1){
		int x=q.front();
		q.pop();
		int y=q.front();
		if(abs(y-x)<=1){
			++ans;
			q.pop();
		}
	}
	cout<<ans<<"\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(15);
	solve();
	return 0;
}
