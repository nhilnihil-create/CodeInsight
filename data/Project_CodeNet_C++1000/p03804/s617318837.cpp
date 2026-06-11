#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;
using ld = long double;
const int MOD = 1e9+7;
const ll INF = 1LL << 60;


int main() {
    int n, m; cin >> n >> m;
    V<string> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    V<string> b(m);
    for(int i = 0; i < m; i++) cin >> b[i];

    for(int i = 0; i < n - m + 1; i++){
        for(int j = 0; j < n - m + 1; j++){
            int y = i;
            int x = j;
            bool flag = true;
            for(int k = 0; k < m; k++){
                for(int l = 0; l < m; l++){
                    if(b[k][l] == a[y][x]) x++;
                    else{
                        flag = false;
                        break;
                    }
                }
                y++;
                x = j;
            }
            if(flag){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;

    return 0;
}
