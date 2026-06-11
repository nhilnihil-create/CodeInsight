#include <bits/stdc++.h>
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
	
using namespace std;
const int MAX_N=1e5,MAX_M=1e5;
const ll INF=1e18;
int n,m,a[MAX_N];
typedef pair<ll,ll> P;
int M2;
ll seg[MAX_N<<2],laza[MAX_N<<2];
P lazb[MAX_N<<2];
void lazapro(int k,int a,int b){
	if (laza[k]!=0){
		seg[k]+=laza[k]*(b-a);
		if (b-a>1){
			laza[k*2+1]+=laza[k];
			laza[k*2+2]+=laza[k];
		}
		laza[k]=0;
	}
}
void lazbpro(int k,int a,int b){
	if (lazb[k]!=P(0,0)){
		seg[k]+=(2*lazb[k].first+(b-a-1)*lazb[k].second)*(b-a)/2;
		if (b-a>1){
			lazb[k*2+1].first+=lazb[k].first;
			lazb[k*2+1].second+=lazb[k].second;
			lazb[k*2+2].first+=(b-a)/2*lazb[k].second+lazb[k].first;
			lazb[k*2+2].second+=lazb[k].second;
		}
		lazb[k]=P(0,0);
	}
}
void lazpro(int k,int a,int b){
	lazapro(k,a,b);
	lazbpro(k,a,b);
}
void querya(int l,int r,ll x,int k,int a,int b){
	if (r<=a || b<=l){
		return;
	}
	if (l<=a && b<=r){
		laza[k]+=x;
		return;
	}
	lazpro(k,a,b);
	querya(l,r,x,k*2+1,a,(a+b)/2);
	querya(l,r,x,k*2+2,(a+b)/2,b);
	lazpro(k*2+1,a,(a+b)/2);
	lazpro(k*2+2,(a+b)/2,b);
	seg[k]=seg[k*2+1]+seg[k*2+2];
}
void queryb(int l,int r,ll x,ll y,int k,int a,int b){
	if (r<=a || b<=l){
		return;
	}
	if (l<=a && b<=r){
		lazb[k].first+=x+(a-l)*y;
		lazb[k].second+=y;
		return;
	}
	lazpro(k,a,b);
	queryb(l,r,x,y,k*2+1,a,(a+b)/2);
	queryb(l,r,x,y,k*2+2,(a+b)/2,b);
	lazpro(k*2+1,a,(a+b)/2);
	lazpro(k*2+2,(a+b)/2,b);
	seg[k]=seg[k*2+1]+seg[k*2+2];
}	

int main(){
	cin>>n>>m;
	REP(i,n){
		cin>>a[i];
	}
	M2=1;
	while(M2<m){
		M2<<=1;
	}
	REP(i,n-1){
		int v=(a[i+1]-a[i]+m)%m;
		int u=a[i+1]-v;
		if (u>=0){
			queryb(u,a[i+1],v,-1,0,0,M2);
			if (u>0){
				querya(0,u,v,0,0,M2);
			}
			if (a[i+1]<m){
				querya(a[i+1],m,v,0,0,M2);
			}
		}else{
			queryb(0,a[i+1],a[i+1],-1,0,0,M2);
			queryb(m+u,m,v,-1,0,0,M2);
			querya(a[i+1],m+u,v,0,0,M2);
		}
	}
	{
		int l,d;
		l=0,d=M2;
		REP(i,M2*2-1){
			lazpro(i,l,l+d);
			l+=d;
			if (l==M2){
				d/=2;
				l=0;
			}
		}
	}
	ll ans=INF;
	REP(i,m){
		ans=min(ans,seg[i+M2-1]);
	}
	cout<<ans<<endl;
	return 0;
}