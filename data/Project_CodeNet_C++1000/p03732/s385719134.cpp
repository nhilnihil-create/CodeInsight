#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll mod = 1000000007;





int main()
{
    ll n,d;
    cin >> n >> d;
    vector<ll> w(n), v(n);
    for(ll i = 0; i < n; i++)cin >> w[i] >> v[i];
    ll base = w[0];
    vector<ll> cnt(4);
    vector<vector<ll>> val(4);
    for(ll i = 0; i < n; i++){
        cnt[w[i] - w[0]]++; 
        val[w[i] - w[0]].push_back(v[i]);
    }
    for(ll i = 0; i < 4; i++)sort(val[i].begin(), val[i].end(), greater<ll>());



    //m個取る
    ll ans = 0;
    for(ll i = 0; i <= cnt[0]; i++){
        for(ll j = 0; j <= cnt[1]; j++){
            for(ll t = 0; t <= cnt[2]; t++){
                for(ll l = 0; l <= cnt[3]; l++){
                    ll m = i + j + t + l;
                    ll lim = d - base * m;
                    if(i * 0 + j * 1 + t * 2 + l * 3 > lim)continue;
                    ll sum = 0;

                    for(ll q = 0; q < i; q++)sum += val[0][q];
                    for(ll q = 0; q < j; q++)sum += val[1][q];
                    for(ll q = 0; q < t; q++)sum += val[2][q];
                    for(ll q = 0; q < l; q++)sum += val[3][q];
                    ans = max(ans, sum);
                }
            }
        }
    }
    cout << ans << endl;
}