#include<iostream>
#include<algorithm>
using namespace std;

long long n,a[10000],ams;

int main()
{
	ios::sync_with_stdio(0);
	 cin>>n;
	 n*=2;
	 for(int i=1;i<=n;i++)
	 	cin>>a[i];
	 sort(a+1,a+n+1);
	 for(int i=1;i<n;i+=2)
	 	ams+=a[i];
	 cout<<ams;
	return 0;
}