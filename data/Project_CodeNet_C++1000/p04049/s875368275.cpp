#include <cstdio>
#include <climits>
#include <vector>
using namespace std;

bool AssignMin(int* p, int v) {
    if (v < *p) return *p = v, true;
    return false;
}

bool AssignMax(int* p, int v) {
    if (*p < v) return *p = v, true;
    return false;
}

struct Solution {
    int N, K;
    vector<vector<int> > Out;
    vector<int> Distance;

    void SetDistanceToMax() {
        Distance.resize(N);
        for (int i = 0; i < N; ++i) Distance[i] = INT_MAX;
    }

    void DFS(int start) {
        for (int i = 0; i < Out[start].size(); ++i) {
            int target = Out[start][i];
            if (AssignMin(&Distance[target], Distance[start] + 1)) {
                DFS(target);
            }
        }
    }

    int VisitedSize(int limit) {
        int answer = 0;
        for (int i = 0; i < N; ++i) {
            if (Distance[i] <= limit) ++answer;
        }
        return answer;
    }

    int EvenCase() {
        int answer = 0;
        for (int i = 0; i < N; ++i) {
            SetDistanceToMax();
            Distance[i] = 0;
            DFS(i);
            AssignMax(&answer, VisitedSize(K / 2));
        }
        return answer;
    }

    int OddCase() {
        int answer = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < Out[i].size(); ++j) {
                int target = Out[i][j];
                SetDistanceToMax();
                Distance[i] = Distance[target] = 0;
                DFS(i);
                DFS(target);
                AssignMax(&answer, VisitedSize(K / 2));
            }
        }
        return answer;
    }

    void Solve() {
        scanf("%d%d", &N, &K);
        Out.resize(N);
        for (int i = 1; i < N; ++i) {
            int v1, v2;
            scanf("%d%d", &v1, &v2);
            Out[v1 - 1].push_back(v2 - 1);
            Out[v2 - 1].push_back(v1 - 1);
        }
        int answer = K % 2 == 0 ? EvenCase() : OddCase();
        printf("%d\n", N - answer);
    }
};

int main() {
    Solution().Solve();
    return 0;
}
