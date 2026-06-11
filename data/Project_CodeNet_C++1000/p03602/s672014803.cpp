#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i = 0;i<((ll)(n));i++)
#define reg(i,a,b) for(ll i = ((ll)(a));i<=((ll)(b));i++)
#define irep(i,n) for(ll i = ((ll)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(ll i = ((ll)(b));i>=((ll)(a));i--)
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

/*
*/

ll n,a[310][310],ans=0;
pair<ll,pair<ll,ll>> p[90010];
bool ok=true;

void init(){
	cin>>n;
	rep(i,n)rep(j,n)cin>>a[i][j];
}

int main(void){
	init();
	rep(i,n)rep(j,i){
		ll d=1e18;
		rep(k,n){
			if(k==i || k==j)continue;
			d=min(d,a[i][k]+a[k][j]);
		}
		if(d<a[i][j]){  // 構築不可能
			ok=false;
			break;
		}
		if(d>a[i][j]){
			ans+=a[i][j];
		}
	}
	cout<<(ok?ans:-1)<<endl;
	return 0;
}