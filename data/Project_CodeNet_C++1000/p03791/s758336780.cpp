#include <bits/stdc++.h>
#define FOR(i,a,b) for(ut i=(a);i<(ut)(b);i++)
#define REP(i,b) FOR(i,0,b)
#define ALL(c) c.begin(),c.end()
#define PB push_back
#define cat //cout << __LINE__ << endl;
using namespace std;
typedef long long LL;
typedef double ld;
typedef LL ut;
typedef vector<ut> VI;
typedef pair<ut,ut> pr;
typedef vector<pr> Vpr;
inline void IN(ut &x){cin >> x;}
inline void INA(ut n,ut x[]){REP(i,n) cin >> x[i];}
inline void INE(ut m,VI edges[]){
	ut a,b;
	REP(i,m){
		cin >> a >> b;
		edges[a].PB(b);
		edges[b].PB(a);
	}
}
inline void INEC(ut m,Vpr edges[]){
	ut a,b,c;
	REP(i,m){
		cin >> a >> b >> c;
		edges[a].PB(pr(c,b));
		edges[b].PB(pr(c,a));
	}
}
const int SIZE=5+5*1e5;
const int INF=10+1e9;
const LL p=7+1e9;
ut N,A[SIZE];

int main(){
	IN(N);
	INA(N,A);
	A[0]=1;
	FOR(i,1,N){
		A[i]=min(A[i-1]+2,A[i]);
	}
	LL ans=1;
	LL need=0;
	FOR(i,1,N){
		need=max(0LL,i*2-A[i-1])/2;
		ans*=i+1-need;
		ans%=p;
	}
	cout << ans << endl;
}