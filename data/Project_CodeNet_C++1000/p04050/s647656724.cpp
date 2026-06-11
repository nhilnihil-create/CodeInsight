#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=a;i<=b;++i)
#define rpd(i,a,b) for(register int i=a;i>=b;--i)
#define rep1(i,x) for(register int i=head[x];i;i=nxt[i])
typedef long long ll;
const int N=100+5;
using namespace std;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,cnt;int a[N];
int main(){
	n=read();m=read();rep(i,1,m)a[i]=read(),cnt+=a[i]&1;
	if(cnt>2)return puts("Impossible"),0;
	rep(i,2,m-1){
		if(!(a[i]&1))continue;
		if(a[1]&1){swap(a[i],a[m]);break;}
		else swap(a[i],a[1]);
	}
	rep(i,1,m)printf("%d ",a[i]);puts("");
	a[1]+=1;a[m]-=1;if(m==1)a[1]=1,a[m=2]=n-1;if(!a[m])m-=1;
	printf("%d\n",m);rep(i,1,m)printf("%d ",a[i]);
	return 0;
}