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
#define LLINF 1000000000000000000
#define MOD 1000000007

typedef long long ll;
typedef pair<ll,ll> P;

ll n,l,t,hoge;

ll check(ll a, ll b){
	ll d = (b - a + l) % l;
	if(t*2 >= d + l)return hoge + 2;
	if(t*2 >= d)return hoge + 1;
	return hoge;
}

int main(){
	
	cin >> n >> l >> t;
	hoge = (2 * (t / l)) % l;
	t %= l;
	
	vector<pair<ll, ll>> v;
	vector<pair<pair<ll,ll>, ll>> aft;
	
	REP(i,n){
		ll x,w;cin >> x >> w;
		ll af;
		if(w == 1){
			af = (x + t) % l;
		}
		else {
			af = (x - t + l) % l;
		}
		v.PB(MP(x, w));
		aft.PB(MP(MP(af,-w), i));
	}	
	sort(ALL(aft));

	ll cou = 0;
	for(ll i = 1;i < v.size();i++){
		if(v[0].SE == v[i].SE)continue;
		else{
			if(v[0].SE == 1){
				cou += check(v[0].FI, v[i].FI);
			}
			else{
				cou += (n - 1) * check(v[i].FI, v[0].FI);
			}
			cou %= n;
		}
	}
	
	vector<pair<ll,ll>> ans;
	REP(i,n){
		if(aft[i].SE == 0){
			REP(j,n){
				ans.PB(MP((cou+j)%n,aft[(i+j)%n].FI.FI));
			}
			break;
		}
	}
	
	sort(ALL(ans));
	
	REP(i,n){
		cout << ans[i].SE << endl;
	}
	
	
	return 0;
}