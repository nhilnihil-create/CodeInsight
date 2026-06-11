#include<iostream>
using namespace std;
int main()
{
	long long n,a[100000]={0},count=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		count+=a[i];
	}
	if(count%2==0)
	{
		cout<<"YES";
		return 0;
	 } 
	cout<<"NO";
	return 0;
 } 