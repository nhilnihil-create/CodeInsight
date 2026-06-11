#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[1000];
	for(int i=1;i<=2*n;i++)
	{
		cin>>a[i];
	} 
	sort(a+1,a+2*n+1);
	int s=0;
	for(int i=1;i<=2*n-1;i+=2)
	{
		s+=min(a[i],a[i+1]);
	}
	cout<<s<<endl;
 	return 0;
}
