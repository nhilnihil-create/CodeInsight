#include <bits/stdc++.h>
#define N 200005
using namespace std;
int a[N],len,n;
bool f[N];
bool check(int x){
	for(int i=1;i<=len;++i) f[i]=a[i]>=x;
	for(int i=0;i<n-1;++i){
		if((f[n+i]&&f[n+i+1])||(f[n-i]&&f[n-i-1])) return 1;
		else if((!f[n+i]&&!f[n+i+1])||(!f[n-i]&&!f[n-i-1])) return 0;
	}
	return f[1];
}
int main(){
	int l=1,r,i,ans;
	scanf("%d",&n);r=len=2*n-1;
	for(i=1;i<=len;++i) scanf("%d",&a[i]);
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans;
}