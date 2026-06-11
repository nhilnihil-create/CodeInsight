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
	cin>>s;
	n=s.size();
	map<char,int>mp;
	map<char,int>::iterator it;	
	while(n--){

		mp[s[n]]++;
	}
	for(it=mp.begin();it!=mp.end();it++){
		if((it->second)%2==1 )return cout<<"No",0;
		//cout<<it->second<<nw;
	}
	cout<<"Yes";
}