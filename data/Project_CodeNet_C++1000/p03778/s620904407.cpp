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
	int w,a,b;
	cin>>w>>a>>b;
	if(abs(b-a)<=w)
		cout<<0<<endl;
	else
		cout<<min(abs(b-a-w),abs(a-b-w))<<endl;
	return 0;
}