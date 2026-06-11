#include <iostream>
#include <vector>

using namespace std;
constexpr int64_t INF = 1'000'000'000'000'000'000;

int main(void) {
    int N, A;
    cin >> N >> A;
    vector<int> x(N);
    for(int i=0; i<N; i++) {
        cin >> x[i];
    }

    vector< vector<int64_t> > cnt(N+1, vector<int64_t>(50*N+1, INF));
    cnt[0][0] = 1;

    for(int i=0; i<N; i++) {
        for(int j=i; j>=0; j--) {
            for(int k=50*N-x[i]; k>=0; k--) {
                if(cnt[j][k] != INF) {
                    if(cnt[j+1][k+x[i]] == INF) {
                        cnt[j+1][k+x[i]] = cnt[j][k];
                    } else {
                        cnt[j+1][k+x[i]] += cnt[j][k];
                    }
                }
            }
        }
    }

    int64_t ans = 0;
    for(int j=1; j<=N; j++) {
        for(int k=1; k<=50*N; k++) {
            if(j*A == k && cnt[j][k] != INF) {
                ans += cnt[j][k];
            }
        }
    }

    cout << ans << endl;
    return 0;
}
