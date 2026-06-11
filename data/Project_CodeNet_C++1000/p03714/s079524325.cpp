#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    ll n; cin >> n;
    vector<ll> a(3 * n);
    for(ll i = 0; i < n * 3; i++)cin >> a[i];
    priority_queue<ll, vector<ll>, greater<ll>> front;

    ll sumf = 0, sumb = 0;
    for(ll i = 0; i < n; i++){ 
        front.push(a[i]);
        sumf += a[i];
    }
    vector<pair<ll,ll>> b;
    vector<bool> seen(n * 3);
    for(ll i = n; i < 3 * n; i++) b.emplace_back(a[i], i);
    sort(b.begin(), b.end());
    for(ll i  = 0; i < n; i++) {
        seen[b[i].second] = true;
        sumb += b[i].first;
    }

    vector<pair<ll,ll>> que;
    for(ll i = n; i < 2 * n; i++)que.push_back(b[i]);
    reverse(que.begin(), que.end());

    ll res = sumf - sumb;
    //cerr <<res << endl;
    for(ll i = n; i < 2 * n; i++) {
        //cerr << sumf << " :: " << sumb << endl;
        sumf += a[i];
        front.push(a[i]);
        sumf -= front.top();
        front.pop();
        //ここまでは正しい
        

        if(seen[i] && que.size()) {
            sumb -= a[i];
            while(que.back().second < i)que.pop_back();
            sumb += que.back().first;
            seen[que.back().second] = true;
            que.pop_back();
        }
        //cerr << sumf << " :::: " << sumb << endl;
        res = max(res, sumf - sumb);

    }
    cout << res << endl;
}