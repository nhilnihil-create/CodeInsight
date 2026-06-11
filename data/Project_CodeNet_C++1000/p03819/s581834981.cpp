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

struct BIT {
    static const int size = 100100;
    int data[size];

    void add(int a, int x) {
        while (a < size) {
            data[a] += x;
            a += a & -a;
        }
    }

    int sum(int a) {
        int res = 0;
        while (a > 0) {
            res += data[a];
            a -= a & -a;
        }
        return res;
    }
};

int N, M;
pii section[300300];//(長さ,左端)
BIT bit;

signed main() {
    cin >> N >> M;
    rep(i, N) {
        int l, r;
        cin >> l >> r;
        section[i] = pii(r - l + 1, l);
    }
    sort(section, section + N);
    int next = 0;
    for (int d = 1; d <= M; ++d) {
        while (next < N && section[next].first < d) {
            int l = section[next].second;
            int r = l + section[next].first - 1;
            next++;
            bit.add(l, 1);
            bit.add(r + 1, -1);
        }
        int ans = N - next;
        for (int s = 0; s <= M; s += d) {
            ans += bit.sum(s);
        }
        cout << ans << endl;
    }
    return 0;
}
