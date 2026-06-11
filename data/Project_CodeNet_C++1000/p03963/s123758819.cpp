#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#define lowbit(x) ((x)&(-x))
#define sc scanf
#define debug1(x) cout<<x<<" "
#define debug2(x) cout<<x<<"\n"
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
typedef long long ll;
const ll inf=1e18;
const int N=2e5+10;
using namespace std;
int gcd(int a,int  b)
{
	return b==0?a:gcd(b,a%b);
}

int main()
{
	ll k,n;
	cin>>n>>k;
	ll ans=k;
	ans*=pow((k-1),(n-1));
	cout<<ans<<"\n";
	return 0;
}