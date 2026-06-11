#include <bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

int N, T;

void solve() {
    cin >> N >> T;
    multiset<int> st;
    int mn = (int) 1e9+1;
    int mx = 0;
    rep(i,N) {
        int a;
        cin >> a;
        mn = min(mn, a);
        st.insert(a - mn);
        mx = max(mx, a - mn);
    }
    cout << st.count(mx) << endl;
}

int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);
    solve();
    return 0;
}
