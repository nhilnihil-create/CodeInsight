#include<bits/stdc++.h>
#include<iostream>
#define rep(i,n) for(int i=0;i<n;++i)
#define rrep(i,n) for(int i=n-1;i>=0;--i)
#define yesno(flg) if(flg){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define MAX_N 1002
#define i197 1000000007

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P1;
typedef pair<int,int> Pi;
typedef pair<double,Pi> Pdi;
typedef pair<ll,int>Pli;
typedef pair<int,ll>Pil;
typedef pair<int,Pil>Piil;
typedef pair<P1,ll> P2;
typedef pair<string,string> Ps;
const ll INF=1000000000000000001;
struct edge{int to,cost;};
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};
struct Road{double cost;int a,b;};
struct pos{
	// 1 変数を入れる;
	int x,y,sx,sy,cost;
};
ll a[16];

int main() {

	int n,k;
	cin>>n>>k;
	rep(i,n)cin>>a[i+1];

	ll ans=INF;
	rep(i,(1<<n)){
		ll t=0,a2[16]={};
		ll ma=0;
		a2[0]=0;
		rep(j,n){
			a2[j+1]=a[j+1];
			if(i&(1<<j)){
				if(a2[j+1]<=ma){
					t+=ma-a2[j+1]+1;
					a2[j+1]+=ma-a2[j+1]+1;
				}
			}
			ma=max(ma,a2[j+1]);
		}
		int s=0;
		ma=0;
		rep(l,n){
			if(a2[l+1]>ma)s++;
			ma=max(ma,a2[l+1]);
		}
		if(s>=k)ans=min(ans,t);
	}
	cout<<ans<<endl;

	return 0;
}
