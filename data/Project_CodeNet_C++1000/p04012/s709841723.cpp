#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
	string s;
	cin>>s;
	ll ar[1000001] = {0};
	string a = "Yes";
	for(size_t i = 0; i<s.size(); i++)
	{
		ar[s[i]]++;
	}
	for(ll i = 'a'; i<'z'; i++)
	{
		if(ar[i]%2 != 0)
		{
			a = "No";
		}
	}
	cout<<a<<endl;
	return 0;
}