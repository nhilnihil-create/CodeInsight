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

int mp[222222];
int v[222222];
int n,h;

bool check(int mid){
	REP(i,n){
		if(v[i] >= mid)mp[i] = 1;
		else mp[i] = 0;
	}
	
	DBG(SHOW1d(mp,n);)
		
	if(mp[n/2] == mp[n/2+1] || mp[n/2] == mp[n/2-1]){
		DBG(cout << "!" << endl;)
		return mp[n/2];
	}
	else {
		int ret = 0, mi;
		int L = n/2;
		int R = n/2;
		while(L > 0 && mp[L] != mp[L-1])L--;
		if(L == 0)L--;
		while(R < n && mp[R] != mp[R+1])R++;
		if(R == n)R++;
		DBG(cout << "L R " << L << " " << R << endl;)
		if(R != n+1 && abs(n/2 - L) > abs(n/2 - R)){
			DBG(cout << "!!" << endl;)
			return mp[R];
		}
		else if(L != -1 && abs(n/2 - L) <= abs(n/2 - R)){
			DBG(cout << "!!!" << endl;)
			return mp[L];
		}
		else{
			DBG(cout << "!!!!" << endl;)
			return (mp[n/2] + (h % 2) + 1) % 2;
		}
	}
}

int main(){
	
	cin >> h;
	n = 2 * h - 1;
	REP(i,n)cin >> v[i];
	
	int low_b = 1;
	int up_b = n;
	
	while(abs(up_b - low_b) > 1){
		int mid = (up_b + low_b) / 2;
		if(check(mid))low_b = mid;
		else up_b = mid;
		DBG(cout << " " << mid << endl;)
	}
	
	cout << low_b << endl;
	return 0;
}