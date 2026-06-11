#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N,0);
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        A.at(a - 1)++;
        A.at(b - 1)++;
    }
    for(int i = 0; i < N; i++) {
        cout << A.at(i) << endl;
    }

    return 0;
}