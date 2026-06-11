#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
ll const mod = 1e9+7;

#define p_ary(ary,a,b,i) do { cout << "["; for (int (i) = (a);(i) < (b);++(i)) cout << ary[(i)] << ((b)-1 == (i) ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

int main() {
    int n;
    cin >> n;
    ll ans = 1;
    vector<int> x(n);
    for (int i = 0;i < n;++i) cin >> x[i];
    int j = 0,r = -1;
    for (int i = 0;i < n;++i) {
        while (j < n) {
            r += 2;
            j++;
            if (r > x[j-1]) break;
        }
        (ans *= (r+1)/2) %= mod;
        r -= 2;
    }
    cout << ans << endl;
}