#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

int main() {
    int n,m,k;
    cin >> n >> m >> k;
    
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            if (i*(m-j) + j*(n-i) == k){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}