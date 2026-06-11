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
	int n;
	cin>>n;
	string s;
	cin>>s;
	int x = 0;
	string h = "", t= "";
	for(auto it:s)
	{
		x += it=='('?1:-1;
		if(x<0)
		{
			x++;
			h += '(';
		}
	}
	while(x--)
		t +=')';
	cout<<h<<s<<t<<endl;
	return 0;
}