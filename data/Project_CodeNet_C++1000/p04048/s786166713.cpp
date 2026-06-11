#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,m;
ll solve(ll x,ll y)
{
	if(x==y) return x;
	if(x<y) swap(x,y);
	return solve((x-1)%y+1,y)+(x-1)/y*y*2;
}
int main()
{
	scanf("%lld%lld",&n,&m);
	printf("%lld",solve(m,n-m)+n);
	return 0;
}