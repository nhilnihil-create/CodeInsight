#include<bits/stdc++.h>
#define f(i,s,n)for(register int i=s;i<=n;++i)
#define f2(i,s,n)for(register int i=n;i>=s;--i)
#define N 100010
using namespace std;
int a[N];
int main(){
	ios::sync_with_stdio(false);
	int n,ans=0;
	cin>>n;
	f(i,1,n){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	f(i,2,n){
		if(a[i]==a[i-1])ans++;
	}
	if(ans%2==1)ans++;
	cout<<n-ans<<"\n";
	return 0;
}
