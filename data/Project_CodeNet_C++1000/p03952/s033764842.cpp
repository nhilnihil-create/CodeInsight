#include <iostream>
#include <vector>
using namespace std;

void solve(int N, int x) {
    if (x <= 1 || x >= N*2-1) {
        cout << "No" << endl;
        return;
    }

    cout << "Yes" << endl;
    vector<int> res(N*2-1, -1);
    res[N-2] = 1;
    res[N-1] = x;
    res[N] = N*2-1;
    int iter = 0;
    for (int v = 2; v < N*2-1; ++v) {
        if (v == x) continue;
        while (res[iter] != -1) ++iter;
        res[iter] = v;
    }
    for (auto v : res) cout << v << endl;
}

int main() {
    int N, x;
    cin >> N >> x;
    solve(N, x);
}