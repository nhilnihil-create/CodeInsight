#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
#define w1 first
#define w2 second
#define ls (x<<1)
#define rs (x<<1|1)
#define pb push_back
#define mid ((l+r)>>1)
#define SZ(x) ((x).size())
#define All(x) (x).begin(),(x).end()
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define rep2(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define per(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define Rep(p,x) for(int (p)=head[(x)];(p);(p)=nxt[(p)])
template<class T>void read(T&num){
	num=0;T f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')num=num*10+ch-'0',ch=getchar();
	num*=f;
}
const int maxn=1e5+5;
ll k,dlt[maxn],x[maxn];
int n,m;
int ans[maxn],a[maxn],tmp[maxn];
int main(){
	read(n);
	rep(i,1,n)read(x[i]);
	rep(i,2,n)dlt[i]=x[i]-x[i-1];
	read(m);read(k);
	rep(i,1,n)a[i]=ans[i]=i;
	rep(i,1,m){
		int x;read(x);
		swap(a[x],a[x+1]);
	}
	while(k){
		if(k&1)rep(i,2,n)ans[i]=a[ans[i]];
		rep(i,2,n)tmp[i]=a[a[i]];
		rep(i,2,n)a[i]=tmp[i];
		k>>=1;
	}
	rep(i,2,n)x[i]=x[i-1]+dlt[ans[i]];
	rep(i,1,n)printf("%lld.0\n",x[i]);
	return 0;
}