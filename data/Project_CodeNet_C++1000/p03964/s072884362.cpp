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
ll arr[1010],brr[1010];
int gcd(int a,int  b){return b==0?a:gcd(b,a%b);}
int main()
{
	ll n,t,x=1,y=1;
	cin>>t;
	while(t--)
	{
		ll a,b;
		cin>>a>>b;
		n=max(x/a,y/b);
		while(n*a<x||n*b<y)n++;
		x=a*n,y=b*n;
	}
	cout<<x+y<<"\n";
	return 0;
}