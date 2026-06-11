#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define ar array
#define pb push_back
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin>>s;
	for(int i = 0; i<s.length(); i+=2)
		cout<<s[i];
	return 0;
}