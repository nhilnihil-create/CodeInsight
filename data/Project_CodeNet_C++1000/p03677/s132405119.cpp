#include<bits/stdc++.h>
using namespace std;
#define all(vec) vec.begin(),vec.end()
typedef long long int ll;
typedef pair<int,int> P;
typedef pair<P,P> PP;
const ll MOD=10000;
const ll INF=1000000010;
const int MAX=100001;
int dx[8]={0,1,0,-1,1,-1,1,-1};
int dy[8]={1,0,-1,0,1,-1,-1,1};
int r[20][100010];
int main(){
	int n,m;
	cin>>n>>m;
	int a[100010];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	ll sum[300010]={};
	ll ans=0;
	for(int i=0;i<n-1;i++){
		int l=a[i];
		int r=a[i+1];
		if(a[i]>=a[i+1]){
			r+=m;
		}
		ans+=r-l;
		sum[l+2]--;
		sum[r+1]+=r-l;
		sum[r+2]-=r-l-1;
	}
	for(int i=1;i<=2*m+3;i++){
		sum[i]+=sum[i-1];
	}
	for(int i=1;i<=2*m+3;i++){
		sum[i]+=sum[i-1];
	}
	ll s=ans;
	for(int i=1;i<=m;i++){
		ans=min(ans,s+sum[i]+sum[i+m]);
	}
	cout<<ans<<endl;
	return 0;
}
