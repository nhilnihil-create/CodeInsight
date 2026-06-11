#include<bits/stdc++.h>
#define ri register int
#define rep(i,a,b) for(ri i=(a);i<=(b);++i)
using namespace std;
inline int read(){
	ri x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^'0'),c=getchar();
	return x*f;
}
int n,m,d;
char c[4]={'R','Y','G','B'};
int main()
{
	n=read();m=read();d=read();
	rep(i,1,n){rep(j,1,m){
		ri x=i+j+m,y=i-j+m;
		putchar(c[((x/d)&1)<<1|((y/d)&1)]);
	}puts("");}
	return 0; 
}