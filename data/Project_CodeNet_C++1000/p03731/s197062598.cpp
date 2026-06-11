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
    ll n, t;
    cin >> n >> t;

    vector <ll> v(n);

    for(ll i = 0; i < n; i ++)
    	cin >> v[i];

    ll currMax = 0;
    ll prev = 0;
    ll ans = 0;
    for(ll i = 0; i < n; i ++)
    {
    	if(currMax >= v[i])
    		currMax = v[i] + t;
    	else
    	{
    		ans = ans + currMax - prev;
    		prev = v[i];
    		currMax = v[i] + t;
    	}
    }

    ans = ans + currMax - prev;
    cout << ans << endl;
}