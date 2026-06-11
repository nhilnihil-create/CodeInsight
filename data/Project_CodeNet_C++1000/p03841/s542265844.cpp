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
const int maxn=505;
int n,a[maxn];
int res[maxn*maxn];
pin v[maxn];
int main(){
	read(n);
	rep(i,1,n)read(a[i]);
	rep(i,1,n)v[i]=mk(a[i],i);
	sort(v+1,v+1+n);
	rep(i,1,n){
		if(res[v[i].w1]){
			puts("No");
			return 0;
		}
		res[v[i].w1]=v[i].w2;
		int left=v[i].w2-1;
		rep(j,1,v[i].w1){
			if(!left)break;
			if(!res[j]){
				res[j]=v[i].w2;
				left--;
			}
		}
		if(left){
			puts("No");
			return 0;
		}
	}
	rep(i,1,n){
		int left=n-i;
		rep(k,a[i]+1,n*n){
			if(!left)break;
			if(!res[k]){
				res[k]=i;
				left--;
			}
		}//assert(left);
		if(left){
			puts("No");
			return 0;
		}
	}
	puts("Yes");
//	printf("%d\n",n);
	rep(i,1,n*n)printf("%d ",res[i]);
	return 0;
}
