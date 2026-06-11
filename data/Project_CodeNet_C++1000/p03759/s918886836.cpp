#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c,sum1=0,sum2=0;
	cin>>a>>b>>c;
	sum1=b-a;
	sum2=c-b;
	if(sum1==sum2)
	cout<<"YES";
	else
	cout<<"NO";
	return 0;
}