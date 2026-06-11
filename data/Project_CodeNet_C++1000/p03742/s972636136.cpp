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
	ll x,y;
	cin>>x>>y;
	if(abs(x-y)<=1) cout<<"Brown"<<endl;
	else cout<<"Alice"<<endl;
	return 0;
}