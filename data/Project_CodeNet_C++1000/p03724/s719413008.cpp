#include<bits/stdc++.h>
#define fi first
#define se second
#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define rrep(i, n) for (int (i) = 1; (i) <= (n); (i++))
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define pb push_back
#define eb emplace_back
#define yn {puts("Yes");}else {puts("No");}
#define printd(x) printf("%.12f\n", ans);
template<class T> bool chmin(T& a, const T& b) {if (a > b) {a = b; return 1;} return 0;}
template<class T> bool chmax(T& a, const T& b) {if (a < b) {a = b; return 1;} return 0;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void) {
    int n, m;
    cin >> n >> m;
    int a[m], b[m];
    rep (i, m) cin >> a[i] >> b[i];

    vector<int> num(n + 1, 0);
    bool ok = true;
    rep (i, m) {
        num[a[i]]++;
        num[b[i]]++;
    }
    rrep (i, n) if (num[i] % 2) ok = false;
    
    cout << (ok ? "YES" : "NO") << endl;
    return 0;
}