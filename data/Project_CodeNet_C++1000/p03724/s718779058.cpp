#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repr(i, n) for(int i = (n-1); i >= 0; --i)

typedef long long ll;
typedef pair<int, int> P;

const int MAX = 200005;
const int INF = 1001001001;
const int MOD = 1000000007;

int main(){
    int N, M;
    cin >> N >> M;

    vector<int> cnt(N);
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        cnt[a]++, cnt[b]++;
    }

    bool ans = true;
    rep(i, N) {
        ans &= !(cnt[i] % 2);
    }

    if (ans) puts("YES");
    else puts("NO");
}