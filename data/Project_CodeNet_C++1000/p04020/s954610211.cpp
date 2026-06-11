#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

int main() {
    ll N;
  	cin>>N;
    vector<ll> v(N);
    for(ll i = 0; i < N; i++) cin>>v[i];
    vector<ll> cnt;
    ll t = 0;
    for(ll i = 0; i < N; i++){
        t += v[i];
        if(i==N-1||v[i+1]==0) {
            cnt.push_back(t);
            t=0;
        }
    }
    ll ans = 0LL;
    for(auto x:cnt) ans+=x/2;
    cout<<ans<<endl;
}