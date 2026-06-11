#include<bits/stdc++.h> 
using namespace std;
char a[20];
int main()
{
	cin>>a;
	int su=0,i;
	for(i=0;i<strlen(a);i++)
	{
		su++;
		if(su==4)
		{
			cout<<a[i]<<' ';
			su++;
			continue;
		}
		cout<<a[i];
	}
	cout<<endl;
	return 0;
}