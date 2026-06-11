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
	int a,b;
	cin>>a>>b;
	cout<<((a+b)>=24?(a+b-24):a+b);
	return 0;
}