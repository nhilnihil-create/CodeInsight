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
vector<int> ans1,ans2;
int num=0;
inline void solve(i64 n){
	if(n==1){
		ans1.pb(num);
		ans2.pb(num);
		num++;
		return;
	}
	if(n&1){
		solve(n/2);
		ans1.pb(num);
		ans2.pb(num);num++;
	}else{
		solve(n-1);
		ans1.insert(ans1.begin(),num);
		ans2.pb(num);
		num++;
	}
}
int main(){
    i64 n;cin>>n;num=1;
    solve(n);
    printf("%d\n",ans1.size()*2);
    for(u32 i=0;i<ans1.size();i++)printf("%d ",ans1[i]);
    for(u32 i=0;i<ans2.size();i++)printf("%d ",ans2[i]);
    return 0;
}
