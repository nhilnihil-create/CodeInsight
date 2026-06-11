#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;

// input
int N;
vector<int> L, R;


void input() {
    cin >> N;
    L = R = vector<int>(N);
    rep(i, N) cin >> L[i] >> R[i];
}


int main() {
    input();
    int ans = 0;
    rep(i, N) ans += R[i] - L[i] + 1;
    cout << ans << endl;
}
