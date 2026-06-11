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

	ll x,y;
	cin>>x>>y;

	if(y<0&&x>0)cout<<1+labs(x-labs(y))<<endl;
	else if(y>0&&x<0)cout<<1+labs(labs(x)-y)<<endl;
	else if(x<=y)cout<<labs(labs(y)-labs(x))<<endl;
	else if(x>y&&x!=0&&y!=0)cout<<2+labs(labs(y)-labs(x))<<endl;
	else cout<<1+labs(labs(y)-labs(x))<<endl;

	return 0;
}
