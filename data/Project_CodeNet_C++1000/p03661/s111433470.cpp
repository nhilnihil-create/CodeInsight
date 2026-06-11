#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include <limits.h>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <string>
#include <string.h>
#include <sstream>
#include <ctime>

using namespace std;

#define eps 1e-12
#define pi 3.14159265358979323846
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define bgn begin
#define ll long long
#define ld long double
#define ull unsigned long long
#define ii pair<ll,ll>













const int N=2e5+10;
ll n,a[N],sum,sum2,res,d;

void solve()
{
	cin>>n;
	sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	sum2=0;
	for(int i=1;i<n;i++)
	{
		sum2+=a[i];
		d=sum2-(sum-sum2);
		if(d<0)d*=-1;
		if(i==1||res>d)res=d;
	}
	cout<<res<<"\n";
}

int main()
{
	std::ios::sync_with_stdio(0);
	cin.tie(0);
#ifdef localProject
	freopen("in.txt","r",stdin);
#endif
	solve();
	return 0;
}