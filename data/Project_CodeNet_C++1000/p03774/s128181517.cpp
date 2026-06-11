#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M; cin >> N >> M;
    vector<vector<int>> student(N, vector<int>(2));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> student.at(i).at(j);
        }
    }
    vector<vector<int>> cp(M, vector<int>(2));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> cp.at(i).at(j);
        }
    }
    
    for (int i = 0; i < N; i++) {
        vector<pair<int, int>> key(M);
        for (int j = 0; j < M; j++) {
            int dst;
            dst = abs(student.at(i).at(0) - cp.at(j).at(0)) + abs(student.at(i).at(1) - cp.at(j).at(1));
            key.at(j) = make_pair(dst, j + 1);
        }
        sort(key.begin(), key.end());
        cout << key.at(0).second << endl;
    }
}