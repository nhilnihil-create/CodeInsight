#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)

typedef long long ll;
typedef pair<int, int> P;

const int MAX = 1e5 + 5;
const int INF = 1001001001;
const int MOD = 1e9 + 7;

int main(){
    int N, L;
    cin >> N >> L;

    vector<int> A(N);
    rep(i, N) cin >> A[i];

    int res = -1;
    rep(i, N-1) {
        if (L <= A[i] + A[i+1]) {
            res = i;
            break;
        }
    }

    if (res < 0) {
        puts("Impossible");
        return 0;
    }

    puts("Possible");
    rep(i, res) {
        cout << i + 1 << endl;
    }

    for (int i = N-2; i > res; --i) {
        cout << i + 1 << endl;
    }

    cout << res + 1 << endl;
}