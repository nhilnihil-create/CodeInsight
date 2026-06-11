#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100005;
int n,a[maxn],id[maxn],ans;
inline int read(){
	int ret=0;bool f=0;char ch=getchar();
	while(ch>'9'||ch<'0') f^=ch=='-',ch=getchar();
	while(ch<='9'&&ch>='0') ret=ret*10+ch-'0',ch=getchar();
	return f?-ret:ret;
}
bool cmp(int x,int y){return a[x]<a[y];}
int main(){
	n=read();
	for (int i=1;i<=n;i++) a[id[i]=i]=read();
	sort(id+1,id+1+n,cmp);
	for (int i=1;i<=n;i++) if((id[i]^i)&1) ans++;
	printf("%d\n",ans>>1);
	return 0;
}