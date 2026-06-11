#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;
using ld = long double;
const int MOD = 1e9+7;


int main() {
    int n; cin >> n;
    V<int> v(n);
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        a--;
        v[i] = a;
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        if(v[v[i]] == i) {
            ans++;
            v[v[i]] = -1;
        }
    }
    cout << ans << endl;

    return 0;
}
