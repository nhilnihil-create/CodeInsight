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

int main() {
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M; cin >> N >> M;
    bool check[N+1] = {0};
    FOR(i,0,M-1){
        int A, B; cin >> A >> B;
        check[A] ^= 1;
        check[B] ^= 1;
    }
    bool ok = 1;
    FOR(i,1,N) ok &= !check[i];
    cout << (ok ? "YES" : "NO");
}

