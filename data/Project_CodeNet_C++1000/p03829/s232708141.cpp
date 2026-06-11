#include<bits/stdc++.h>
#include<iomanip>
#include <numeric>
#define rep(i,n) for(int i=0;i<n;++i)
#define rrep(i,n) for(int i=n-1;i>=0;--i)
#define yesno(flg) if(flg){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define MAX_N 1002
#define i197 1000000007
#define KETA 40

using namespace std;

typedef long long  ll;
typedef pair<ll,ll> P1;
typedef pair<string,int> Pi;
typedef pair<double,Pi> Pdi;
typedef pair<ll,int>Pli;
typedef pair<Pi,int> P2;
const ll INF=1000000000000000001;
struct edge{int to,cost;};
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};
struct Road{double cost;int a,b;};

ll t[100001]={};

int main() {

	int n;
	ll x[100001];
	ll a,b;
	cin>>n>>a>>b;
	cin>>x[0];

	ll ans=0;
	for(int i=1; i<n; i++){
		cin>>x[i];
		t[i]=(x[i]-x[i-1])*a;
		t[i]=min(t[i],b);
		ans+=t[i];
	}
	cout<<ans<<endl;
	return 0;

}
