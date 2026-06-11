#include <bits/stdc++.h>

using namespace std;

string a,b="CODEFESTIVAL2016";
int ans;

int main(void)
{
	ios::sync_with_stdio(false);
	getline(cin,a);
	for(int i=0;i<a.length();i++)
	{
		if(a[i]!=b[i])
		{
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}