#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int, int>;

int main() {

    int N, M;
    cin >> N >> M;

    int A[50], B[50];

    rep(i, M) cin >> A[i] >> B[i];

    int road[50];
    rep(i, N) road[i] = 0;

    rep(i, M) {
        road[A[i]-1] += 1;
        road[B[i]-1] += 1;
    }

    rep(i, N) cout << road[i] << endl;

    return 0;
}