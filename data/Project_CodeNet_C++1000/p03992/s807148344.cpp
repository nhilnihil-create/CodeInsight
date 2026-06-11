#include <bits/stdc++.h>
#define int long long
using namespace std;

char a[15];

signed main()
{
	for (int i=1;i<=12;i++)  cin>>a[i];
	for (int i=1;i<=12;i++)
	{
		cout<<a[i];
		if (i==4)  cout<<' ';
	}
	cout<<endl;
	
	return 0;
}