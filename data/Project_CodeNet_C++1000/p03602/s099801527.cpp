#include <bits/stdc++.h>

#define MAX_N 300

using namespace std;

typedef pair<int, int> P;

int N;
int A[MAX_N][MAX_N];

long long solve()
{
    long long answer = 0;
    P b[MAX_N];
    for (int u = 0; u < N; u++) {
        for (int i = 0; i < N; i++) {
            b[i] = P(A[u][i], i);
        }
        sort(b, b + N);
        // b[0] == (0, i);
        for (int i = 1; i < N; i++) {
            int v = b[i].second;
            if (v > u) {
                continue;
            }
            bool needRoad = true; // need a road between city u and v with length A[u][v].
            for (int j = 1; j < i; j++) {
                int w = b[j].second;
                int determinant = A[u][w] + A[w][v] - A[u][v];
                if (determinant < 0) {
                    return -1;
                }
                if (determinant == 0) {
                    needRoad = false;
                    break;
                }
            }
            if (needRoad) {
                answer += A[u][v];
            }
        }
    }
    return answer;
}

int main(void)
{
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }
    cout << solve() << endl;
    return 0;
}
