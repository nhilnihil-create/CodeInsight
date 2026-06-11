#include<iostream>
#include<math.h>
#include<string>
#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n,inp,ans1=0,ans2=0,sum=0,k1,k2;
	cin>>n;
	vector<long long> v;
	for(long long i=0;i<n;i++)
	{
		cin>>inp;
		sum+= inp;
		v.push_back(inp);
	}
	k1= sum/n;
	k2= sum/n+1;
	for(int i=0;i<(int)v.size();i++)
	{
		ans1+=(k1-v[i])*(k1-v[i]);
	}
	for(int i=0;i<(int)v.size();i++)
	{
		ans2+=(k2-v[i])*(k2-v[i]);
	}
	cout<<min(ans1,ans2)<<endl;
return 0;
}