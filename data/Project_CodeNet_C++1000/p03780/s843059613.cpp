#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i,n) for(int i=1;i<=(n);i++)
#define rep0(i,n) for(int i=0;i<(n);i++)

const ll INF=1e9+7;
int n,m,a[5001],l,r;
bool jl[INF];
bool dp[5001];
bool check(int k){
//	cout<<k<<endl;
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	rep(i,n){
		if(i==k){
			continue;
		}
		for(int j=m-a[i];j>=0;j--){
			dp[j+a[i]]|=dp[j];
		}
		/*rep0(j,g){
			cout<<dp[j]<<' ';
		}
		cout<<endl;*/
	}
	ll t=max(m-a[k],m-m);
//	cout<<t<<endl;
	for(int i=t;i<=m-1;i++){
		if(dp[i]){
			return 0; 
		}
	}
	return 1;
}
int has(int a,int b){
	return (a*101+b*37)%INF; 
}
int main()
{
	/*freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);*/
	cin>>n>>m;
	rep(i,n){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	l=1;
	r=n;
	while(l<=r){
		ll mid=(l+r)/2;
		if(check(mid)){
//			cout<<1<<' '<<mid<<endl<<endl;
			l=mid+1;
		}
		else{
//			cout<<0<<' '<<mid<<endl<<endl;
			r=mid-1;
		}
		if(jl[has(l,r)]){
			break;
		}
		jl[has(l,r)]=1;
	}
	cout<<(l+r)/2;
	return 0;
}