#include <bits/stdc++.h>
typedef long long lint;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

int main() {
    int n,m,k; cin >> n >> m >> k;
    bool ans = false;
    rep(i,n+1) {
        //cout << endl;
        rep(j,m+1) {
            //cout << i*m + j*n - 2*(i*j) << endl;
            //cout << "  " << i*j << endl;
            if (i*m + j*n - 2*(i*j) == k) ans = true;
        }
    }
    auto o = ans ? "Yes" : "No";
    cout << o << endl;
}
//###..
//###..
//###..

//.####
//#....
//#....