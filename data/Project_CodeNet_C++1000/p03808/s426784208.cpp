#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
int n,a[111111],b[111111],k,x,cnt;
signed main(){
	cin>>n;
	rep(i,n){
		cin>>a[i];
		k+=a[i];
	}
	if(k%((n+1)*n/2)){
		puts("NO");
		return 0;
	}
	k/=((n+1)*n/2);
	rep(i,n){
		if(i)b[i]=a[i]-a[i-1];
		else b[i]=a[0]-a[n-1];
		b[i]-=k;
		if(b[i]>0){
			puts("NO");
			return 0;
		}
	}
	rep(i,n){
		if(b[i]<0){
			if(-(b[i])%n==0)cnt+=-(b[i])/n;
		}
	}
	if(cnt==k)puts("YES");
	else puts("NO");
	return 0;
}
