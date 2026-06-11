#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)
#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a)  (a).begin(),(a).end()
#define endl "\n"

template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
typedef long long ll;

void solve() {
    int N;
    bool is_amaring = false;
    cin >> N;
    ll ans = 0;
    REP(i,N) {
        int a;
        cin >> a;
        if(is_amaring) {
            if(a > 0) {
                a--;
                ans++;
            }
            is_amaring = false;
        }
        if(a%2) is_amaring = true;
        ans+=(a/2);
    }
    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}