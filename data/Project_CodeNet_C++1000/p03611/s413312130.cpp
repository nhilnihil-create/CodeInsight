#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll N = 0;
    cin >> N;
    vector<ll> A(N,0);
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    map<int, int> m;
    int ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = -1; j < 2; j++) {
            if(!m.count(A.at(i) + j)) {
                m[A.at(i) + j] = 0;
            }
            m.at(A.at(i) + j)++;
            ans = max(ans, m.at(A.at(i) + j));
        }
    }

    cout << ans << endl;



    return 0;
}