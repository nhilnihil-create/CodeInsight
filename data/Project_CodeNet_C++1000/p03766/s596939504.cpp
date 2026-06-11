#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
#define __ %=Mod
using namespace std;

const int maxn = 1100000;
const ll Mod = 1e9+7;

int n;
ll f[maxn],sum;

int main()
{
	scanf("%d",&n);
	f[0]=1ll; sum=1ll;
	for(int i=1;i<=n;i++) 
	{
		(f[i]+=sum-(i-2>=0?f[i-2]:0))__;
		(sum+=f[i])__;
	}
	ll re=0,N=(ll)(n-1)*(n-1)%Mod;
	for(int i=0;i<n-1;i++) (re+=f[i]*N%Mod)__;
	(re+=f[n-1]*(n-1)%Mod)__;
	(re+=f[n]%Mod)__;
	for(int i=n-2;i>=0;i--) (re+=f[i]*(i+1)%Mod)__;
	printf("%lld\n",re);
	
	return 0;
}
