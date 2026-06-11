#include<bits/stdc++.h>
using namespace std;
typedef long long  ll ;
typedef double db;
const double pi = 3.141592654;
#define pb         push_back
#define forab(i,a,b)       for(int i=(a);i<=(b);i++)
#define CIN	ios_base::sync_with_stdio(0); cin.tie(0)
#define pcase(z,x)     printf("Case %ld: %lld\n",z,x)
#define nw	 "\n"

int main(void)
{
	CIN;
	ll tc,l,k,sum=0,x=0,y,z=0,m=1,n=0,ans=0,cnt=0;
	cin>>n>>m;
	x=n+2,y=m+2;
	char c;
	char a[x][y];
	for(ll i=0;i<x;i++)
		for(ll j=0;j<y;j++)
			a[i][j]='#';
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	for(ll i=0;i<x;i++){
		for(ll j=0;j<y;j++)
			cout<<a[i][j];
		cout<<nw;
	}
		

}