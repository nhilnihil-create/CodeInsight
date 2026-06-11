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
#define mod 1000000007

ll w,e;
int main(void)
{
	CIN;
	ll tc,l,k=0,sum=0,x=0,y,z=0,m=1,n=0,ans=0,cnt=0;
	string s;
	cin>>s;
	for(ll i=0;i<s.size();i++){
		if(s[i]=='E')e=1;
		else if(s[i]=='S')k=1;
		else if(s[i]=='W')w=1;
		else n=1;
	}
	if((n^k)|| (e^w))cout<<"No";
	else cout<<"Yes";
	
}