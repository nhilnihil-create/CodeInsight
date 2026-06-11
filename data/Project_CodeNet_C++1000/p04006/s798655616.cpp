#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;

#define LL long long
#define DB double
#define MAXN 1000000
#define MOD 998244353
#define Pr pair<int,int>
#define X first
#define Y second
#define INF 1000000000000000000
#define mem(x,v) memset(x,v,sizeof(x))

LL read(){
	LL x=0,F=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')F=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*F;
}

int n,x;
LL ans,val[MAXN+5];
int a[MAXN+5];

int main(){
	n=read(),x=read(),ans=INF;
	for(int i=0;i<n;i++)a[i]=read();
	for(int i=0;i<n;i++){
		int mval=a[i];
		for(int j=0;j<n;j++){
			mval=min(mval,a[(i-j+n)%n]);
			val[j]+=mval;
		}
	}
	for(int i=0;i<n;i++)
	ans=min(ans,val[i]+1LL*i*x);
	printf("%lld\n",ans);
}