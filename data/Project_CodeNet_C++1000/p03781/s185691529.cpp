#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;

ll n;
bool check(ll x)
{
    if(x * (x + 1) >= 2 * n)
        return true;
    return false;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    ll x = sqrt(n * 2);
    if(check(x - 1))
        cout << x - 1 << endl;
    else
    if(check(x))
        cout << x << endl;
    else
        cout << x + 1 << endl;


    return 0;
}
