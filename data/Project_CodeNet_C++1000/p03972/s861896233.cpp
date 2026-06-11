#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using P = pair<ll,ll>;
using grid = vector<vector<int>>;

const int dx[2] = {1, 0};
const int dy[2] = {0, 1};
const int INF = 1<<30;
const ll mod = 998244353LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    ll W,H;
    cin>>W>>H;
    vector<ll> p(W),q(H);
    rep(i,W) cin>>p[i];
    rep(i,H) cin>>q[i];
    ll t = H+1LL,s = W+1LL;
    priority_queue<P,vector<P>,greater<P>> A;
    rep(i,W) A.push(make_pair(p[i],0));
    rep(i,H) A.push(make_pair(q[i],1));
    ll ans = 0LL;
    while(!A.empty()){
        P x = A.top();
        A.pop();
        if(x.second == 0){
            ans += x.first*t;
            s--;
        }
        if(x.second == 1){
            ans += x.first*s;
            t--;
        }
    }
    cout<<ans<<endl;
}