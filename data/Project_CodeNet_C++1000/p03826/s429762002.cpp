#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	int e=0;
	int f=0;
	e=a*b;
	f=c*d;
	cout<<max(e,f)<<endl;
	
	return 0;
}