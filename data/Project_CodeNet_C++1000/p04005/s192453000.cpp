#include <iostream>

using namespace std;

int main()
{
	long long a[3];
	cin>>a[0];
	cin>>a[1];
	cin>>a[2];
	for(int i=0;i<2;i++)//降序排列 
	{
		for(int j=i;j<3;j++)
		{
			if(a[i]<a[j])
			{
				swap(a[i],a[j]);
			}
		}
	}
    long long t1=a[0]-a[0]/2;
    long long t2=a[0]-t1;
    long long t=t1-t2;
    if(t<0)
    {
    	t=-t;
	}
	cout<<t*a[1]*a[2];
 } 