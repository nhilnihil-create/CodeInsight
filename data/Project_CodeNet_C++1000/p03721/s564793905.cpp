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
    ll N,K;
    cin>>N>>K;
    vector<P> v(N);
    rep(i,N) cin>>v[i].first>>v[i].second;
    sort(v.begin(),v.end());
    ll p = 0;
    rep(i,N){
        if(p+v[i].second>=K) {
            cout<<v[i].first<<endl;
            break;
        } 
        p += v[i].second;
    }
}