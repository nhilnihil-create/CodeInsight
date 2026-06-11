#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;
const int INT_INF = 1e9;
const ll INF = 1LL << 30;

int main() {
    int n, m; cin >> n >> m;
    V<string> a(n);
    V<string> b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    bool ans = false;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i + m - 1 >= n || j + m - 1 >= n) continue;
            bool flag = true;
            for(int k = 0; k < m; k++){
                for(int l = 0; l < m; l++){
                    if(a[i + k][j + l] != b[k][l]) flag = false;
                }
            }
            if(flag) ans = true;
        }
    }
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}
