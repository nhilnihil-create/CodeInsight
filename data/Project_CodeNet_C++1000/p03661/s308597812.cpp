#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int n;
	long long int temp,*a;
	long long int sum=0;
	cin>>n;
	a=new long long int[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	sum-=2*a[0];
	temp=abs(sum);
	for(int i=1;i<n-1;i++)
	{
		sum-=2*a[i];
		if(temp>abs(sum))
			temp=abs(sum);
		}
	cout<<temp;
	return 0;
 }
  