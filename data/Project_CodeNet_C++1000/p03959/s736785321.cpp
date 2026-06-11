#include<bits/stdc++.h>
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
typedef pair<P1,ll> P2;
const ll INF=1000000000000000001;
struct edge{int to,cost;};
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};
struct Road{double cost;int a,b;};

ll t[100001],a[100001];

int main() {

	int n;
	cin>>n;
	rep(i,n)cin>>t[i];
	rep(i,n)cin>>a[i];

	ll total=1;
	rep(i,n){
		int f=0;
		if(t[i]!=t[i-1]&&a[i]!=a[i+1]&&t[i]!=a[i])f=1;
		if(t[i]!=t[i-1]&&a[i]<t[i])f=1;
		if(a[i]!=a[i+1]&&t[i]<a[i])f=1;
		if(f==1){
			cout<<"0"<<endl;
			return 0;
		}
		if(t[i]==t[i-1]&&a[i]==a[i+1])total*=min(t[i],a[i]);
		total%=i197;
	}
	cout<<total<<endl;
	return 0;

}
