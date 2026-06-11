#include <iostream>
using namespace std;
int main()
{
	int a[5];
	for(int i=0;i<3;i++)
		cin>>a[i];
	if(a[0]%2==0||a[1]%2==0||a[2]%2==0)
		cout<<"0";
	else
	{
		long long max=0;
		int maxid=-1;
		for(int i=0;i<3;i++)
		{
			if(a[i]>max)
			{
				max=a[i];
				maxid=i;
			}
		}
		long long sum=1;
		for(int i=0;i<3;i++)
			if(i!=maxid)
				sum*=a[i];
		cout<<sum<<endl;
	}
}