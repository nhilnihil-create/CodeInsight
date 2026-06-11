#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	long size,s,i;
	s=i=0;
	cin>>size;
	long* a=new long[size];
	long* b=new long[size]; 
	for(i=0;i<size;i++)
	{
		cin>>a[i];
		s+=a[i];
		b[i]=s;
	}
	long k=abs(s-b[0]*2);
	for(i=0;i<size-1;i++)
	{
		if(abs(s-b[i]*2)<k)
		{
			k=abs(s-b[i]*2);
		}
	}
	cout<<k;
	delete [] a;
	delete [] b;
	return 0;
}