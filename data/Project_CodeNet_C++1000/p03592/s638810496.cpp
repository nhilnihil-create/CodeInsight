#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;


int main() {
    int n, m, k; cin >> n >> m >> k;

    for(int i = 0; i <= n; i++){
        int sum = i * m;
        for(int j = 0; j <= m; j++){
            int tmp = sum + j * n - 2 * j * i;
            if(tmp == k){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;

    return 0;
}
