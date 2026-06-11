#include <bits/stdc++.h>
using namespace std;
int main()
{
	int r,c;
	cin>>r>>c;
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			string x;
			cin>>x;
			if(x == "snuke")
			{
				cout<<(char)('A'+j)<<i+1<<"\n";
				return 0;
			}
		}
	}
	return 0;
}