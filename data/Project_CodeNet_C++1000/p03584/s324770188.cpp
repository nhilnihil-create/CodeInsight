#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
#include<set>
#include<numeric>
#include<map>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i = 0;i<((int)(n));i++)
#define reg(i,a,b) for(int i = ((int)(a));i<=((int)(b));i++)
#define irep(i,n) for(int i = ((int)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(int i = ((int)(b));i>=((int)(a));i--)
typedef long long ll;
typedef pair<ll, ll> mp;

/*
AC
上のbitから順に0,1を選択する．
O(log(K)*n)なので間に合う
*/

//累乗法
ll mod_pow(ll x,ll n,ll mod=1e18+7){
	ll res=1;
	while(n){
		if(n&1) (res*=x)%=mod;
		(x*=x)%=mod;
		n>>=1;
	}
	return res;
}

int main(void){
	ll n,k,a[100010],b[100010],cur=0,ans=0;
	cin>>n>>k;
	rep(i,n)cin>>a[i]>>b[i];
	rep(j,n)if((a[j]|k)==k)ans+=b[j];
	// cout<<bitset<8>(k)<<endl;
	irep(i,31){//最上位bitがどうなってるかの確認
		ll c=mod_pow(2,i),d=k/c;//d：最上位bit
		k-=c*d;
		if(d==1){
			//f：d=0にして，下の桁を全て1にした数
			ll f=cur+c-1,sum=0;
			rep(j,n)if((a[j]|f)==f)sum+=b[j];
			ans=max(ans,sum);
			ll e=cur+c;
			sum=0;
			rep(j,n)if((a[j]|e)==e)sum+=b[j];
			ans=max(ans,sum);
			// cout<<bitset<8>(f)<<endl;
		}
		cur+=c*d;
	}
	cout<<ans<<endl;
	return 0;
}