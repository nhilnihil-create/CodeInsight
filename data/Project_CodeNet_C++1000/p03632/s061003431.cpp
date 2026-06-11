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
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	int y = -max(a,c)+min(b,d);
	if(y<0)
		cout<<0<<endl;
	else
		cout<<y<<endl;
	return 0;
}