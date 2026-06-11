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
    int N,M;
    cin>>N>>M;
    map<int,bool> m;
    m[0]=true;
    map<int,int> cnt;
    rep(i,N) cnt[i]=1;
    rep(i,M){
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        if(m[x]){
            if(cnt[x]==1) {
                m[x] = false;
                m[y] = true;
            }
            else {
                m[y] = true;
            }
        }
        cnt[x]--;
        cnt[y]++;
    }
    int ans = 0;
    rep(i,N) {
        if(m[i])ans++;
    }
    cout<<ans<<endl;
}