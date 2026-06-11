#include<bits/stdc++.h>
using namespace std;
int n,x,ans;
int main()
{
	cin>>n;
	for (int i=0;i<n;i++)
	{
		cin>>x;
		ans+=x%2;
		ans%=2;
	}
	if (ans%2)
		cout<<"NO"<<endl;
	else
		cout<<"YES"<<endl;
	return 0;
}