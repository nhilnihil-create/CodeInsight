#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <iomanip>
#define endl "\n"
#define ll long long int
using namespace std;

ll binCoeff(ll n, ll r)
{
	ll res = 1;
	if(r > n - r)
		r = n - r;

	for(ll i = 0; i < r; i ++)
	{
		res = res * (n - i);
		res = res / (i + 1);
	}
	return res;
}

ll fastExp(ll base, ll exp)
{
	ll result = 1;
	while(exp > 0)
	{
		if(exp % 2 == 1)
			result = result * base;
		base = base * base;
		exp /= 2;
	}
	return result;
}

int main()
{
    ll n, a, b;
    cin >> n >> a >> b;

    vector <ll> v(n);

    for(ll i = 0; i < n; i ++)
    {
    	cin >> v[i];
    }
    sort(v.begin(), v.end(), greater<ll>());

    ll sum = 0;
    for(ll i = 0; i < a; i ++)
    	sum = sum + v[i];

    ll lastIndex = a - 1;
    double avg = (double)sum / (lastIndex + 1);
    for(ll i = a; i < b; i ++)
    {
    	if(v[i] > avg)
    	{
    		sum = sum + v[i];
    		lastIndex = i;
    		avg = (double)sum / (lastIndex + 1);
    	}
    }

    ll inc = 0, exc = 0;
    for(int i = 0; i < n; i ++)
    {
    	if(v[i] == v[lastIndex] && i <= lastIndex)
    	{
    		inc ++;
    		exc ++;
    	}
    	else if(v[i] == v[lastIndex] && i > lastIndex)
    		exc ++;
    }
    cout << fixed << setprecision(6) << avg << endl;
    ll poss = 0;

    if(v[0] == v[lastIndex])
    {
    	poss = fastExp(2, exc);
	    for(int i = 0; i < inc; i ++)
	    {
	    	poss = poss - binCoeff(exc, i);
	    }

	    for(int i = b + 1; i <= exc; i ++)
	    	poss = poss - binCoeff(exc, i);
    }
    else
    	poss = binCoeff(exc, inc);
    // cout << inc << " " << exc << endl;
    cout << poss << endl;
}