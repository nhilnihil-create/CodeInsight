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
	string s;
	cin>>s;
	int n = s.length()-2;
	if(s[0]==s[n+1])
		n--;
	if(n&1)
		cout<<"First"<<endl;
	else cout<<"Second"<<endl;
	return 0;
}