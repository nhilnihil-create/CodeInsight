#include<iostream>
#include<stdio.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
ll node[MAX],sum; 
int n,m;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>node[i];
	node[0]=0;
	sum=0;
	for(int i=1;i<=n;i++)
	if(node[i-1]+node[i]>m)
	{
	sum=sum+node[i]-(m-node[i-1]);
	node[i]=m-node[i-1];
	}
	cout<<sum;
}