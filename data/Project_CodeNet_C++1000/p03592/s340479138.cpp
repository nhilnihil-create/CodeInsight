#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define REP(i, n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    rep(i, n + 1){
        rep(j, m + 1){
            if(i * j + (n - i) * (m - j) == k){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}
