#include<bits/stdc++.h>
using namespace std;
bool zs(int n)
{
	for(int i=2;i*i<=n;++i)
		if(n%i==0)
			return false;
	return true;
}
bool hw(int n)
{
	int m=0,k=n;
	while(k!=0)
	{
		m=m*10+k%10;
		k/=10;
	}
	if(m==n)
		return true;
	return false;
}
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	if(b-a==c-b)
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}