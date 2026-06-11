#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#define endl "\n"
#define ll long long int
#define mod 1000000007
using namespace std;

int main()
{
    ll n, i, j;
    cin >> n;

    vector <bool> primes(n + 1, true);
    primes[0] = false;
    primes[1] = false;

    vector <ll> primeList;

    for(i = 2; i <= sqrt(n); i ++)
    {
    	if(primes[i] == true)
    	{
	    	for(j = 2; i * j <= n; j ++)
	    	{
	    		primes[i * j] = false;
	    	}    		
    	}

    }

    for(i = 2; i <= n; i ++)
    {
    	if(primes[i] == true)
    		primeList.push_back(i);
    }

    map <ll, ll> mp;

    for(i = 2; i <= n; i ++)
    {
    	ll val = i;
    	for(ll num: primeList)
    	{
    		if(num * num > val)
    			break;
    		while(val % num == 0)
    		{
    			mp[num] ++;
    			val = val / num; 
    		}
    	}

    	if(val > 1)
    		mp[val] ++;
    }

    ll ans = 1;
	for(auto it = mp.begin(); it != mp.end(); it ++)
	{
		ans = ((ans % mod) * (((it -> second) + 1) % mod)) % mod;
	}
	cout << ans << endl;
}