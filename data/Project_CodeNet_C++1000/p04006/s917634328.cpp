#include<bits/stdc++.h>
#define LL long long
#define MAX 2005
using namespace std;
int n,x;
int a[MAX],mn[MAX];
LL calc(int t){
	for (int i=0;i<n;i++) mn[i]=min(mn[i],a[(i-t+n)%n]);
	LL tans=0;
	for (int i=0;i<n;i++) tans+=mn[i];
	return tans;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>x;
	for (int i=0;i<n;i++) cin>>a[i];
	for (int i=0;i<n;i++) mn[i]=1e9+10;
	LL ans=1e18+10;
	for (int i=0;i<n;i++)
	  ans=min(ans,1ll*x*i+calc(i));
	cout<<ans<<'\n';
	return 0;
}