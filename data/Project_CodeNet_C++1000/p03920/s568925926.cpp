#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <memory.h>
using namespace std;

const int maxn = 1e7 + 10;
bool dp[maxn];


int main()
{
	int n;
    while(cin>>n)
    {
    	int i;
    	for(i=1; i<=n; i++)
    	{
    		if(i * (i + 1) / 2 >= n) break;
    	}
    	int sum = i * (i+1) / 2;

    	vector<bool> vis(i+1, false);
    	int k = 30;

    	while(sum > n)
    	{
    		if( (1 << k) < sum && sum - (1 << k) >= n)
    		{
    			sum -= (1 << k);
    			vis[(1 << k)] = true;
    		}
    		--k;
    	}
    	for(int j=1; j<=i; j++) if(!vis[j]) cout<<j<<endl;
    }
}






