#include<bits/stdc++.h>
typedef long long ll ;
typedef double db;
typedef long double ldb;
typedef unsigned long long ull ;
const double PI = acos(-1) ;

#define pf		  	printf
#define sf			  scanf
#define pb(a)         push_back(a)
#define for0(i,n)          for(int i=0;i<n;i++)
#define for1(i,n)          for(int i=1;i<=n;i++)
#define forab(i,a,b)       for(int i=a;i<=b;i++)
//#define gcd(a, b)     __gcd(a, b)
#define lcm(a, b)     ((a)*((b)/gcd(a,b)))
#define sq(a)		   (a)*(a)
#define nw				"\n"
//#define abs(x)		fabs(x)
#define pcase(z,x)     cout<<"Case "<<z<<": "<<x<<"\n"
#define CIN	ios_base::sync_with_stdio(0); cin.tie(0)
#define max 1000000007

using namespace std;
int n,m,y,x,a,b,h,e,l,o,i,j,sum=0;

int main()
{
	
	CIN;
	cin>>n;
	//pair<int,pair<int,int>>arr[n];
	int lala[100001]={0},arr[n];
	for0(i,n)
	while(n--)
	{
		cin>>arr[i];
		//arr[i].second.first=arr[i].first+1;
		lala[arr[i]-1]++;
		lala[arr[i]+1]++;
		lala[arr[i]]++;
	}
	for(int i=0;i<=100000;i++)
		if(sum<lala[i])sum=lala[i];
	cout<<sum<<nw;
	


}

