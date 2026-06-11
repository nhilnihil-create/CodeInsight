#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ii, int> ri3;
#define mp make_pair
#define pb push_back
#define fi first
#define sc second
#define SZ(x) (int)(x).size()
#define ALL(x) begin(x), end(x) 
#define REP(i, n) for (int i = 0; i < n; ++i) 
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define RFOR(i, a, b) for (int i = a; i >= b; --i)

const int MX_N = 2005;

int N, K;
vector<int> al[MX_N];

int sub(int u, int p, int d, int k) {
    int ret = (d > k);
    for (auto v : al[u]) if (v != p) {
        ret += sub(v,u,d+1,k);
    }
    return ret;
}

int main() {
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    vector<ii> el;
    FOR(i,1,N-1){
        int A, B; cin >> A >> B;
        al[A].push_back(B);
        al[B].push_back(A);
        el.emplace_back(A,B);
    }

    int ans = N+1;
    if (K&1) {
        for(auto& e : el) {
            ans = min(ans, sub(e.fi,e.sc,0,K/2)+sub(e.sc,e.fi,0,K/2));
        }
    } else {
        FOR(i,1,N){
            ans = min(ans, sub(i,-1,0,K/2));
        }
    }

    cout << ans;
}

