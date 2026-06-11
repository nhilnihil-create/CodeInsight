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
	char ch,c;
	cin>>c>>ch;
	if(c=='H')
		cout<<ch<<endl;
	else
	{
		if(ch=='D')
			cout<<'H'<<endl;
		else
			cout<<'D'<<endl;
	}
	return 0;
}