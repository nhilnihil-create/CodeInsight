#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,i;
	char a[100010];
	cin>>a;
	n=strlen(a);
	if(a[0]==a[n-1])
	{
		if(n%2==1)
		{
			cout<<"Second"<<endl;
		}
		else
		{
			cout<<"First"<<endl;
		}
	}
	else
	{
		if(n%2==1)
		{
			cout<<"First"<<endl;
		}
		else
		{
			cout<<"Second"<<endl;
		}
	}
}