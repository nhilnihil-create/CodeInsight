#include<bits/stdc++.h>
using namespace std;

const int N=100100;
typedef long long ll;
pair<int,int>a[N];
int n;
ll ans[N];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i].first,a[i].second=i;
	sort(a+1,a+n+1);
	for(int i=n,mn=a[n].second;i;--i){
		ans[mn]+=(ll)(a[i].first-a[i-1].first)*(n-i+1);
		mn=min(mn,a[i-1].second);
	}
	for(int i=1;i<=n;++i)cout<<ans[i]<<'\n';
	return 0;
}
