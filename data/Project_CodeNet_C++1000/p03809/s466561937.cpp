#include <bits/stdc++.h>

using namespace std;

//#define DEBUG_MODE
#ifdef DEBUG_MODE
	#define _(QQQ) QQQ;
#else
	#define _(QQQ) ;
#endif
#define DBG cerr << '!' << endl;
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

ll n;
ll a[111111];
vector<vector<ll> > v(111111);

ll dfs(ll now,ll prev){
	_(cout << "dfs " << now << ' ' << prev << endl;)
	if(v[now].size() == 1){
		return a[now];
	}
	ll sum = 0;
	vector<ll> seica;
	REP(i,v[now].size()){
		if(v[now][i] == prev)continue;
		seica.PB(dfs(v[now][i],now));
	}
	REP(i,seica.size()){
		if(seica[i] == -1)return -1;
		sum += seica[i];
	}
	_(cout << "A SUM " << a[now] << ' ' << sum << endl;)
	if(seica.size() == 1){
		if(a[now] != sum){
			return -1;
		}
		return a[now];
	}
	ll ma = 0;
	REP(i,seica.size())ma = max(ma,seica[i]);
	ll x = sum - a[now];
	if(x < 0 || x > sum - ma || x > a[now] || (a[now] == 0 && sum > 0))return -1;
	return a[now] - x;
}
	

bool check(int num){
	_(cout << "num is " << num << endl;)
	ll sum = 0;
	vector<ll> seica;
	REP(i,v[num].size()){
		seica.PB(dfs(v[num][i],num));
		_(cout << seica[i] << endl;)
		if(seica[i] == -1)return false;
		sum += seica[i];
	}
	_(
	cout << "IN CHECK SUM IS " << sum << " A  " << a[num] << endl;
	SHOW1d(seica,seica.size());
	)
	if(sum % 2 != 0){
		return false;
	}
	REP(i,seica.size()){
		if(sum / 2 < seica[i]){
			return false;
		}
	}
	return (sum / 2) == a[num];
}

int main()
{
	cin >> n;
	REP(i,n)cin >> a[i];
	REP(i,n-1){
		ll x,y;cin >> x >> y;
		x--;y--;
		v[x].PB(y);
		v[y].PB(x);
	}
	if(n == 2){
		if(a[0] == a[1]){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
		return 0;
	}
	
	REP(i,n){
		if(v[i].size() > 1){
			if(check(i)){
				cout << "YES" << endl;
			}
			else{
				cout << "NO" << endl;
			}
			return 0;
		}
	}
	
	return 0;
}