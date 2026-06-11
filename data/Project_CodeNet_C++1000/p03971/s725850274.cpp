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
	ll tc,l,k,sum=0,x=0,y,z=0,m=1,n=0,ans;
	ll a,b;
	cin>>n>>a>>b;
	string s;
	cin>>s;
	ll as=0,bs=0;
	for(ll i=0;i<n;i++)
	{
		if(s.at(i)=='a'&& as+bs<a+b)cout<<"Yes"<<nw,as++;
		else if(s.at(i)=='b'&& as+bs<a+b && bs<b)
			cout<<"Yes"<<nw,bs++;
		else cout<<"No"<<nw;
	}

}
