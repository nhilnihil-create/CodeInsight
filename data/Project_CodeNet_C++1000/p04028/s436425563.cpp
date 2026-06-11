#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define repd(i, a, b) for(int i = a; i >= (b); i--)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int INF = 1e9+7;
long long INFLL = 1e17;

int N;
string s;

const int maxn = 5e3 + 5;
int DP[maxn][maxn];

int dp(int cmd, int pos) {
    if (cmd == 0) {
        return pos == s.size() ? 1 : 0;
    }
    int &ret = DP[cmd][pos];
    if (ret != -1) return ret;
    ret = dp(cmd - 1, pos + 1);
    if (pos == 0) ret += dp(cmd - 1, pos);
    else ret += dp(cmd - 1, pos - 1) * 2 % INF;
    ret %= INF;
    return ret;
}
int main() {
    cin >> N >> s;
    memset(DP, -1, sizeof DP);
    // puts("gg");
    printf("%d\n", dp(N, 0));
}
