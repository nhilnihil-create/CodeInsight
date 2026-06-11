#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;

// input
int N, M;
vector<int> A, B;


void input() {
    cin >> N >> M;
    A = B = vector<int>(M);
    rep(i, M) cin >> A[i] >> B[i];
}


int main() {
    input();
    vector<int> w(N);
    rep(i, M) {
        w[A[i] - 1]++;
        w[B[i] - 1]++;
    }
    rep(i, N) cout << w[i] << endl;
}
