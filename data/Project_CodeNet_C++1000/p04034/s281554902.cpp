#include<bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<n;++i)
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
typedef pair<P1,ll> P2;
const ll INF=100000000000000001;
struct edge{int to,cost;};
struct pos{
	int x,y,cost;
};
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};
struct Road{double cost;int a,b;};

ll gcd(ll a2,ll b2){
	ll t;
	while(b2!=0){
		t=a2%b2;
		a2=b2;
		b2=t;
	}
	return a2;
}

int main() {

	int n,m;
	cin>>n>>m;
	int f[100001],f2[100001]={};
	f2[1]=1;

	rep(i,n)f[i+1]=1;
	rep(i,m){
		int x,y;
		cin>>x>>y;
		if(f2[x]==1&&f[x]==1){
			f[y]++;
			f2[y]=1;
			f2[x]=0;
			f[x]--;
		}else if(f2[x]==1){
			f[x]--;
			f[y]++;
			f2[y]=1;
		}else{
			f[x]--;
			f[y]++;
		}
	}
	int t=0;
	rep(i,n){
		if(f2[i+1]==1)t++;
	}
	cout<<t<<endl;

	return 0;
}
