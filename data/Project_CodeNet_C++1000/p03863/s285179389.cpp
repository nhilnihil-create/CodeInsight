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
	bool even=(s.length()%2==0);
	bool same=(s[0]==s[s.length()-1]);
	if(even ^ same)
		cout<<"Second";
	else
		cout<<"First";
	return 0;
}

