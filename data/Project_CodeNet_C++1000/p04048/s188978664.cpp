#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
ll ans;

void solve(ll a,ll b)
{
	if(a<b) swap(a,b);
	if(!b){ans+=a;return ;};
	ll cnt=a%b?a/b:a/b-1;
	ans+=cnt*b*2;
	solve(b,a%b);
}

int main()
{
	ll N,X;scanf("%lld %lld",&N,&X);
	ans+=N;
	solve(X,N-X);
	printf("%lld\n",ans);
	return 0;
}