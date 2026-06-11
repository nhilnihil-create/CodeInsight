#include<bits/stdc++.h>
#define N 100005
using namespace std;
inline int read(){
	int ans=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))ans=(ans<<3)+(ans<<1)+(ch^48),ch=getchar();
	return ans;
}
int n,t,a[N],mx[N],delta,ans=0;
int main(){
	n=read(),t=read();
	for(int i=1;i<=n;++i)a[i]=read();
	mx[n]=a[n];
	for(int i=n-1;i;--i)mx[i]=max(mx[i+1],a[i]);
	for(int i=1;i<=n;++i){
		if(delta<mx[i]-a[i])delta=mx[i]-a[i],ans=1;
		else if(delta==mx[i]-a[i])++ans;
	}
	cout<<ans;
	return 0;
}