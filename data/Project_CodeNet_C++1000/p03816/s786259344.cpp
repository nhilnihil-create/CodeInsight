#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    int N; cin >> N;
    map<int,int> M;
    rep(i,N) {
        int j; cin >> j;
        M[j]++;
    }
    int k = M.size();
    if (k % 2 == 1)
        cout << k << endl;
    else
        cout << k - 1 << endl;
}
