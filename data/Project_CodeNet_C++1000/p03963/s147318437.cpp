#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n, k;
    cin >> n >> k;
    ll x = k;
    x*=pow(k-1, n-1);
    cout << x;
}

