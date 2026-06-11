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
	int a,b,c;
	cin>>a>>b>>c;
	int ans = (a+b+c)-max({a,b,c});
	cout<<ans<<endl;
	return 0;
}