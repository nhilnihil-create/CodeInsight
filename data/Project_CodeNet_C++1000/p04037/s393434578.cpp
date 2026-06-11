#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<cstdio>
#include<algorithm>
using namespace std;

#define LL long long

inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}
const int INF=9999999;
const int MAXN=100010;

int N; 
int a[MAXN+1];

inline void print(int x){
	if(x==1) puts("First");
	else puts("Second");
}

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	N=read();
	for(int i=1;i<=N;i++) a[i]=read();
	sort(a+1,a+N+1); int cnt=1;
	for(int i=N;i>=1;i--){
		if(a[i-1]<=cnt){
			int x1=(a[i]-cnt)&1; if(cnt==a[i-1]) x1^=1;
			if(a[i-1]<cnt){print(x1); return 0;}
			int j=i-1; while(j>1&&a[j-1]==a[j]) --j;
			int x2=(i-1-j)&1,x3;
			if(((x1^1)|(x2^1))==1) x3=1;
			else x3=0; print(x3); return 0;
		} ++cnt;
	}
	return 0;
}