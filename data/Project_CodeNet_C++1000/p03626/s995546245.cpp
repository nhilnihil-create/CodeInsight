#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mod 1000000007
int main(){
	fast;
	ll n,ans=1;
	cin>>n;
	string s1,s2,s;
	cin>>s1>>s2;
	for(int i=0;i<s1.length();i++)
	{
		if(s1[i]==s2[i])
			s+='X';
		else
			s+='Y',i++;
	}
	if(s[0]=='X')
		ans=3;
	else
		ans=6;
	for(int i=1;i<s.length();i++)
		if(s[i]=='X'&&s[i-1]=='X')
			ans=(ans*2)%mod;
		else if(s[i]=='X'&&s[i-1]=='Y')
			ans=ans;
		else if(s[i]=='Y'&&s[i-1]=='X')
			ans=(ans*2)%mod;
		else if(s[i]=='Y'&&s[i-1]=='Y')
			ans=(ans*3)%mod;
	cout<<ans%mod;
	return 0;
}

