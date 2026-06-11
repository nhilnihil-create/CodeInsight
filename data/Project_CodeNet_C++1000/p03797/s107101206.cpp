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
    ll n, m;
    cin >> n >> m;

    ll ans;

    if(m <= 2 * n)
    	ans = m / 2;
    else
    {
    	m = m - 2 * n;
    	ans = n + (m / 4);
    }
    cout << ans << endl;
}