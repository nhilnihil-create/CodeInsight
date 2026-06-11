#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll k,t;
    cin >> k >> t;
    priority_queue<pair<ll,ll>> pq;
    for(i = 0;i < t;++i){
        ll a;
        cin >> a;
        pq.emplace(a, i);
    }
    auto x = pq.top();
    ll num = x.first;
    ll tmp = x.second;
    --num;
    pq.pop();
    if(num != 0){
        pq.emplace(num, tmp);
    }
    while(!pq.empty()){
        auto x = pq.top();
        pq.pop();
        if(tmp != x.second){
            --x.first;
            tmp = x.second;
            if(x.first != 0) pq.emplace(x);
        }else{
            if(pq.empty()){
                cout << x.first << endl;
                return 0;
            }else{
                auto y = pq.top();
                pq.pop();
                tmp = y.second;
                --y.first;
                pq.emplace(x);
                if(y.first != 0) pq.emplace(y);
            }
        }
    }
    cout << 0 << endl;
    return 0;
}