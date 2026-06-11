#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
typedef long long ll;
typedef pair<ll,ll> P;

int main(){
    ll w, h;
    cin >> w >> h;
    ll p, q;
    priority_queue<P,vector<P>,greater<P>> que;
    rep(i,w) {
        cin >> p;
        que.push(P(p,0));
    }
    rep(i,h) {
        cin >> q;
        que.push(P(q,1));
    }
    ll ans = 0;
    ll n = 0;
    p = w + 1; q = h + 1;
    while(!que.empty()){
        P a = que.top();
        que.pop();
        if(a.second == 0) {
            ans += a.first*q;
            p--;
        } else {
            ans += a.first*p;
            q--;
        }
    }
    cout << ans << endl;
    return 0;
} 