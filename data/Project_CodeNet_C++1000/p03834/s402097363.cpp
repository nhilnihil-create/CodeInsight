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
	for(int i=0;i<s.length();i++)
		if(s[i]!=',')
			cout<<s[i];
		else
			cout<<" ";
	return 0;
}

