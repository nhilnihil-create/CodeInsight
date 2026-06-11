#include <iostream>

using namespace std;

int main()
{
	long int n;
	cin>>n;
	long int a[n], l;
	cin>>l;
	for(long int i=0; i<n; i++)
		cin>>a[i];

	long int sum=0;
	long int ind=-1;
	for(long int i=1; i<n; i++)
	{
		if(sum<=a[i]+a[i-1])
		{
			sum = a[i]+a[i-1];
			ind=i;
		}
	}
	if(sum>=l)
	{
		cout<<"Possible"<<endl;
		for(long int i=1; i<ind; i++)
			cout<<i<<endl;
		for(long int i=n-1; i>ind; i--)
			cout<<i<<endl;
		cout<<ind<<endl;
	}
	else
		cout<<"Impossible";
}