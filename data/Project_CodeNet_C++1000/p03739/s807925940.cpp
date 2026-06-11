#include<iostream>    
#include<cstdio>  
#include<stdio.h>  
#include<cstring>    
#include<cstdio>    
#include<climits>    
#include<cmath>   
#include<vector>  
#include <bitset>  
#include<algorithm>    
#include <queue>  
#include<map>  
#include<stack>
using namespace std;
 
long long int ans1, ans2, sum1, sum2;
int n, i;
long long int a[100005];
int main()
{
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	if (a[1] >0)
	{
		sum1 = a[1];
		ans2= a[1] + 1;
		sum2 = -1;
	}
	else if (a[1] == 0)
	{
		sum1 = 1;
		ans1 = ans2 = 1;
		sum2 = -1;
	}
	else 
	{
		sum1 = 1;
		ans1 = abs(a[1]) + 1;
		sum2 = a[1];
	}
	for (i = 2; i <= n; i++)
	{	
		if (sum1 > 0)
		{
			if (a[i] + sum1 >= 0)
			{
				ans1 += a[i] + sum1 + 1;
				sum1 = -1;
			}
			else
			{
				sum1 += a[i];
			}
		}
		else
		{
			if (a[i] + sum1 <= 0)
			{
				ans1 += abs(sum1 + a[i]) + 1;
				sum1 = 1;
			}
			else
			{
				sum1 += a[i];
			}
		}
	}
	if (sum1 == 0)
	{
		ans1++;
	}
	for (i = 2; i <= n; i++)
	{
		if (sum2 > 0)
		{
			if (a[i] + sum2 >= 0)
			{
				ans2 += a[i] + sum2 + 1;
				sum2 = -1;
			}
			else
			{
				sum2 += a[i];
			}
		}
		else
		{
			if (a[i] + sum2 <= 0)
			{
				ans2 += abs(sum2 + a[i]) + 1;
				sum2 = 1;
			}
			else
				sum2 += a[i];
		}
	}
	if (sum2 == 0)
	{
		ans2++;
	}
	cout << min(ans1, ans2) << endl;
}
