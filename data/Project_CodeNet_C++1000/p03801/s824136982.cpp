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

int N;
pii A[100100];//(個数,番号)
int Ans[100100];

signed main() {
    cin >> N;
    rep(i, N) {
        int a;
        cin >> a;
        A[i] = pii(a, i);
    }
    A[N] = pii(0, N + 2);
    sort(A, A + N + 1, greater<pii>());
    int minv = INF;
    int cnt = 0;
    rep(i, N) {
        minv = min(minv, A[i].second);
        int d = A[i].first - A[i + 1].first;
        cnt++;
        Ans[minv] += d * cnt;
    }
    rep(i, N) {
        cout << Ans[i] << endl;
    }
    return 0;
}
