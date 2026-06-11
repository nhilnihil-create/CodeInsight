#include<bits/stdc++.h>
const int MN=100000+5;
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
template<typename T>T&IN(T&in){
	in=0;char c=getchar();int f=1;
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))in=in*10+c-'0',c=getchar();
	return in*=f;
}
int n,m;ll k;
int fr[MN],st[MN],vis[MN];
ll a[MN],ans[MN];
void input(){
	IN(n);
	for(int i=1;i<=n;++i)IN(a[i]),fr[i]=i;
	for(int i=n;i>=1;--i)a[i]-=a[i-1];
	IN(m),IN(k);
	for(int i=1,x;i<=m;++i)IN(x),swap(fr[x],fr[x+1]);
	for(int i=1;i<=n;++i)if(!vis[i]){
		st[0]=0;
		for(int j=i;!vis[j];j=fr[j])vis[j]=1,st[++st[0]]=j;
		for(int j=1;j<=st[0];++j)ans[st[j]]=a[st[(j+k-1)%st[0]+1]];
	}
	for(int i=1;i<=n;++i)ans[i]+=ans[i-1],printf("%lld.0\n",ans[i]);
}
int main(){
	input();
	return 0;
}