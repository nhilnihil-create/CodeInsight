#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    int N; cin >> N;
    string S; cin >> S;
    vector<int> d(N);
    int ka = 0, ko = 0;
    int x = 0;
    rep(i,N) {
        if (S.at(i) == '(') ka++; else ko++;
        d.at(i) = ka - ko;
        x = min(x, d[i]);
    }
    
    rep(i, -x) cout << '(';
    cout << S;
    rep(i, d[N-1]-x) cout << ')';
    cout << endl;
}
