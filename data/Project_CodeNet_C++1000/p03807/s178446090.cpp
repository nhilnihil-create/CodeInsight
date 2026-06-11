#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll N;
    ll ans = 0;
    cin >> N;
    ll even = 0;
    ll odd = 0;
    for (ll i = 0; i < N; ++i)
    {
        ll temp;
        cin >> temp;
        if (temp % 2 != 0)
        {
            ++odd;
        }
        else
        {
            ++even;
        }
    }
    if (odd % 2 != 0)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }
}
