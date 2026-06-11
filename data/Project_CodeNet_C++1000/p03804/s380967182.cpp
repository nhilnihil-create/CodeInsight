#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
 
#define rp(i, k, n) for (int i = k; i < n; i++)
using ll = long long;
using ld = double;

template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7ll;
// const ll MOD = 998244353;
const double PI=3.14159265358979323846;



int main() {
    int m, n;
    cin >> n >> m;
    vector<string> A(n), B(m);
    string s;
    rp(i, 0, n) {
        cin >> s; A[i] = s;
    }
    rp(i, 0, m) {
        cin >> s; B[i] = s;
    }
    rp(i, 0, n-m+1) {
        rp(j, 0, n-m+1) {
            bool is_same = true;
            rp(k, 0, m) {
                rp(l, 0, m) {
                    if(B[k][l] != A[i+k][j+l]) {
                        is_same = false;
                        break;
                    }
                }
                if(is_same == false) break;
            }
            if(is_same) {
                cout << "Yes" << endl;
                return 0;
            }
        } 
    }
    cout << "No" << endl;
    return 0;
}
