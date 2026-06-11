#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007
int main(){
	fast;
	string s;
	cin>>s;
	int n=s.length(),a=0,z=0;
	for(int i=0;i<n;i++)
		if(s[i]=='A')
		{
			a=i;
			break;
		}
	for(int i=n-1;i>=0;i--)
		if(s[i]=='Z')
		{
			z=i;
			break;
		}
	cout<<z-a+1;
	return 0;
}

