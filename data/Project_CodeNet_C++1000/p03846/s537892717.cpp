#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#define endl "\n"
#define mod 1000000007
#define ll long long int
using namespace std;

int main()
{
    ll n;
    cin >> n;

    map <ll, ll> mp;

    ll i, data;
    for(i = 0; i < n; i ++)
    {
    	cin >> data;
    	mp[data] ++;
    }
    
    ll count = 0;
    ll flag = 0;
    ll ans = 1;
    if(n % 2 == 0)
    {
    	for(i = 0; i < n / 2; i ++)
    	{
    		if(mp[2 * i + 1] == 2)
    		{
    			ans = (ans % mod * 2) % mod;
    			count ++;
    		}
    		else
    		{
    			flag = 1;
    			break;
    		}
    	}

    	if(flag == 0 && count == n / 2)
    		cout << ans << endl;
    	else
    		cout << "0" << endl; 
    }
    else if(n % 2 == 1)
    {
    	if(mp[0] != 1)
    		flag = 1;
    	for(i = 1; i <= n / 2; i ++)
    	{
    		if(mp[2 * i] == 2)
    		{
    			ans = (ans % mod * 2) % mod;
    			count ++;
    		}
    		else
    		{
    			flag = 1;
    			break;
    		}
    	}

    	if(flag == 0)
    		cout << ans << endl;
    	else
    		cout << "0" << endl; 
    }
}