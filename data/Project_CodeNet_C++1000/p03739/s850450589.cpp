#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#define endl "\n"
#define ll long long int
using namespace std;

int main()
{
    ll n;
    cin >> n;

    ll i;
    vector <ll> v(n);
    for(i = 0; i < n; i ++)
    	cin >> v[i];

    ll preSum = 0;
    ll ans1 = 0;
    ll ans2 = 0;
    for(i = 0; i < n; i ++)
    {
    	preSum = preSum + v[i];
    	if(i % 2 == 1)
    	{
    		if(preSum >= 0)
    		{
    			ans1 = ans1 + preSum + 1;
    			preSum = -1;
    		}
    	}
    	else
    	{
    		if(preSum <= 0)
    		{
    			ans1 = ans1 + abs(preSum) + 1;
    			preSum = 1;
    		}
    	}
    }

    preSum = 0;
    for(i = 0; i < n; i ++)
    {
    	preSum = preSum + v[i];
    	if(i % 2 == 1)
    	{
    		if(preSum <= 0)
    		{
    			ans2 = ans2 + abs(preSum) + 1;
    			preSum = 1;
    		}
    	}
    	else
    	{
    		if(preSum >= 0)
    		{
    			ans2 = ans2 + abs(preSum) + 1;
    			preSum = -1;
    		}
    	}
    }
    ll ans = min(ans1, ans2);
    cout << ans << endl;
}