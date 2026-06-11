#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<bitset>
#include<map>
#include<queue>
#include<vector>
#include<set>
#include<iostream>
#include<string>
#define ll long long
#define N 100005
#define For(i,x,y) for(int i=x;i<=y;i++)
#define Rep(i,x,y) for(int i=x;i>=y;i--)
#define Forn(i,x,y) for(int i=x;i<y;i++)
using namespace std;
ll read(){ll x=0,f=0;char ch=getchar();for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-48;return f?-x:x;}
void write(ll x){if(x<10) putchar(x+48);else write(x/10),putchar(x%10+48);}
void writeln(ll x){if(x<0) putchar('-'),x=-x;write(x);puts(".0");}
int n,m,f[N][65],Q[N];
ll k,a[N];
int main(){
	n=read();For(i,1,n) a[i]=read();
	m=read();k=read();
	Forn(i,1,n) f[i][0]=i,Q[i]=i;
	For(i,1,m){int x=read();swap(f[x][0],f[x-1][0]);}
	For(i,1,61) Forn(j,1,n) f[j][i]=f[f[j][i-1]][i-1];
	For(i,0,61) if(k>>i&1)
		Forn(j,1,n) Q[j]=f[Q[j]][i];
	ll ans=a[1];
	writeln(ans);
	Forn(i,1,n){
		ans+=a[Q[i]+1]-a[Q[i]];
		writeln(ans);
	}
	return 0;
}