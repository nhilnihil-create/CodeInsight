#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp setprecision
#define pb(x) push_back(x)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = 1e9;
const ll INF = 1e18;
const ld EPS = 1e-10;
const string alpha = "abcdefghijklmnopqrstuvwxyz";

int main(){
    int N;
    cin >> N;
    pli p[N];
    rep(i, N){
        cin >> p[i].first;
        p[i].second = i;
    }
    sort(p, p+N);
    ll sum[N+1];
    sum[0] = 0, sum[1] = p[0].first*N;
    rep2(i, 2, N){
        sum[i] = sum[i-1]+(p[i-1].first-p[i-2].first)*(N+1-i);
    }
    ll ans[N];
    fill(ans, ans+N, 0);
    vector<int> steps;
    int now = inf;
    rep3(i, N-1, 0){
        if(i>0 && p[i-1].first == p[i].first) continue;
        if(p[i].second < now){
            steps.pb(i+1);
            now = p[i].second;
        }
    }
    steps.pb(0);
    sort(steps.begin(), steps.end());
    int n = steps.size();
    rep2(i, 1, n-1){
        int j = steps[i], k = steps[i-1];
        ans[p[j-1].second] = sum[j]-sum[k];
    }
    rep(i, N){
        cout << ans[i] << endl;
    }
}