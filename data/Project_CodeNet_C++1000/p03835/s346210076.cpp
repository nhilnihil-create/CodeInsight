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
    int K,S;
    cin>>K>>S;
    int ans = 0;
    rep(i,K+1){
        if(S-i<0||S-i>2*K) continue;
        if(S-i<=K) ans += S-i+1;
        else ans += 2*K-(S-i) +1;
    }
    cout<<ans<<endl;
}