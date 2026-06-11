#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG_MODE
	#define DBG(n) n;
#else
	#define DBG(n) ;
#endif
#define REP(i,n) for(ll (i) = (0);(i) < (n);++i)
#define rep(i,s,g) for(ll (i) = (s);(i) < (g);++i)
#define rrep(i,s,g) for(ll (i) = (s);i >= (g);--(i))
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {for(int W = 0;W < (n);W++)cerr << v[W] << ' ';cerr << endl << endl;}
#define SHOW2d(v,i,j) {for(int aaa = 0;aaa < i;aaa++){for(int bbb = 0;bbb < j;bbb++)cerr << v[aaa][bbb] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define MOD 1000000007


typedef long long ll;
typedef pair<ll,ll> P;

ll imos[333333];
ll memo[333333];

int main()
{
	ll n,m;cin >> n >> m;
	vector<ll> v(n);
	REP(i,n)cin >> v[i];
	
	REP(i,n-1){
		if(v[i] > v[i+1]){
			DBG(cout << "!" << endl;);
			if(m + v[i+1] - v[i] < 2)continue;
			imos[v[i]+2]++;
			imos[m+v[i]+2]++;
			imos[m+v[i+1]+1]--;
			imos[2*m+v[i+1]+1]--;
			memo[v[i+1]+m+1] -= m+v[i+1]-v[i]-1;
			memo[v[i+1]+2*m+1] -= m+v[i+1]-v[i]-1;
		}
		else{
			if(v[i+1] - v[i] < 2)continue;
			imos[v[i]+2]++;
			imos[v[i]+m+2]++;
			imos[v[i+1]+1]--;
			imos[v[i+1]+m+1]--;
			memo[v[i+1]+1] -= v[i+1]-v[i]-1;
			memo[v[i+1]+m+1] -= v[i+1]-v[i]-1;
		}
	}
	
	DBG(
	cout << "memo" << endl;
	SHOW1d(memo,3*m+10);
	);
	DBG(
	cout << "imos" << endl;
	SHOW1d(imos,3*m+10);
	);

	
	REP(i,3*m+10){
		imos[i+1] += imos[i];
	}
	
	REP(i,3*m+10){
		memo[i+1] += memo[i] + imos[i+1];
	}
	
	ll ans = 0;
	REP(i,3*m+10)ans = max(ans,memo[i]);
	
	ll ret = 0;
	REP(i,n-1){
		if(v[i] > v[i+1]){
			ret += m + v[i+1] - v[i];
		}
		else{
			ret += v[i+1] - v[i];
		}
	}
	
	DBG(
	cout << "memo" << endl;
	SHOW1d(memo,3*m+10);
	);
	DBG(
	cout << "imos" << endl;
	SHOW1d(imos,3*m+10);
	);
	
	cout << ret - ans << endl;
	
	return 0;
}
