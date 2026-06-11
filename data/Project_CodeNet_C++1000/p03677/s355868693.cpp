#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(a) a.begin(), a.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;
typedef long long ll;
const ll inf = 100000000000000;

int main(){

    int n, m;
    cin >> n >> m;

    vector<ll> a(n);
    rep(i, n){ cin >> a[i]; a[i]--; }

    ll now = 0, cnt = 0, sum = 0;
    vector<int> start(m, 0), end(m, 0);
    vector<ll> plus(m, 0);
    rep(i, n - 1){
        a[i + 1] += sum;
        if(a[i + 1] <= a[i]){ a[i + 1] += m; sum += m; }
        if(a[i + 1] - a[i] <= 1){ now++; continue; }
        start[(a[i] + 1) % m]++;
        end[a[i + 1] % m]++;
        plus[a[i + 1] % m] += a[i + 1] - a[i] - 1;
        if(m - a[i] % m <= a[i + 1] - a[i]){ now += a[i + 1] % m + 1; cnt++; } 
        else now += a[i + 1] - a[i]; 
    }

    ll ans = inf;
    rep(i, m){
        chmin<ll>(ans, now);
        if(i)cnt += start[i];
        cnt -= end[i];
        now += plus[i];
        now -= cnt;
    }

    cout << ans << endl;
    return 0;

}