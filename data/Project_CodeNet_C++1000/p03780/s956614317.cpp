#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(ll (i) = (0);(i) < (n);++i)
#define REV(i,n) for(ll (i) = (n) - 1;(i) >= 0;--i)
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {REP(WW,n)cerr << v[WW] << ' ';cerr << endl << endl;}
#define SHOW2d(v,WW,HH) {REP(W_,WW){REP(H_,HH)cerr << v[W_][H_] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define MOD 1000000007

typedef long long ll;
typedef pair<ll,ll> P;

int n,k;

bool f(int mid, vector<int> &v){
	bitset<5005> bi(1);
	REP(i,v.size()){
		if(i == mid)continue;
		bi |= (bi << v[i]);
	}
	for(int i = k - v[mid];i < k;i++){
		if(bi[i] == 1)return false;
	}
	return true;
}

int main(){
	
	cin >> n >> k;
	vector<int> v;
	
	REP(i,n){
		int tmp;cin >> tmp;
		if(tmp < k)v.EB(tmp);
	}
	
	sort(ALL(v));
	
	int l = -1;
	int r = v.size();
	while(r - l > 1){
		int mid = (l + r) / 2;
		if(f(mid, v))l = mid;
		else r = mid;
	}
	
	cout << l+1 << endl;
	
	return 0;
}
