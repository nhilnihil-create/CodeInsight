#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(I,A,B) for(ll I = (A); I < (B); ++I)
const ll INF=1e9+7;
const ll N = 100001;
ll m,n,x[N],y[N],ans=0,xs=0,ys=0,xad[N],yad[N];


int main(){
	cin>>n>>m;
	FOR(i,0,n)cin>>x[i+1];
	FOR(i,0,m)cin>>y[i+1];
	xad[n]=x[n];
	yad[m]=y[m];
	for(ll i=n-1;i>=1;i--){
		xad[i]=x[i]+xad[i+1];
	}
	for(ll i=m-1;i>=1;i--){
		yad[i]=y[i]+yad[i+1];
	}

	FOR(i,1,n+1){
		xs+=xad[i]-x[i]*(n-i+1);
		xs%=INF;
	}
	FOR(i,1,m+1){
		ys+=yad[i]-y[i]*(m-i+1);
		ys%=INF;
	}
	cout<<(xs*ys)%INF<<endl;
	return 0;
}