#include <bits/stdc++.h>
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
	
using namespace std;
const int MAX_N=1e5;
const ll INF=1e18;
int N;
ll a[MAX_N*3];
ll sm[2][MAX_N+1];
int main(){
	cin>>N;
	REP(i,N*3){
		cin>>a[i];
	}
	priority_queue<ll,vector<ll>,greater<ll> > pque1;
	REP(i,N){
		sm[0][0]+=a[i];
		pque1.push(a[i]);
	}
	REP(i,N){
		sm[0][1+i]=sm[0][i];
		sm[0][1+i]+=a[N+i];
		pque1.push(a[N+i]);
		sm[0][1+i]-=pque1.top();
		pque1.pop();
	}
	priority_queue<ll> pque2;
	REP(i,N){
		sm[1][N]+=a[2*N+i];
		pque2.push(a[N*2+i]);
	}
	REP(i,N){
		sm[1][N-1-i]=sm[1][N-i];
		sm[1][N-1-i]+=a[2*N-i-1];
		pque2.push(a[N*2-i-1]);
		sm[1][N-1-i]-=pque2.top();
		pque2.pop();
	}
	ll ans=-INF;
	REP(i,N+1){
		ans=max(ans,sm[0][i]-sm[1][i]);
	}
	cout<<ans<<endl;
	return 0;
}
