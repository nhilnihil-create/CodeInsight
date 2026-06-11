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
    ll x;
    cin >> x;

    ll ans;
    ans = (x / 11) * 2;

    if(x % 11 == 0)
    {
    	cout << ans << endl;
    } 
    else
    {
    	x = x % 11;
    	if(x > 6)
    		cout << ans + 2 << endl;
    	else
    		cout << ans + 1 << endl;
    }
}