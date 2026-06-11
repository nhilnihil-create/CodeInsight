#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 505;
int n,m,a,b;
int f(int x, int y){
	x=(x-1)%a+1;y=(y-1)%b+1;
	if(x==1&&y==1)return 1e9-1;
	if(x==a&&y==b)return -1e9;return 0;
}
int main() {
	read(n);read(m);read(a);read(b);
	if(n%a==0&&m%b==0){puts("No");return 0;}
	puts("Yes");rep(i,1,n){rep(j,1,m)printf("%d ",f(i,j));puts("");}
	return 0;
}
