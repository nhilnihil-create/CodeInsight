#include<bits/stdc++.h>
#include<cstdio>
#include<string>  
#include<algorithm>
#include<cmath>  
#include<iostream>
#include<queue>
#include<cstdlib>
#include<cstring>
#define maxn 200000
#define ll long long
using namespace std;
ll a[maxn]={0}; 
int main()
{
	int n,i;
	ll x;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&x);
		a[i]=a[i-1]+x;
	}
	ll sum=10000000000000;
	for(i=1;i<n;i++)
	{
		sum=min(sum,abs(a[i]-(a[n]-a[i])));
	}
	printf("%lld",sum);	
	//freopen("名字.in","r",stdin);
	//freopen("名字.out","w",stdout);
	return 0;
 }
