#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define ar array
#define mp make_pair
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s,b,c;
	cin>>s>>b>>c;
	if(s[s.length()-1]==b[0] && b[b.length()-1]==c[0])
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}