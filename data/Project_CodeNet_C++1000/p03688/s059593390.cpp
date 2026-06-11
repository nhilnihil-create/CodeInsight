#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#define gg return puts("No"),0
#define ok return puts("Yes"),0

using namespace std;

inline int read() {
    int res=0,fh=1;
    char ch=getchar();
    while((ch>'9'||ch<'0')&&ch!='-')ch=getchar();
    if(ch=='-')fh=-1,ch=getchar();
    while(ch>='0'&&ch<='9')res=res*10+ch-'0',ch=getchar();
    return fh*res;
}

const int maxn=100010;
const int INF= (1<<30);
int a[maxn],n,maxx=-INF,minn=INF,cnt=0;

inline int Max(int a,int b){
	return a<b?b:a;
}
inline int Min(int a,int b){
	return a>b?b:a;
}

int main()
{
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		maxx=Max(maxx,a[i]);
		if(a[i]<minn) cnt=1;
		else if(a[i]==minn) cnt++;
		minn=Min(minn,a[i]);
	}
	if(maxx>minn+1) gg;
	else if(maxx==minn){
		if(minn==n-1||(minn<<1)<=n) ok;
		else gg; 
	}
	else{
		if(minn<cnt||n-cnt<2*(maxx-cnt)) gg;
		else ok;
	}
}