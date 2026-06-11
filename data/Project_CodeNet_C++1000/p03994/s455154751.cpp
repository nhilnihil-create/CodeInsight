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
    string S;
    int K;
    cin >> S >> K;
    rep(i, S.size()) {
        if(K <= 0)
            break;
        if(i == S.size() - 1) {
            K %= 26;
            rep(j, K) {
                S[i] = (char)(S[i] + 1);
                if(S[i] - 'z' > 0)
                    S[i] = 'a';
            }
            break;
        }
        int dist = S[i] == 'a' ? 0 : ('z' - S[i]) + 1;
        if(dist <= K) {
            S[i] = 'a';
            K -= dist;
        }
    }
    cout << S << endl;
    return 0;
}