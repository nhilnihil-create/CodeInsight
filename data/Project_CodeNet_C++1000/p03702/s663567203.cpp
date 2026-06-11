#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <queue> 
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <set>
using namespace std;
long long d[10000000],m,a,b;
bool isans(long long ex)
{
	long long dam=ex*b;
	long long sum=0;
	for (long long i=m-1;d[i]>dam;i--)
		sum+=(d[i]-dam-1)/(a-b)+1;
	return sum<=ex;
}

int main()
{
	cin>>m;
	cin>>a>>b;
	for(long long i=0;i<m;i++)
		cin>>d[i];
	sort(d,d+m);
	long long left=d[m-1]/a,right=(left+1)*m;
	while (left<right)
	{
		long long mid=(left+right)/2;
		if (isans(mid)) right=mid;
		else left=mid+1;
	}
	cout<<left<<endl;
}