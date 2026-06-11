#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
inline int read(){
	int f=1,ans=0;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return f*ans;
}
const int MAXN=200001;
int n,x,N,a[MAXN],vis[MAXN];
int main(){
	n=read(),x=read();N=2*n-1;
	if(x==1||x==N) {printf("No\n");return 0;}
	a[(N+1)>>1]=x,a[((N+1)>>1)-1]=x+1,a[((N+1)>>1)+1]=x-1;
	vis[x]=vis[x+1]=vis[x-1]=1;
	if(n==2&&x==2){printf("Yes\n1\n2\n3\n");return 0;}
	if(x+2<=N){
		if(((N+1)>>1)+2<=N) a[((N+1)>>1)+2]=x+2,vis[x+2]=1;
		int num=1;
		for(int i=1;i<=N;i++){
			if(a[i]) continue;
			while(vis[num]) num++;
			a[i]=num;vis[num]=1;
		}printf("Yes\n");
		for(int i=1;i<=N;i++) printf("%d\n",a[i]);
		return 0;
	}
	if(x-2>=1){
		if(((N+1)>>1)-2>=1) a[((N+1)>>1)-2]=x-2,vis[x-2]=1;
		int num=1;
		for(int i=1;i<=N;i++){
			if(a[i]) continue;
			while(vis[num]) num++;
			a[i]=num;vis[num]=1;
		}printf("Yes\n");
		for(int i=1;i<=N;i++) printf("%d\n",a[i]);
		return 0;
	}
	return 0;
}