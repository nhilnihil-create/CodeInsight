#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<queue>
#include<cstdio>
using namespace std;
int main()
{
	int n;
	int x,sum=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		sum+=x;
	}
	if(sum%2==0)cout<<"YES";
	else cout<<"NO";
	return 0;
}