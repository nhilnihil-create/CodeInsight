#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1e18

int N, M;
vector<queue<int>> A;

bool solve(int x) {
    vector<bool> visited(M, false);
    vector<queue<int>> B(A);
    bool ok = true;
    while (true) {
        for (int i = 0; i < N; i++) {
            while (!B[i].empty() && visited[B[i].front()]) B[i].pop();
            if (B[i].empty()) {
                ok = false;
                break;
            }
        }
        if (!ok) break;
        vector<int> cnt(M, 0);
        int cnt_max = 0, max_s = -1;
        for (int i = 0; i < N; i++) cnt[B[i].front()]++;
        for (int i = 0; i < M; i++)
            if (cnt_max < cnt[i]) {
                cnt_max = cnt[i];
                max_s = i;
            }
        if (cnt_max <= x)
            return true;
        else
            visited[max_s] = true;
    }
    return false;
}

int binary_search(int ok, int ng) {
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        if (solve(mid)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    return ok;
}

int main() {
    cin >> N >> M;
    A.resize(N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            int a;
            cin >> a;
            a--;
            A[i].push(a);
        }
    cout << binary_search(N + 1, 0) << endl;
    return 0;
}