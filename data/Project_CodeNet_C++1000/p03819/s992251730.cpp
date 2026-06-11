#pragma GCC target("avx")
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#include<bits/stdc++.h>
#define rep(i,x,y) for (int i=(x);i<=(y);i++)
#define ll long long
#define inf 1000000001
using namespace std;
int read(){
	char ch=getchar();int x=0,op=1;
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') op=-1;
	for (;isdigit(ch);ch=getchar()) x=(x<<1)+(x<<3)+ch-'0';
	return x*op;
}
void write(ll a){
	if (a<0) putchar('-'),a=-a;
	if (a>=10) write(a/10);putchar(a%10+'0');
}
#define N 100005
int n,m;ll ans[N];
int main(){
	n=read(),m=read();
	rep (i,1,n){
		int l=read()-1,r=read(),last,j;
		for (j=1;j<=l;j=last+1){
			last=min(l/(l/j),r/(r/j));//cerr<<last<<' ';
			if (r/j-l/j>0) ans[j]++,ans[last+1]--;
		}
		if (j<=r) ans[j]++,ans[r+1]--;
	}
	rep (i,1,m) ans[i]+=ans[i-1],write(ans[i]),puts("");
	return 0;
}