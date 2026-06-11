#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
bool comp(int a,int b)
{
	return a>b;
}
int main()
{
	int a[300];
	int n;
	cin>>n;
	for(int i=0;i<2*n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+2*n,comp);//从大到小排序
	int ans=0;
	for(int i=1;i<2*n;i=i+2)
	{
		ans+=a[i];
	}
	cout<<ans<<endl;
}