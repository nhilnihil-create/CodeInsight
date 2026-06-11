#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
	while(c<'0'||c>'9'){ if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+c-'0',c=getchar();
	return x*f;
}
int n,x,a[2002],mx[2002][2002];
long long ans;
int main(){
	n=read(),x=read();
	for(int i=0;i<n;++i) a[i]=read(),ans+=a[i];
	for(int i=0;i<n;++i){
		mx[i][0]=a[i];
		for(int len=1;len<n;++len)
			mx[i][len]=min(mx[i][len-1],a[(i+len)%n]);
	}
	for(int len=1;len<n;++len){
		long long tmp=0;
		for(int j=0;j<n;++j){
			tmp+=mx[j][len];
		}
		ans=min(ans,tmp+1ll*len*x);
	}
	cout<<ans<<endl;
	return 0;
}
