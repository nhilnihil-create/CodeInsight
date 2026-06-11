#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,a[maxn],c,x;
int main(){
	n=read();
	FOR(i,1,n) a[i]=read();
	sort(a+1,a+n+1,greater<int>());
	FOR(i,1,n+1) if(a[i]<i){c=i-1;break;}
	if((a[c]-c)&1) return puts("First"),0;
	FOR(i,c+1,n+1){
		if(a[i]<c) return puts(x&1?"First":"Second"),0;
		x++;
	}
}