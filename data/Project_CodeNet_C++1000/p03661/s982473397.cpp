#include<iostream>
#include<cmath>
using namespace std;
const long long size=2e+5;
	long long a[size],x[size];
	long long n,s;
int main()
{	
	cin>>n>>a[0];
     x[0]=a[0];
	 s=a[0]; 
	for(int i=1;i<n;i++)
	{
		cin>>a[i];
	    x[i]=x[i-1]+a[i];
	    s+=a[i];
	}
	long long min=2e+10,result;
	for(int i=0;i<n-1;i++)
	{
	result=abs(2*x[i]-s);
	if(min>result)
	min=result;
	}
	cout<<min;
	return 0;
}
	