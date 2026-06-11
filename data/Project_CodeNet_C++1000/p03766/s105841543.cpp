#include <bits/stdc++.h>
#define syosu(x) fixed<<setprecision(x)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<P> vp;
typedef vector<vp> vvp;
typedef vector<pll> vpll;
typedef pair<int,P> pip;
typedef vector<pip> vip;
const int inf=1<<30;
const ll INF=1ll<<55;
const double pi=acos(-1);
const double eps=1e-8;
const ll mod=1e9+7;
const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};

ll n;
vl dp,DP;

int main(){
	cin>>n;
	dp=DP=vl(n);
	dp[0]=DP[0]=1;
	for(int i=1;i<n;i++){
		dp[i]=(dp[i-1]+(i>2?DP[i-3]:0))%mod;
		DP[i]=(dp[i]+DP[i-1])%mod;
	}
	ll res=n,N=n-1;
	for(int i=1;i<n;i++) (res+=N*(N*dp[i-1]%mod+dp[i]))%=mod;
	cout<<res<<endl;
}