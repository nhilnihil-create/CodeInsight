#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n, a[110];
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    pair<ll, ll> p[210];
    for(int i = -100; i <= 100; i++)
    {
        ll sum=0;
        for(int j = 0; j < n; j++)
            sum+=(a[j]-i)*(a[j]-i);
        p[i+100] = make_pair(sum, i);
    }
    sort(p, p+201);
    cout << p[0].first;
}

