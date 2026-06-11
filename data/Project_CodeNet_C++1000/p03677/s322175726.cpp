#include <set>
#include <map>
#include <queue>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pa;
typedef unsigned int uint;
typedef unsigned long long ull;
#define w1 first
#define ls (x<<1)
#define w2 second
#define ins insert
#define rs (x<<1|1) 
#define mp make_pair
#define pb push_back
#define mid ((l+r)>>1)
#define sqr(x) ((x)*(x))
#define cle(x) ((x).clear())
#define lowbit(x) ((x)&(-x))
#define SZ(x) (int((x).size()))
#define All(x) (x).begin(),(x).end()
#define ms(x,y) memset(x,y,sizeof (x))
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define rep2(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define per(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define Rep(p,x) for(int (p)=head[(x)];(p);(p)=nxt[(p)]) 
#define Rep2(p,x) for(int (p)=cur[(x)];(p);(p)=nxt[(p)])
template<class T>inline void read(T&num){
	num=0;T f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')num=num*10+ch-'0',ch=getchar();
	num*=f;
}
inline int getgcd(int x,int y){if(!x)return y;return getgcd(y%x,x);}
inline int power(int x,int k,int p){int res=1;for(;k;k>>=1,x=(ll)x*x%p)if(k&1)res=(ll)res*x%p;return res;}
const double pi=acos(-1);	
inline void judge(){
	freopen("input.txt","r",stdin);
} 
//********************************head*************************************
const int maxn=1e5+5;
int n,m;
int a[maxn];
ll sum[2][maxn];
void Add(int id,int l,int r,int num){
	if(l>r)return;
	sum[id][l]+=num;
	sum[id][r+1]-=num;
}
int main(){
	read(n);read(m);
	rep(i,1,n)read(a[i]);
	rep(i,2,n){
		if(a[i-1]<a[i]){
			Add(0,1,a[i-1],a[i]-a[i-1]);
			Add(0,a[i]+1,m,a[i]-a[i-1]);
			Add(0,a[i-1]+1,a[i],1+a[i]);
			Add(1,a[i-1]+1,a[i],-1);
		}else{
			Add(0,1,a[i],1+a[i]);
			Add(1,1,a[i],-1);
			Add(0,a[i]+1,a[i-1],m+a[i]-a[i-1]);
			Add(0,a[i-1]+1,m,1+a[i]+m);
			Add(1,a[i-1]+1,m,-1);
		}
	}
	rep(i,1,m)sum[0][i]+=sum[0][i-1],sum[1][i]+=sum[1][i-1];
	ll ans=1e18;
	rep(i,1,m){
		ll res=sum[0][i]+sum[1][i]*i;
		ans=min(ans,res);
	}
	cout<<ans<<endl;
	return 0;
}