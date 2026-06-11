#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if(d<=a||b<=c)
	{
		cout<<0;
	}
	else cout<<(min(b,d)-max(a,c));
}