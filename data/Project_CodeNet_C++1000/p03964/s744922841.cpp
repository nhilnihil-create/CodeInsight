#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#define endl "\n"
#define ll long long int
using namespace std;

ll div_ceil(ll a, ll b)
{
    ll s = a / b;
    if (a % b != 0) s++;
    return s;
}

int main()
{
    ll n;
    cin >> n;

    ll ans = 0;
    ll prevA = 1, prevB = 1;
    while(n --)
    {
    	ll a, b;
    	cin >> a >> b;
    	
    	ll fact = max(div_ceil(prevA, a), div_ceil(prevB, b));
    	prevA = fact * a;
    	prevB = fact * b;

    }
    ans = prevA + prevB;
    cout << ans << endl;
}