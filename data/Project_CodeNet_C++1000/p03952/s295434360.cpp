
#pragma GCC optimize ("O3")

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include <prettyprint.hpp>
#define debug(...)  cerr << "[" << #__VA_ARGS__ << "]: ", d_err(__VA_ARGS__);
#else
#define debug(...) 83;
#endif

void d_err() {
    cerr << endl;
}

template <typename H, typename... T>
void d_err(H h, T... t) {
    cerr << h << " ";
    d_err(t...);
}

template <typename T>
void print(T x) {
    cout << x << endl;
}

#define ALL(x) (x).begin(), (x).end()
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define REVFOR(i, m, n) for (int i = (n - 1); i >= (m); --i)
#define REP(i, n) FOR(i, 0, n)
#define REVREP(i, n) REVFOR(i, 0, n)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define bcnt __builtin_popcountll

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll,ll> Pll;
typedef pair<int,int> Pin;

ll INF = 1e16;
int inf = 1e9;
ll MOD = 1e9+7;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    
    int N, x;
    cin >> N >> x;

    if (x == 1 || x == 2 * N - 1) {
        print("No");
        return 0;
    }

    vector<int> ans(2 * N - 1);

    if (x == 2) {
        ans[N - 2] = 1;
        ans[N - 1] = x;
        int cnt = 3;
        REP(i, 2 * N - 1) {
            if (ans[i] > 0) continue;
            ans[i] = cnt++;
        }
    } else if(x == 2 * N - 2) {
        ans[N - 2] = 2 * N - 1;
        ans[N - 1] = x;
        int cnt = 1;
        REP(i, 2 * N - 1) {
            if (ans[i] > 0) continue;
            ans[i] = cnt++;
        }
    } else {
        ans[N - 3] = 1;
        ans[N - 2] = 2 * N - 1;
        ans[N - 1] = x;
        ans[N] = 2;
        ans[N + 1] = 2 * N - 2;
        int cnt = 3;
        REP(i, 2 * N - 1) {
            if (ans[i] > 0) continue;
            if (cnt == x) cnt++;
            ans[i] = cnt++;
        }
    }

    print("Yes");
    REP(i, 2 * N - 1) {
        print(ans[i]);
    }
    
}
