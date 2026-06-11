#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 310
int ans=0x3f3f3f3f,n,m,a[N][N],cnt[N],flag[N],now[N];
inline char gc(){
    static char *S,*T,buf[1<<16];
    if(T==S){T=(S=buf)+fread(buf,1,1<<16,stdin);if(T==S) return EOF;}
    return *S++;
}
inline int read(){
    int x=0,f=1;char ch=gc();
    while(ch<'0' || ch>'9'){if(ch=='-') f=-1;ch=gc();}
    while('0'<=ch && ch<='9') x=x*10+ch-'0',ch=gc();
    return x*f;
}
int main(){
	n=read();m=read();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			a[i][j]=read();
	for(int i=1;i<=n;++i) now[i]=1;
	for(int i=1;i<=m;++i){
		for(int j=1;j<=m;++j) cnt[j]=0;
		for(int j=1;j<=n;++j){
			while(flag[a[j][now[j]]]) ++now[j];
			cnt[a[j][now[j]]]++;
		}
		int mx=0;
		for(int j=1;j<=m;++j) if(cnt[j]>=cnt[mx]) mx=j;
		flag[mx]=1;
		ans=min(ans,cnt[mx]);
	}
	printf("%d\n",ans);
	return 0;
}