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

const int MX_N = 1e5+5;

int N, M;
vector<int> al[MX_N];
bool used[MX_N];

int main() {
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    FOR(i,0,M-1){
        int A, B; cin >> A >> B;
        al[A].push_back(B);
        al[B].push_back(A);
    }

    deque<int> dq;
    dq.push_front(1); used[1] = 1;
    dq.push_back(al[1][0]); used[al[1][0]] = 1;
    while (true) {
        bool done = true;
        for (int v : al[dq.front()]) if (!used[v]) {
            dq.push_front(v);
            used[v] = true;
            done = false;
            break;
        }
        if (done) break;
    }
    while (true) {
        bool done = true;
        for (int v : al[dq.back()]) if (!used[v]) {
            dq.push_back(v);
            used[v] = true;
            done = false;
            break;
        }
        if (done) break;
    }

    cout << SZ(dq) << '\n';
    for (auto x : dq) cout << x << ' ';
}

