#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N));
    for(int i=0; i<N; ++i) {
        for(int j=0; j<N; ++j) cin >> A[i][j];
    }

    vector<vector<int>> dist(A);
    for(int k=0; k<N; ++k) {
        for(int i=0; i<N; ++i) {
            for(int j=0; j<N; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    long long res = 0;
    for(int i=0; i<N; ++i) {
        for(int j=i+1; j<N; ++j) {
            if(dist[i][j] < A[i][j]) {
                cout << -1 << endl;
                return 0;
            } else {
                int k=0;
                for(; k<N; ++k) {
                    if(k == i || k == j) continue;
                    if(dist[i][j] == dist[i][k] + dist[k][j]) break;
                }
                if(k == N) res += A[i][j];
            }
        }
    }

    cout << res << endl;
}