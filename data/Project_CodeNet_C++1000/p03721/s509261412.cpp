#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;

// input
int N;
ll K;
vector<int> A, B;


void input() {
    cin >> N >> K;
    A = B = vector<int>(N);
    rep(i, N) cin >> A[i] >> B[i];
}


int main() {
    input();
    vector<P> w;
    rep(i, N) w.push_back(P(A[i], B[i]));
    sort(w.begin(), w.end());
    ll x = 0;
    rep(i, N) {
        x += w[i].second;
        if (K <= x) {
            cout << w[i].first << endl;
            return 0;
        }
    }
}
