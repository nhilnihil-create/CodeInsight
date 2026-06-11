#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

#define ll long long

int main()
{
    ll N;
    scanf("%lld", &N);
    vector<ll> L(N * 2);
    vector<ll> diff(N * 2, 0);
    for (ll i = 0; i < N * 2; i++)
        scanf("%lld", &L[i]);

    sort(L.begin(), L.end());

    ll sum1 = 0, sum2 = L[0];
    for (ll i = 1; i < N * 2; i++)
    {
        diff[i] = L[i] - L[i - 1];
        if (i % 2 == 1)
        {
            sum1 += L[i - 1];
        }
        else
        {
            sum2 += L[i - 1];
        }
    }
    ll ans = 0;

    printf("%lld\n", max(sum1, sum2));
}
