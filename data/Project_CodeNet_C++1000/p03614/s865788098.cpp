#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[100000+5]={0};
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int num=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==i)
		{
				swap(a[i],a[i+1]);
				num++;
		}
	}
	cout<<num<<endl;
	return 0;
}