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
	ll x,a,b;
	cin>>x>>a>>b;
	if(x+a<b)
		cout<<"dangerous"<<endl;
	else if(b<=a)
		cout<<"delicious"<<endl;
	else
		cout<<"safe"<<endl;
	return 0;
}