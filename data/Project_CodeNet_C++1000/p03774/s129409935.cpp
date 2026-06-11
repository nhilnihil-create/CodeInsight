#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9;
using namespace std;
using ll = long long;
int main() {
    int n , m;
    cin >> n >> m;
    vector<int> a(n), b(n), c(m), d(m);
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }   
    for(int i = 0; i < m; i++) {
        cin >> c[i] >> d[i];
    }
 
    for(int i = 0; i < n; i++){
        int MIN = 1001001001;
        int ans = -1;
        for(int j = 0; j < m; j++){
            if(abs(a[i] - c[j]) + abs(b[i] - d[j]) < MIN){
                MIN = abs(a[i] - c[j]) + abs(b[i] - d[j]);
                ans = j;
            }
        }
        cout << ans + 1 << endl;
    }
    return 0;
}