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
const int maxn=100010,INF=1<<30;
int N,a[maxn],mn[maxn],mx[maxn],idmn[maxn],idmx[maxn];
bool vis[maxn];
int main(){
	//freopen("in","r",stdin);
	N=read();read();
	for(int i=1;i<=N;i++)
		a[i]=read();
	mn[0]=INF,mx[N+1]=-INF;
	for(int i=1;i<=N;i++){
		mn[i]=mn[i-1],idmn[i]=idmn[i-1];
		if(a[i]<mn[i])
			mn[i]=a[i],idmn[i]=i;
	}
	for(int i=N;i>=1;i--){
		mx[i]=mx[i+1],idmx[i]=idmn[i+1];
		if(a[i]>mx[i])
			mx[i]=a[i],idmx[i]=i;
	}
	int diff=0;
	for(int i=1;i<N;i++)
		diff=max(diff,mx[i+1]-mn[i]);
	for(int i=1;i<N;i++)
		if(diff==mx[i+1]-mn[i])
			vis[idmx[i+1]]=vis[idmn[i]]=1;
	int ans=0;
	for(int i=1;i<=N;i++)
		ans+=vis[i];
	printf("%d\n",ans/2);
	return 0;
}

