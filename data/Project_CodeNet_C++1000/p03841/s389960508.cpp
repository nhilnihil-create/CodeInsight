#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()
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

int main(){
    int N; cin >> N;
    pii p[N];
    rep(i, N){
        cin >> p[i].first;
        p[i].first--;
        p[i].second = i+1;
    }
    sort(p, p+N);
    int now = 0;
    vector<int> ans(N*N, 0);
    rep(i, N){
        //k番目のkのidがpos(0-indexed)である
        int pos = p[i].first, k = p[i].second;
        rep(j, k-1){
            while(ans[now]) now++;
            if(now >= pos) {cout << "No" << endl; return 0;}
            ans[now] = k;
        }
        ans[pos] = k;
    }
    now = N*N-1;
    rep3(i, N-1, 0){
        //k番目のkのidがpos(0-indexed)である
        int pos = p[i].first, k = p[i].second;
        rep(j, N-k){
            while(ans[now]) now--;
            if(now <= pos) {cout << "No" << endl; return 0;}
            ans[now] = k;
        }
    }
    cout << "Yes" << endl;
    rep(i, N*N) cout << ans[i] << ' ';
    cout << endl;
}