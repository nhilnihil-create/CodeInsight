#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
// #include <cmath>
// #include <string>

using namespace std;
// typedef unsigned long long ull;


template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "[";
    for (const auto i : v) {
        os << i << " ";
    }
    os << "]";
    return os;
}

template<typename T>
ostream& operator<<(ostream& os, const set<T>& s) {
    os << "[";
    for (const auto i : s) {
        os << i << " ";
    }
    os << "]";
    return os;
}

template<typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
    os << "(" << p.first << "," << p.second << ")";
    return os;
}


int main(int argc, char const *argv[]) {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> D(N), dist(N);
    for (int i = 0; i < N; i++) {
        D[i].resize(N, -1);
        dist[i].resize(N, 1000000);
        dist[i][i] = 0;
    }
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a -= 1;
        b -= 1;
        D[a][b] = D[b][a] = dist[a][b] = dist[b][a] = c;
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
            }
        }
    }

    // cout << "dist\n";
    // cout << dist << endl;

    set<pair<int, int>> used;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (D[i][j] == -1) continue;
            for (int k = 0; k < N; k++) {
                if (dist[i][k] == D[i][j] + dist[j][k]) {
                    used.insert(make_pair(min(i, j), max(i, j)));
                    break;
                }
            }
        }
    }
    // cout << used << endl;

    cout << M - used.size() << endl;

    return 0;
}
