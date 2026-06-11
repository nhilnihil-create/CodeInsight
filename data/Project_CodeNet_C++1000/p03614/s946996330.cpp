#include <bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

int N;
int ans = 0;

void solve() {
    cin >> N;
    vi p(N);
    rep(i,N) cin >> p[i];
    int c = 0;
    rep(i,N) {
        if (p[i] == i+1) {
            c++;
        } else {
            if (c == 1) ans++;
            else if (c > 1) ans += ceil(1. * c / 2);
            c = 0;
        }
    }
    if (c == 1) ans++;
    else if (c > 1) ans += ceil(1. * c / 2);
    cout << ans << endl;
}

int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);
    solve();
    return 0;
}
