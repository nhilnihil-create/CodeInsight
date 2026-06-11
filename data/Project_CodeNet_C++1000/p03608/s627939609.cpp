#include "bits/stdc++.h"

using namespace std;

const long long MAX = 1000000000000000000;

void Main() {
    long long N, M, R;
    cin >> N >> M >> R;
    vector<long long> r(R, 0);
    for (long long i = 0; i < R; ++i) {
        cin >> r[i];
        --r[i];
    }
    sort(r.begin(), r.end());

    vector<vector<long long> > towns(N, vector<long long>(N, MAX));
    for (long long i = 0; i < M; ++i) {
        long long a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;
        towns[a][b] = c;
        towns[b][a] = c;
    }
    for (long long i = 0; i < N; ++i) {
        towns[i][i] = 0;
    }

    for (long long k = 0; k < N; ++k) {
        for (long long i = 0; i < N; ++i) {
            for (long long j = 0; j < N; ++j) {
                towns[i][j] = min(towns[i][j], towns[i][k] + towns[k][j]);
            }
        }
    }

    long long ans = MAX;
    do {
        long long dist = 0;
        for (long long i = 1; i < R; ++i) {
            long long from = r[i - 1];
            long long to = r[i];
            dist += towns[from][to];
        }
        ans = min(dist, ans);
        //for (int i = 0; i < R; ++i) {
        //    cout << r[i] << " ";
        //}
        //cout << dist << endl;
    } while (next_permutation(r.begin(), r.end()));

    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
