//9.8 AT2141
#include <bits/stdc++.h>
using namespace std;
int main()
{
	string q;
	cin>>q;
	int m[100001]={0};
	int a=0,sum=0;
	for(int i=0;i<q.size();i++) 
	{
		if(q[i]=='p') m[i]=1;
		else m[i]=0;
	}
	for(int i=0;i<q.size();i++)
	{
		if(i%2==0) a=0;
		else a=1;
		if(a>m[i]) sum++;
		else if(a<m[i]) sum--;
	}
	cout<<sum;
	return 0;
}