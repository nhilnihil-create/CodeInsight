#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> A(N), B(N);
    rep(i,N) cin >> A.at(i);
    rep(i,M) cin >> B.at(i);
    rep(i,N-M+1) {
        rep(j,N-M+1) {
            bool include = true;
            rep(k,M) {
                rep(l,M) {
                    if (B.at(k).at(l) != A.at(i + k).at(j + l)) {
                        include = false;
                    }
                }
            }
            if (include) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}
