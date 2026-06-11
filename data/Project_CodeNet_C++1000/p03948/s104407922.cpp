#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    ll N, T;
    cin >> N >> T;
    ll A[N + 5];
    map<ll, ll> mp;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    ll max_v = -20000000000000;
    ll min_v = A[0];
    for (int i = 1; i < N; i++)
    {
        max_v = max(max_v, A[i] - min_v);
        min_v = min(min_v, A[i]);
    }
    ll dis = max_v;
    ll cnt = 0;
    for (int i = 0; i < N; i++)
    {
        mp[A[i]]++;
        if (mp[A[i] - dis])
        {
            cnt++;
        }
    }
    if(T<=1)cout<<0<<endl;
    else cout<<cnt<<endl;
}