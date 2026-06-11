#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 210000
#define MAXM 410000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int gcd(int x,int y)
{
	if (!y)
		return x;
	return gcd(y,x%y);
}

int n;
int mx;
int x;
int k;
int gc;

int main()
{
	cin>>n>>k;
	for (int i=0;i<n;i++)
	{
		scanf("%d",&x);
		mx=max(mx,x);
		gc=gcd(gc,x);
	} 
	if (mx<k)
	{
		cout<<"IMPOSSIBLE"<<endl;
		return 0;
	}
	if (k%gc)
	{
		cout<<"IMPOSSIBLE"<<endl;
		return 0;
	}
	cout<<"POSSIBLE"<<endl;
	
	return ~~(0^_^0);
}

