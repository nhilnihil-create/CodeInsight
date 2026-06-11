#include <bits/stdc++.h>
using namespace std;

int N;
string S;

vector<int> solve(int a, int b) {
    int M = N * 2;
    vector<int> res(M);
    res[0] = a, res[1] = b;
    for(int i = 1; i < M - 1; ++i) {
        if(S[i] == 'o') {
            if(res[i]) res[i + 1] = res[i - 1]; // S
            else res[i + 1] = 1 ^ res[i - 1]; // W
        } else {
            if(res[i]) res[i + 1] = 1 ^ res[i - 1]; // S
            else res[i + 1] = res[i - 1]; // W
        }
    }
    if(res[0] == res[N] && res[1] == res[N + 1]) return res;
    return vector<int> ();
}

int main() {
    cin >> N >> S;
    S += S;
    for(int i = 0; i < 2; ++i) {
        for(int j = 0; j < 2; ++j) {
            auto ans = solve(i, j);
            if(!ans.empty()) {
                for(int k = 0; k < N; ++k) {
                    cout << (ans[k] ? "S" : "W");
                }
                cout << '\n';
                return 0;
            }
        }
    }
    cout << -1 << '\n';
    return 0;
}
