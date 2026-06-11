#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b)
{
	return a>b;
}
long long a[4];
int main()
{
	for(int i=1;i<=3;i++)
	cin>>a[i];
	sort(a+1,a+4,cmp);
	if(a[2]-a[1]==a[3]-a[2])
	cout<<"YES";
	else 
	cout<<"NO";
	cout<<endl;
	return 0;
}