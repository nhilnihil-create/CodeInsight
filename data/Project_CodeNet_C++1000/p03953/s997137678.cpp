#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

ll n, m;
ll k;
vector <ll> a, v, swaps;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0, x ; i < n && cin >> x ; i++)
        a.push_back(x);
    vector <ll> b;
    for(ll i = 1 ; i < n ; i++)
        b.push_back(a[i] - a[i - 1]);
    cin >> m >> k;
    for(ll i = 0, x ; i < m && cin >> x ; i++)
        swaps.push_back(x - 2);
    vector <ll> plain, s;
    for(ll i = 0 ; i < n - 1 ; i++)
        plain.push_back(i);
    s = plain;
    for(auto &i : swaps)
        swap(s[i], s[i + 1]);
    v.resize(s.size());
    for(ll i = 0 ; i < (ll)s.size() ; i++)
        v[s[i]] = i;
    vector <ll> ans(v.size());
    vector <ll> vis(v.size());
    for(ll i = 0 ; i < n ; i++){
        if(vis[i]) continue;
        vector <ll> c;
        ll cur = i;
        while(vis[cur] == 0){
            c.push_back(cur);
            vis[cur] = 1;
            cur = v[cur];
        }
        for(ll i = 0 ; i < (ll)c.size() ; i++)
            ans[c[i]] = c[(k + i) % c.size()];
    }
    vector <ll> res(v.size());
    for(ll i = 0 ; i < (ll)ans.size() ; i++)
        res[ans[i]] = b[i];
    ll cur = a[0];
    cout << cur << " ";
    for(auto &i : res){
        cur += i;
        cout << cur << " ";
    }
    cout << endl;
}
