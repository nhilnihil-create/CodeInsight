#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
#define int long long

int next_combination(int bit) {
    int x = bit & -bit, y = bit + x;
    return (((bit & ~y) / x) >> 1) | y;
} /*(1<<k)-1から列挙*/

signed main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int cost = 1e17;
    for (int i = (1<<k) - 1; i < (1<<n); i = next_combination(i)) {
        int tmp = 0;
        int height = 0;
        for (int j = 0; j < n; ++j) {
            if(i & (1<<j)){
                if(height < a[j]){
                    height = a[j];
                    continue;
                }
                else{
                    tmp += height - a[j] + 1;
                    height++;
                    continue;
                }
            }
            height = max(height, a[j]);
        }
        cost = min(cost, tmp);
    }
    cout << cost << endl;
}