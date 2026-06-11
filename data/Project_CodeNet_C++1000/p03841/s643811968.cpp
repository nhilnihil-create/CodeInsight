#include<bits/stdc++.h>

using namespace std;
using ll = long long int;
#define long ll

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    vector<pair<ll,ll>> x(n);
    for(ll i=0; i<n; i++)
        cin >> x[i].first, x[i].first--, x[i].second = i+1;
    sort(x.begin(), x.end());

    vector<ll> res(n*n);
    for(ll i=0; i<n; i++)
        res[x[i].first] = x[i].second;

    queue<ll> www;
    queue<ll> q;

    vector<ll> rem(n+1);
    for(ll i=0; i<n; i++)
        rem[i+1] = i;
    for(ll i=0; i<n; i++)
        for(ll k=0; k<x[i].second-1; k++)
            q.push(x[i].second);

    for(ll i=0; i<n*n; i++) {
        if(res[i] > 0) {
            if(rem[res[i]]) {
                cout << "No" << endl;
                return 0;
            }
            for(ll k=0; k<n-res[i]; k++)
                www.push(res[i]);
        } else {
            if(!q.empty()) {
                res[i] = q.front(); q.pop();
                rem[res[i]]--;
            } else if (!www.empty()) {
                res[i] = www.front(); www.pop();
            } else {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;
    for(auto &e: res) cout << e << ' ';
    cout << endl;
}
