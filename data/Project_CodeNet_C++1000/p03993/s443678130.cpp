#include <bits/stdc++.h>
#define FASTIO
using namespace std;

using ll = long long;
using Vi = vector<int>;
using Vl = vector<ll>;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

constexpr int I_INF = numeric_limits<int>::max();
constexpr ll L_INF = numeric_limits<ll>::max();

//==================================

int main() {
#ifdef FASTIO
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
#endif
#ifdef FILEINPUT
    ifstream ifs("./in_out/input.txt");
    cin.rdbuf(ifs.rdbuf());
#endif

    int N;
    cin >> N;
    Vi A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        --A[i];
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (A[A[i]] == i) {
            ++cnt;
        }
    }

    cout << cnt / 2 << endl;

    return 0;
}