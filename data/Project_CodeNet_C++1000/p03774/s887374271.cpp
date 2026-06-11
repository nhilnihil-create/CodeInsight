#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int A[N], B[N], C[M], D[M], ans[N];
    for(int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }
    for(int i = 0; i < M; i++) {
        cin >> C[i] >> D[i];
    }
    for(int i = 0; i < N; i++) {
        int x = A[i];
        int y = B[i];
        int min_dist = abs(x - C[0]) + abs(y - D[0]);
        int res = 1;
        for(int j = 0; j < M; j++) {
            int dist = abs(x - C[j]) + abs(y - D[j]);
            if(dist < min_dist) {
                min_dist = dist;
                res = j+1;
            }
        }
        ans[i] = res;
    }
    for(int i = 0; i < N; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}