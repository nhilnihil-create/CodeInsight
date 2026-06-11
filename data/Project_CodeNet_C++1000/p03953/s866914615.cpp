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
#define SHOW1d(v,n) {for(int WWW = 0;WWW < (n);WWW++)cerr << v[WWW] << ' ';cerr << endl << endl;}
#define SHOW2d(v,i,j) {for(int aaa = 0;aaa < i;aaa++){for(int bbb = 0;bbb < j;bbb++)cerr << v[aaa][bbb] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define MOD 1000000007

typedef long long ll;
typedef pair<ll,ll> P;

int x[80][111111];
double diff[111111];

int main(){
	
	ll n;cin >> n;
	vector<ll> v(n);
	REP(i,n)cin >> v[i];
	ll m,k;cin >> m >> k;
	vector<ll> a(m);
	REP(i,m){
		cin >> a[i];
	}
	
	REP(i,n)x[0][i] = i;
	REP(i,m)swap(x[0][a[i]],x[0][a[i]-1]);
	
	for(int i = 0;i < 79;i++){
		REP(j,n){
			x[i+1][j] = x[i][x[i][j]];
		}
	}
	
	for(int i = 1;i < n;i++){
		int tmp = i;
		for(ll j = 0;j < 60;j++){
			if(k & (1LL << j)){
				tmp = x[j][tmp];
			}
		}
		DBG(cout << "tmp " << i << ' ' << tmp << endl;)
		diff[i] = v[tmp] - v[tmp-1];
	}

	DBG(cout << "x" << endl;REP(i,10)SHOW1d(x[i],n);)
	DBG(cout << "diff" << endl;SHOW1d(diff,n););
	
	diff[0] = v[0];
	cout << v[0] << endl;
		
	for(int i = 1;i < n;i++){
		diff[i] += diff[i-1];
		cout << Decimal << diff[i] << endl;
	}
	
	return 0;
}
