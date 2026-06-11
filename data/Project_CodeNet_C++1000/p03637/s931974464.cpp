#include<iostream>
using namespace std;
int n,n4,n2;
long long int a;
int main()
{
	cin>>n;n4=0;n2=0;
	for (int i=0;i<n;i++)
	{
		scanf("%d",&a);
		
		if(a%4==0)n4++;
		else if(a%2==0)n2++;
	}
	if(n2==0&&2*n4>=n-1)
		cout<<"Yes";
	else if(n2+2*n4>=n)cout<<"Yes";
	else cout<<"No";

}