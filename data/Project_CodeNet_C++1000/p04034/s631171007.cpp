#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;
using ld = long double;
const int MOD = 1e9+7;


int main() {
    int n, m; cin >> n >> m;
    map<int, int> sum, red;

    for(int i = 1; i <= n; i++) sum[i]++;
    red[1]++;

    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        if(red[x]){
            red[y]++;
            sum[y]++;
            sum[x]--;
            if(sum[x] == 0) red[x] = 0;
        }else{
            sum[x]--;
            sum[y]++;
        }
    }

    int ans = 0;
    for(auto p : red){
        if(p.second) ans++;
    }
    cout << ans << endl;

    return 0;
}
