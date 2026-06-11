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
	string s,t;
	getline(cin,s);
	stringstream ss(s);
	while(ss>>t)
	{
		cout<<char(t[0]-32);
	}
	return 0;
}