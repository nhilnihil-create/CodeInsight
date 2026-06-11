#include<bits/stdc++.h>
using namespace std;
int a[101101];
int main()
{	
	int check,n;
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1; i<=n; i++)
	{
		if(a[i]==a[i-1])check++;
	}
	if(check%2==1) check++;
	cout<<n-check<<endl;
	return 0;

}