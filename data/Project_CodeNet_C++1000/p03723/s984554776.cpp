#include<bits/stdc++.h>
using namespace std;
typedef long long  ll ;
typedef double db;
const double pi = acos(-1) ;
#define pb         push_back
#define forab(i,a,b)       for(int i=(a);i<=(b);i++)
#define CIN	ios_base::sync_with_stdio(0); cin.tie(0)
#define pcase(z,x)     printf("Case %ld: %lld\n",z,x)
#define nw				"\n"


int main(void)
{
	CIN;
	ll tc,l,k,sum=0,x=0,y,z=0,m=1,n=0,ans=0;
	int arr[3];
	for(auto &i:arr)
		cin>>i;
	
	while(arr[0]%2==0&&arr[1]%2==0&&arr[2]%2==0)
	{
		x=arr[0],y=arr[1],z=arr[2];
		arr[0]=y/2+z/2;
		arr[1]=x/2+z/2;
		arr[2]=x/2+y/2;
		sum++;
		if(arr[0]==arr[1] && arr[1]==arr[2] &&arr[0]%2==0&&arr[1]%2==0&&arr[2]%2==0 )
		return cout<<-1<<nw,0;
	}
	cout<<sum<<nw;
}
