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
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 505*505;
int n,a[N],x[N],q[N],sz,id[N];
bool cmp(int a, int b){
	return x[a]<x[b];
}
void GG(){puts("No");exit(0);}
int main() {
	read(n);rep(i,1,n)read(x[i]),a[x[i]]=i;
	rep(i,1,n)id[i]=i;sort(id+1,id+n+1,cmp);
	rep(i,1,n)rep(j,1,id[i]-1)q[++sz]=id[i];
	rep(i,1,n)rep(j,id[i]+1,n)q[++sz]=id[i];
	int f=1;rep(i,1,n*n)if(!a[i])a[i]=q[f++];
	
	static int buc[N];rep(i,1,n*n)buc[a[i]]++;
	rep(i,1,n)if(buc[i]!=n)GG();
	rep(i,1,n){
		int cnt=0;rep(j,1,x[i])cnt+=a[j]==i;
		if(cnt!=i)GG();
	}
	puts("Yes");
	rep(i,1,n*n)printf("%d ",a[i]);
	return 0;
}
