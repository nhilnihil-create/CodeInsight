#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
	while(c<'0'||c>'9'){ if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+c-'0',c=getchar();
	return x*f;
}
int n,a[200005],b[200005],le[200005],ri[200005],vis[200005];
long long ans;
int main(){
	n=read();
	for(int i=1;i<=n;++i) a[i]=read(),b[a[i]]=i;
	for(int i=n;i>=1;--i){
		int pos=b[i];vis[pos]=1;le[pos]=ri[pos]=1;
		if(vis[pos-1]) le[pos]+=le[pos-1];
		if(vis[pos+1]) ri[pos]+=ri[pos+1];
		if(vis[pos-1]) ri[pos-le[pos-1]]+=ri[pos];
		if(vis[pos+1]) le[pos+ri[pos+1]]+=le[pos];
		ans+=(1ll*le[pos]*ri[pos]*i);
	//	cout<<i<<' '<<le[pos]<<' '<<ri[pos]<<' '<<(1ll*le[pos]*ri[pos]*i)<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
