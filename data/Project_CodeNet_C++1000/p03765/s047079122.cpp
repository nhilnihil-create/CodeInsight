#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int(i) = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define pb push_back
#define MP(a, b) make_pair((a), (b))
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;

int main() {
    string S, T;
    cin >> S >> T;
    int N = S.size(), M = T.size();
    vector<int> SAsum(N + 1), SBsum(N + 1), TAsum(M + 1), TBsum(M + 1);
    rep(i, N) {
        if(S[i] == 'A')
            SAsum[i + 1]++;
        else
            SBsum[i + 1]++;
    }
    rep(i, M) {
        if(T[i] == 'A')
            TAsum[i + 1]++;
        else
            TBsum[i + 1]++;
    }
    rep(i, N) {
        SAsum[i + 1] += SAsum[i];
        SBsum[i + 1] += SBsum[i];
    }
    rep(i, M) {
        TAsum[i + 1] += TAsum[i];
        TBsum[i + 1] += TBsum[i];
    }
    int q;
    cin >> q;
    rep(i, q) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        int a = SAsum[r1] - SAsum[l1 - 1];
        int b = SBsum[r1] - SBsum[l1 - 1];
        int c = TAsum[r2] - TAsum[l2 - 1];
        int d = TBsum[r2] - TBsum[l2 - 1];
        int diff = a - c;
        b += diff * 2;
        if(abs(b - d) % 3 == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}