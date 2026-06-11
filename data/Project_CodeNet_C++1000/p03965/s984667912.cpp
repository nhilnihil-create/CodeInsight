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
	string s;
	cin>>s;
	int rock=0, paper =0, ans =0;
	for(auto it:s)
	{
		if(it=='g')
		{
			if(rock>paper)
			{
				ans++;
				paper++;
			}
			else
				rock++;
		}
		else
		{
			if(rock>paper)
				paper++;
			else
			{
				rock++;
				ans--;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}