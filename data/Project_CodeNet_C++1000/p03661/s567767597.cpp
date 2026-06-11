#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cmath>
#include<queue>
#include<vector>
#include<sstream>
#include<algorithm>
#include<stack>
#include<map>
#include<set>
#define rep(i,n) for(int i=0;(i)<(n);i++)
#define rep1(i,n) for(int i=1;(i)<=(n);i++)
#define mst(a,b) memset(a,b,sizeof(a))
#define scd(a) scanf("%d",&a)
#define scdd(a,b) scanf("%d%d",&a,&b)
#define scddd(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define dbg(a) cout<<"* "<< #a <<" : "<<a<<endl
#define fr first
#define se second
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ls x<<1
#define rs x<<1|1
#define lowbit(x) x&(-x)
#define ac cout<<ans<<endl
//#define DEBUG 0
using namespace std;
const double pi=acos(-1.0);
const double eps=1e-6;
const ull hashp=1e7+19;
const ll INF=0x3f3f3f3f3f3f3f3fll;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
const int maxn=3e5+100;
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
ll qpow(ll a,ll b){
	ll ret=1;
	while(b){
		if(b&1)ret*=a;
		b>>=1;
		a*=a;
	}
	return ret;
}
ll get(ll x){
	return x*(x+1)/2;
}
int a[maxn];
ll sum[maxn];
void solve()
{
    int n;scd(n);
    rep1(i,n){
    	scd(a[i]);
    	sum[i]=sum[i-1]+1ll*a[i];
	}
	ll ans=INF;
	rep1(i,n-1)ans=min(ans,abs(sum[n]-2*sum[i]));
	ac;
}
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("D://out.txt","w",stdout);
    //IOS;
    solve();
    return 0;
}