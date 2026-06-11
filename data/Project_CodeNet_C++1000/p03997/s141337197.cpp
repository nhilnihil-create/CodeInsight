#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define f first
#define s second
#define mp make_pair
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int a,b,c;
	cin>>a>>b>>c;
	ll area = (c/2)*(b-a)+a*c;
	cout<<area<<endl;
	return 0;
}