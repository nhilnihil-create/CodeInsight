#include<stdio.h>
#include<iostream>
using namespace std;
int main(void)
{
	long long a,b,c,ans;
	cin>>a>>b>>c;
	if(a%2==0||b%2==0||c%2==0)
	printf("0\n");
	else
	{
		if(a>b&&a>c)
		ans=b*c;
		else if(b>a&&b>c)
		ans=a*c;
		else ans=a*b;
		cout<<ans;
	}
	return 0;
}