#include<bits/stdc++.h>

using namespace std;
using ll = long long;




int main()
{
    ll n; cin >> n;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++)cin >> a[i];
    vector<ll> nind;
    vector<ll> sum(n);
    sum[0] = a[0];
    for(ll i = 1; i < n; i++)sum[i] = max(sum[i - 1], a[i]);

    for(ll i = n - 1; i >= 1; i--) {
        if(sum[i] != sum[i - 1])nind.push_back(i);
    }
    nind.push_back(0);


    map<ll,ll,greater<ll>> mp;
    vector<ll> ans(n);
    ll past = n;
    ll m = nind.size();
    reverse(nind.begin(), nind.end());

    for(ll i = m - 1; i >= 0; i--) {

        for(ll j = past-1; j >= nind[i]; j--) {
            mp[a[j]]++;
        }
        


        vector<ll> del;
        for(auto j : mp) {
            if(i!=0){
            if(j.first <= a[nind[i-1]])break;}
            ans[nind[i]] += (j.first * j.second) - (i == 0 ? 0 : a[nind[i - 1]]) * j.second;
            // cerr << i << ": " << j << endl;
            del.push_back(j.first);
        }
        // prvec(del);
        if(i==0)break;
        for(auto j : del) {
            mp[a[nind[i-1]]] += mp[j];
            mp.erase(j);
        }



        past = nind[i];

    }
    for(ll i = 0; i < n; i++)cout << ans[i] << endl;
    
}