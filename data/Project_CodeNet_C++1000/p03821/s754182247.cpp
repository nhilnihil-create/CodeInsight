#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<iomanip>
#include<map>
#include<cstring>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9;
const ll LLINF = 4 * 1e18;
/* -- template -- */

int main() {
    int N; cin >> N;
    ll A[N], B[N];
    rep(i, N) cin >> A[i] >> B[i];
    ll add = 0;
    for(int i = N - 1;i >= 0;--i) {
        if((A[i] + add) % B[i] != 0)
            add += B[i] - (A[i] + add) % B[i];
    }
    cout << add << endl;
}
