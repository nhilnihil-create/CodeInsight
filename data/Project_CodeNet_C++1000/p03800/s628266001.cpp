#include <bits/stdc++.h>
using namespace std;

const char itos[2] = {'S', 'W'};
int id[256];

bool dif(char A, char T) {
    return (A == 'S' && T == 'x') || (A == 'W' && T == 'o');
}

string solve(int N, const string &S, int a, int b) {
    int M = S.size();
    string res(M, 'A');
    res[0] = itos[a], res[1] = itos[b];
    for(int i = 1; i < M - 1; ++i) {
        res[i + 1] = itos[id[res[i - 1]] ^ dif(res[i], S[i])];
        if(i + 1 >= N && res[i + 1 - N] != res[i + 1]) return "";
    }
    return res.substr(N);
}

int main() {
    int N; string S;
    cin >> N >> S;
    S += S;
    id['S'] = 0; id['W'] = 1;
    for(int i = 0; i < 2; ++i) {
        for(int j = 0; j < 2; ++j) {
            auto res = solve(N, S, i, j);
            if(res != "") {
                cout << res << '\n';
                return 0;
            }
        }
    }
    cout << -1 << '\n';
    return 0;
}
