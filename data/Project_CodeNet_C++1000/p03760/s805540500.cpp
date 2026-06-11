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

int main(void)
{
	CIN;
	ll tc,l,k,sum=0,x=0,y,z=0,m=1,n=0,ans=0,cnt=0;
	string s,t;
	cin>>s>>t;
	char p[100];
	for(ll i=0,j=0;j<s.size();i+=2,j++){
		p[i]=s[j];
	}
	for(ll i=1,j=0;j<t.size();j++,i+=2){
		p[i]=t[j];
	}
	for(ll i=0;i<s.size()+t.size();i++)
		cout<<p[i];
	


}