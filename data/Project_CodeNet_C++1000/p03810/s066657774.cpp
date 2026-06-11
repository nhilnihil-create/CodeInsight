#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define forE(i,x) for(int i=head[x];i!=-1;i=ne[i])
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned u32;
typedef pair<int,int> pin;
#define mk(a,b) make_pair(a,b)
#define lowbit(x) ((x)&(-(x)))
#define sqr(a) ((a)*(a))
#define clr(a) (memset((a),0,sizeof(a)))
#define ls ((x)<<1)
#define rs (((x)<<1)|1)
#define mid (((l)+(r))>>1)
#define pb push_back
#define w1 first
#define w2 second
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
inline void judge(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
}
/*******************************head*******************************/
const int maxn=1000005;
int a[maxn],n;
inline void sol(int td){
	if(td==1){
		puts("First");
		exit(0);
	}
	puts("Second");
	exit(0);
}
inline void play(int user){
	int cnt=0,tag=0;
	rep(i,1,n)tag|=a[i]==1;
	rep(i,1,n)cnt+=(a[i]&1);
	if((cnt&1)^(n&1))sol(user);
	if(cnt>1||tag)sol(user^1);
	rep(i,1,n)if(a[i]&1)a[i]--;
	int g=a[1];
	rep(i,1,n)g=__gcd(g,a[i]);
	rep(i,1,n)a[i]/=g;
	play(user^1);
}
int main(){
	// judge();
	read(n);
	rep(i,1,n)read(a[i]);
	if(n>=3)play(1);
	if(n==1){
		sol(a[1]%2==0);
	}
	if(n==2){
		sol(a[1]%2==0||a[2]%2==0);
	}
	return 0;
}
