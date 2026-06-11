#include<bits/stdc++.h>
using namespace std;
const int N=100100;
typedef long long ll;
vector<int>L[N],R[N];
int cnt,n,m,a[N];
ll ans=LLONG_MAX,sum;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	cnt=0;sum=0;
	for(int i=1;i<n;++i){
		R[a[i]].push_back(a[i+1]);
		L[a[i+1]].push_back(a[i]);
		if(a[i+1]<a[i])sum+=a[i+1],cnt++;
		else sum+=a[i+1]-a[i];
	}
	for(int i=1;i<=m;++i){
		ans=min(ans,sum);
		for(int j:L[i])sum--,sum+=(i-j+m)%m,--cnt;
		sum-=cnt;cnt+=R[i].size();
	}
	cout<<ans<<'\n';
	return 0;
}
