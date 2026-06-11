#include <bits/stdc++.h>
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
	
using namespace std;
const int MAX_N=1e5,MAX_H=1e9;
int N;
ll A,B;
ll h[MAX_N];
bool C(ll x){
	ll cnt=0;
	REP(i,N){
		cnt+=max((h[i]-x*B+A-B-1)/(A-B),0ll);
	}
	return cnt<=x;
}
int main(){
	cin>>N;
	cin>>A>>B;
	REP(i,N){
		cin>>h[i];
	}
	ll lb=-1,ub=1e9;
	while((ub-lb)>1){
		ll mid=(lb+ub)>>1;
		if (C(mid)){
			ub=mid;
		}else{
			lb=mid;
		}
	}
	cout<<ub<<endl;
	return 0;
}