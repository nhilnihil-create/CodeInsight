#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    ll N; cin >> N;
    vector<ll> A(N);
    rep(i,N) cin >> A.at(i);
    ll step[2] = {0,0};
    ll sum[2] = {0,0};

    rep(i,2) {
        rep(j, N) {
            sum[i] += A[j];
            if ((i+j)%2 == 0) {
                if (sum[i] <= 0) {
                    step[i] += abs(sum[i] - 1);
                    sum[i] = 1;
                }
            } else {
                if (sum[i] >= 0) {
                    step[i] += sum[i] + 1;
                    sum[i] = -1;
                }
            }
        }
    }
    cout << min(step[0], step[1]) << endl;
}
