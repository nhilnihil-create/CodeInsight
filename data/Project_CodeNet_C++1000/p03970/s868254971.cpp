#include<bits/stdc++.h>
using namespace std;
string a,b;
int ans=0;
int main()
{
	cin>>a;
	b="CODEFESTIVAL2016";
	for(int i=0;i<16;i++)
	{
		if(a[i]!=b[i])
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}