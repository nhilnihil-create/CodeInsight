#include<iostream>
using namespace std;
#define int long long int
int bs(int s,int e,int v)
{
	if(s<=e)
	{
		int m=(s+e)/2;
		if(m*(m+1)>=2*v)
		{
			int x=m;
			int y=bs(s,m-1,v);
			if(y==-1)
			   return x;
			else
			   return y;
		}
		else
		    return bs(m+1,e,v);
	}
	return -1;
}
int32_t main()
{
	int x;
	cin>>x;
	int val=bs(1,1000000000,x);
	cout<<val<<endl;
}
