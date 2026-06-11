#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
	int n,i,j,a,b,c=0,t;
	vector<int> v;
	cin >> n;
	for(i=0;i<n;i++)
	{
		cin >> a;
		v.push_back(a);
	}
	for(i=0;i<n;i++)
	{
		if(i==0&&v[i]==1)
		{
			for(j=1;j<n;j++)
			if(v[j]!=1)
			{t=v[i];v[i]=v[j];v[j]=t;c+=j;break;}
		}
		else if(i==n-1&&v[i]==n)
		{
			for(j=n-2;j>=0;j--)
			if(v[j]!=n)
			{t=v[i];v[i]=v[j];v[j]=t;c+=n-1-j;break;}
		}
		else if(i<n-1&&i>0)
		{
			if(i+1==v[i])
			{
				for(j=i+1;j<n;j++)
				if(v[j]!=i+1)
				{a=j;break;}
				for(j=i-1;j>=0;j--)
				if(v[j]!=i+1)
				{b=j;break;}
				if(a-i>i-b) j=b;
				else j=a;
				{t=v[i];v[i]=v[j];v[j]=t;c+=abs(j-i);}
			}
		}
	}
	cout << c;
	return 0;
}