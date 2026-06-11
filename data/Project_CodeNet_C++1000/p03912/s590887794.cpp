#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> X(n);
    copy_n(istream_iterator<int>(cin), n, X.begin());
    vector<int> C(1e5 + 1), D(m), M(m);

    for (const auto &x: X){
        C[x]++;
        M[x % m]++;
    }

    for (int i = 0; i <= 1e5; i++){
        D[i % m] += C[i] / 2;
    }

    int ans = M[0] / 2;
    for (int i = 1; i <= m / 2; i++){
        auto mi = min(M[i], M[m - i]);
        if (i == m - i){
            ans += mi / 2;
        } else {
            ans += mi;
            ans += min((M[i] - mi) / 2, D[i]);
            ans += min((M[m - i] - mi) / 2, D[m - i]);
        }
    }

    cout << ans << endl;
}