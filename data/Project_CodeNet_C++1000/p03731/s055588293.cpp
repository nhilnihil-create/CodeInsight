#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main()
{
    ll N,T;
    cin >> N >> T;
    vector<ll> t(N);
    for(ll i = 0; i < N; i++)
    {
        cin >> t[i];
    }
 
    ll count = 0;
 
    for(ll i = 1; i < N; i++)
    {
        if(T <= (t[i] - t[i-1]))count += T;
        else count += t[i] - t[i-1];
    }
    count += T;
 
    cout << count << endl;
    return 0;
}