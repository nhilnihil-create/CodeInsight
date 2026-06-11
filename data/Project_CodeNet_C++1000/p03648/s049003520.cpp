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

#define int long long
using namespace std;
#define rep(i, n) for(int i=0;i<(n);++i)
typedef pair<int, int> pii;
const int INF = 1l << 60;
#define u_b upper_bound
#define l_b lower_bound

int K;
const int N = 50;
int A[50];
const int e16 = 10000000000000000;

signed main() {
    cin >> K;
    K = 50 * e16 - K;
    rep(i, 50) {
        A[i] = e16 + 49 - (K / 50);
    }
    rep(i, K % 50) {
        A[i] -= 51;
    }
    rep(i, 50) {
        A[i] += K % 50;
    }
    cout << 50 << endl;
    rep(i, 50) {
        cout << (i ? " " : "") << A[i];
    }
    cout << endl;
    return 0;
}
