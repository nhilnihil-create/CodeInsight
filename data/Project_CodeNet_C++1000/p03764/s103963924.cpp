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
ll MOD=1e9+7;

int main(void){
	ll n,m,x,y,sum[100010],ansx=0,ansy=0;
	scanf("%lld%lld",&n,&m);
	sum[0]=0;
	reg(i,1,n){
		scanf("%lld",&x);
		sum[i] = x+sum[i-1];
		sum[i] %= MOD;
		ansx += i*x-sum[i];
		ansx %= MOD;
	}
	sum[0]=0;
	reg(i,1,m){
		scanf("%lld",&y);
		sum[i] = y+sum[i-1];
		sum[i] %= MOD;
		ansy += i*y-sum[i];
		ansy %= MOD;
	}
	ansx*=ansy;
	ansx%=MOD;
	printf("%lld\n", ansx);
	return 0;
}