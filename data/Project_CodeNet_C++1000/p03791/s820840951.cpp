#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<complex>
#include<string>
#include<cstring>
using namespace std;
#define rep2(x,from,to) for(long long x=(from);(x)<(to);(x)++)
#define rep(x,to) rep2(x,0,to)
#define INF 100000000
#define debug(x) cout<<#x<<": "<<x<<endl
#define NN 1000000007
#define all(x) x.begin(),x.end()
typedef pair<long long,long long> P;
typedef pair<long long,P> PP;
long long a[200005];
long long n;
long long M;
long long ans;
long long torino;
long long tor[200005];
long long mm(long long aa,long long bb)
{
	if(aa<bb)return bb;
	else return aa;
}
int main()
{
	cin>>n;
	rep(i,n)cin>>a[i];
	if(n==2)
	{
		cout<<2<<endl;
		return 0;
	}
	rep2(i,1,n)
	{
		if(a[i]%2==0)
		{
			M=a[i]/2;
		}
		else M=a[i]/2+1;
		tor[i]=mm(i+1-M,0);
		tor[i]=mm(tor[i],tor[i-1]);
	}
	ans=1;
	rep2(i,1,n)
	{
		ans*=(i+1-tor[i-1]);
		ans%=NN;
	}
	cout<<ans<<endl;
	return 0;
}
