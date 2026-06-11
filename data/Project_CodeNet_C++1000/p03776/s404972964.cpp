#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(int i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(int i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(int i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define uniq(x) (x).erase(unique((x).begin(), (x).end()), (x).end())

vector<vector<ll>> pascal;

void init_pascal(int n) {
    pascal.resize(n + 1);
    
    rep(i, n + 1) {
        pascal[i].resize(i + 1, 1);
        
        if (i < 2) {
            continue;
        }
        
        reps(ii, 1, i) {
            pascal[i][ii] = pascal[i - 1][ii - 1] + pascal[i - 1][ii];
        }
    }
}

ll combination(int n, int r) {
    if (n < r) {
        return 0;
    }
    
    return pascal[n][r];
}

string get_average(ll sum, int n) {
    ll l = sum / n;
    double d = (double)(sum % n) / n;
    char ds[10];
    char res[30];
    snprintf(ds, sizeof(ds), "%.6f", d);
    snprintf(res, sizeof(res), "%lld%s", l, ds + 1);
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n, a, b;
    cin >> n >> a >> b;
    vector<ll> v(n);
    rep(i, n) cin >> v[i];
    sort(all(v), greater<ll>());
    ll sum = 0, ans = 0;
    int acnt = 0, gcnt = 0;
    init_pascal(50);
    
    rep(i, a) {
        sum += v[i];
    }
    
    rep(i, n) {
        if (v[i] == v[a - 1]) {
            acnt++;
        }
        else if (v[i] > v[a - 1]) {
            gcnt++;
        }
    }
    
    if (acnt == 1) {
        ans = 1;
    }
    else {
        if (gcnt == 0) {
            reps(i, a, b + 1) {
                ans += combination(acnt, i - gcnt);
            }
        }
        else {
            ans += combination(acnt, a - gcnt);
        }
    }
    
    cout << get_average(sum, a) << endl;
    cout << ans << endl;
    return 0;
}