#include <iostream>
#include <iomanip>
#include <ios> 
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <bitset>
#include <map>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define sz(c) ((int)(c).size())

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
const ll MOD=1e9+7;
const int MAX=1e5+5;

ll extgcd(ll a,ll b,ll& x, ll& y){
	ll d=a;
	if(b!=0){
		d = extgcd(b, a%b, y, x);
		y -= (a/b) * x;
	}
	else{
		x = 1; y = 0;
	}
	return d;
}
ll mod_inv(ll a,ll m){
	ll x,y;
	extgcd(a,m,x,y);
	return (m+x%m)%m;
}

ll fc[2*MAX];

ll cb(int a,int b){
	return (((fc[a]*mod_inv(fc[b],MOD))%MOD)*mod_inv(fc[a-b],MOD))%MOD;
}
//(a,b)から(c,d)へ行く
ll rect(int a,int b,int c,int d){
	return cb(a-c+d-b,a-c);
}

int main(){
	fc[0]=1;
	rep1(i,2*MAX-1)fc[i]=(i*fc[i-1])%MOD;
	
	int H,W,A,B;
	cin>>H>>W>>A>>B;
	ll ans=0;
	int p=A,q=B;
	while(p<H && q<W){
		ll k=(rect(H-1,0,p,q)*rect(p,q,0,W-1))%MOD;
		ans=(ans+k)%MOD;
		p++;q++;
	}
	cout<<ans<<endl;
}