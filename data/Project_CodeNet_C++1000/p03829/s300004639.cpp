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
    ll n, a, b;
    cin >> n >> a >> b;

    ll i;
    vector <ll> v(n);
    for(i = 0; i < n; i ++)
    	cin >> v[i];

    ll totalCost = 0;

    for(i = 0; i < n - 1; i ++)
    {
    	totalCost = totalCost + min(b, (v[i + 1] - v[i]) * a);
    }
    cout << totalCost << endl;
}
