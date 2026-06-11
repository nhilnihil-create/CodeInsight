#include<bits/stdc++.h>
using namespace std;
#define all(vec) vec.begin(),vec.end()
typedef long long int ll;
typedef pair<int,int> P;
const ll MOD=1234567;
const ll INF=1000000010;
const ll LINF=4000000000000000010LL;
const int MAX=200010;
const double EPS=1e-3;
int dx[4]={0,1,0,1};
int dy[4]={0,0,1,1};
int main(){
	int n,m;cin>>n>>m;
	int a[100010];for(int i=1;i<=n;i++)cin>>a[i];
	ll sum[250000]={};
	ll ans=0;
	for(int i=1;i<n;i++){
		int l=a[i];int r=a[i+1];
		if(l>=r){
			r+=m;
		}
		ans+=r-l;
		sum[l+1]--;
		sum[r]+=r-l;
		sum[r+1]-=r-l-1;
	}
	for(int i=1;i<=2*m+1;i++){
		sum[i]+=sum[i-1];
	}
	for(int i=1;i<=2*m+1;i++){
		sum[i]+=sum[i-1];
	}
	ll s=ans;
	for(int i=1;i<=m;i++){
		ans=min(ans,s+sum[i]+sum[i+m]);
	}
	cout<<ans<<endl;
    return 0;
}
