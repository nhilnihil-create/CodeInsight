#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int a, b;
    int r[N + 1] = {0};
    rep(i, M) {
        cin >> a >> b;
        r[a]++;
        r[b]++;
    }
    for (int i = 1; i < N + 1; i++) {
        cout << r[i] << endl;
    }
    
}