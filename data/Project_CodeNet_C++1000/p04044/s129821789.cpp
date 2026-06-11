
#include <bits/stdc++.h> 
using namespace std; 

string s[10000];

bool compare( string a, string b)
{
	return a+b < b+a ;
}


int main()
{
	int n,l; cin>>n>>l;

	
	for(int i=0;i<n;i++)
	cin>>s[i];
	
	//sort( s, s+n ,compare);
sort(s, s+n) ;
	
	string ans="";
	
	for( int i=0;i<n;i++) 
	ans= ans + s[i];
	
	cout<<ans<<endl;
	
}