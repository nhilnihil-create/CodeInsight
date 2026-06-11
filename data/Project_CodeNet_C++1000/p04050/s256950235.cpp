#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG_MODE
	#define DBG(n) n;
#else
	#define DBG(n) ;
#endif
#define REP(i,n) for(ll (i) = (0);(i) < (n);++i)
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {for(int W = 0;W < (n);W++)cerr << v[W] << ' ';cerr << endl << endl;}
#define SHOW2d(v,i,j) {for(int aaa = 0;aaa < i;aaa++){for(int bbb = 0;bbb < j;bbb++)cerr << v[aaa][bbb] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define MOD 1000000007

typedef long long ll;
typedef pair<ll,ll> P;

int main(){
	
	int n,m;cin >> n >> m;
	vector<pair<ll,ll>> v;
	int cou = -1;
	REP(i,m){
		int tmp;cin >> tmp;
		if(tmp % 2 == 0)v.PB(MP(0,tmp));
		else {
			v.PB(MP(cou,tmp));
			cou += 2;
		}
	}
	
	if(cou > 3){
		cout << "Impossible" << endl;
		return 0;
	}
	
	sort(ALL(v));
	
	vector<int> ans;
	REP(i,m){
		if(i == 0){
			if(v[i].SE != 1)ans.PB(v[i].SE-1);
			if(m == 1)ans.PB(1);
		}
		else if(i == m-1){
			ans.PB(v[i].SE+1);
		}
		else{
			ans.PB(v[i].SE);
		}
	}
	
	REP(i,m){
		cout << v[i].SE;
		if(i != m-1)cout << ' ';
		else cout << endl;
	}
	
	cout << ans.size() << endl;
	REP(i,ans.size()){
		cout << ans[i];
		if(i != ans.size() - 1)cout << ' ';
		else cout << endl;
	}
	
	
	
	return 0;
}
