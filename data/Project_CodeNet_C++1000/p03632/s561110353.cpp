#include<bits/stdc++.h>

using namespace std;

int main()
{
	int a,b,c,d,hi,lo;
	cin>>a>>b>>c>>d;
	hi = min(b,d);
	lo = max(a,c);
	cout<<max(0,hi-lo)<<endl;
	
	return 0;
}