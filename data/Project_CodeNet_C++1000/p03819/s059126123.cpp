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
int power(int x,int k,int p){int res=1;for(;k;k>>=1,x=1ll*x*x%p)if(k&1)res=1ll*res*x%p;return res;}
const int maxn=3e5+5;
int n,m;
int ans[maxn];
void add(int l,int r){
	ans[l]++;ans[r+1]--;
}
void calc(){
	rep(i,1,m)ans[i]+=ans[i-1];
}
int main(){
	read(n);read(m);
	rep(i,1,n){
		int l,r;read(l);read(r);
		l--;
		for(int j=1,nxtj;j<=l;j=nxtj+1){
			nxtj=min(l/(l/j),r/(r/j));
			if((l/j)!=(r/j))add(j,nxtj);
		}
		add(l+1,r);
	}
	calc();
	rep(i,1,m)printf("%d\n",ans[i]);
	return 0;
}