#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>
#include<utility>
#include<cmath>
#include<assert.h>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<complex>
#include<bitset>

#define int long long
using namespace std;
#define rep(i, n) for(int i=0;i<(n);++i)
typedef pair<int, int> pii;
const int INF = 1l << 60;
#define u_b upper_bound
#define l_b lower_bound

int N, A, B, C, D;

signed main() {
    cin >> N >> A >> B >> C >> D;
    if (A > B)swap(A, B);
    B -= A;
    A = 0;
    rep(k, N) {
        //k回下げる、残りは上げる
        int kl = -k * D;
        int kg = -k * C;
        int bl = B - D * (N - 1 - k);
        int bg = B - C * (N - 1 - k);
        if (kg < bl || bg < kl)continue;
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;
    return 0;
}
