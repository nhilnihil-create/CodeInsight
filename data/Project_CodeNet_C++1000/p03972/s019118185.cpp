#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

int main() {
    ll n, m, i, j, k;
    ll H, W;
    cin >> W >> H;
    vector<ll> p(W),q(H);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
    for(i=0;i<W;i++){
        cin >> p[i];
        pq.push({p[i],1});
    }
    for(i=0;i<H;i++){
        cin >> q[i];
        pq.push({q[i],0});
    }
    ll ret = 0,cnt = 0;
    H++;
    W++;
    while(H!=1 || W!=1){
        ll cost = pq.top().first;
        ll x = pq.top().second;
        pq.pop();
        if(x==0){
            ret+=cost*W;
            H--;
        }else {
            ret+=cost*H;
            W--;
        }
    }
    cout << ret << endl;
    return 0;
}