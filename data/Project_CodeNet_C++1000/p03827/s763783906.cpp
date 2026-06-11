#include<bits/stdc++.h>
using namespace std;
typedef long long  ll ;
typedef double db;
const double pi = 3.141592654;
#define pb         push_back
#define forab(i,a,b)       for(int i=(a);i<=(b);i++)
#define CIN	ios_base::sync_with_stdio(0); cin.tie(0)
#define pcase(z,x)     printf("Case %ld: %lld\n",z,x)
#define nw				"\n"
int main(void)
{
	CIN;
	ll tc,l,k,sum=0,x=0,y,z=0,m=1,n=0,ans=0,cnt=0;
	string s;
	cin>>n;
	cin>>s;
	ll maxh=-1e9;
	while(n--){
		if(s[x++]=='I')sum++;
		else sum--;
		maxh=max(maxh,sum);
	}
	if(maxh<0)maxh=0;
	cout<<maxh;
}