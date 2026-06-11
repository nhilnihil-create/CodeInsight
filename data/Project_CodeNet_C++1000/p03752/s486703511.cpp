// https://atcoder.jp/contests/s8pc-4/tasks/s8pc_4_b
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int,int> P;

#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<(b);i++)
#define repr(i,b,a) for(int i=int(b);i>=(a);i--)
#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool valid(int lx,int ux,int ly,int uy,int x,int y){
	return lx<=x&&x<ux&&ly<=y&&y<uy; 
}
ll power(ll x,ll p){
	if(p==0)return 1;
	ll res=power(x*x%mod,p/2);
	if(p%2==1)res=res*x%mod;
	return res;
}

int main()
{
	int n,k;
	cin>>n>>k;
	vector<int> a(n);
	rep(i,n)cin>>a[i];

	ll ans=1e12;
	rep(bit, (1<<n)){
		if(__builtin_popcount(bit)<k)continue;
		vector<int> pos, tmp=a;
		rep(i,n){
			if(bit&(1<<i))pos.push_back(i);
		}
		ll res=0;
		int h=0;
		for(auto p:pos){
			if(tmp[p]<=h){
				res+=h+1-tmp[p];
				tmp[p]=h+1;
			}
			h=tmp[p];
		}
		bool is_valid=true;
		h=0;
		rep(i,n){
			if(tmp[i]<=h&&(bit&(1<<i)))is_valid=false;
			h=max(tmp[i],h);
		}
		if(is_valid)ans=min(ans,res);
	}
	cout<<ans<<endl;
	return 0;
}