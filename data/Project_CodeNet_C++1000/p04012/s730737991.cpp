#include <bits/stdc++.h>
using namespace std;
int main()
{
	string w;
	cin>>w;
	int a,i,j,n,b[123]={0};
	n=w.size();
	for(i=0;i<n;i++)
	{
		a=w[i]-0;
		b[a]++;
	}
	for(i=97;i<123;i++)
	{
		if(b[i]%2!=0)
		{
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
}