#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<utility>
#include<iomanip>
using namespace std;
int read(){
    int xx=0,ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=xx*10+ch-'0';ch=getchar();}
    return xx*ff;
}
long long READ(){
    long long xx=0,ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=xx*10+ch-'0';ch=getchar();}
    return xx*ff;
}
char one(){
	char ch=getchar();
	while(ch==' '||ch=='\n')
		ch=getchar();
	return ch;
}
const int maxn=100010;
int N,L,Q;
int a[maxn],f[maxn][21];
int main(){
	//freopen("in","r",stdin);
	N=read();
	for(int i=1;i<=N;i++)
		a[i]=read();
	L=read(),Q=read();
	for(int i=1;i<=N;i++)
		f[i][0]=lower_bound(a+1,a+1+N,a[i]+L+1)-a-1;
	for(int j=1;j<=20;j++)
		for(int i=1;i<=N;i++)
			f[i][j]=f[f[i][j-1]][j-1];
	while(Q--){
		int x=read(),y=read(),ans=0;
		if(x>y)swap(x,y);
		for(int i=20;i>=0;i--)
			if(f[x][i]<y)
				x=f[x][i],ans+=(1<<i);
		if(x<y)
			ans++;
		printf("%d\n",ans);
	}
	return 0;
}

