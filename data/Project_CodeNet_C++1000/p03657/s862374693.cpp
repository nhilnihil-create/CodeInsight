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
	if(a%3==0 || b%3==0 || (a+b)%3==0)
		cout<<"Possible";
	else
		cout<<"Impossible";
	return 0;
}