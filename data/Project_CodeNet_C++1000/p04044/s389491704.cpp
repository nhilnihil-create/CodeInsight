#include<iostream>
#include<algorithm>
using namespace std;
string a[1000];
int comp(string zh,string hz)
{
	return zh<hz;
}
int main()
{
	int n,l;
	cin>>n>>l;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n,comp);
	for(int i=1;i<=n;i++)
	  cout<<a[i];
	return 0;
}