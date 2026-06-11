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
const int maxn=105;
int a[maxn],n,m;
vector<int> odd,even;
int main(){
	read(n);read(m);
	rep(i,1,m)read(a[i]);
	if(m==1){
		cout<<a[1]<<endl;
		if(a[1]==1){
			cout<<1<<endl;
			cout<<1<<endl;
			return 0;
		}
		cout<<2<<endl;
		cout<<a[1]-1<<' '<<1<<endl;
		return 0;
	}
	rep(i,1,m)if(a[i]&1)odd.pb(a[i]);else even.pb(a[i]);
	if(odd.size()>2){
		puts("Impossible");return 0;
	}
	vector<int> ans;
	if(odd.size()){
		ans.pb(odd[odd.size()-1]);odd.pop_back();
	}
	for(int v:even)ans.pb(v);
	if(odd.size()){
		ans.pb(odd[odd.size()-1]);odd.pop_back();
	}
	vector<int> res;
	res=ans;
	res[0]--;res[res.size()-1]++;
	reverse(res.begin(),res.end());
	if(res[res.size()-1]==0)res.pop_back();
	reverse(res.begin(),res.end());
	for(int v:ans){
		printf("%d ",v);
	}puts("");
	printf("%d\n",res.size());
	for(int v:res){
		printf("%d ",v);
	}
	return 0;
}
