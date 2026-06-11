#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;
const int INT_INF = 1e9;
const ll INF = 1LL << 30;
const ll MOD = 1e9 + 7;


int main() {
    int h, w; cin >> h >> w;
    int n; cin >> n;
    V<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    V<V<int> > ans(h);
    int x = 0, y = 0, ite = 0;
    bool r = true;
    for(int i = 0; i < h * w; i++){
        if(i != 0 && (x == w || x == 0)){
            y++;
            r = !r;
        }
        if(r){
            ans[y].push_back(ite + 1);
            a[ite]--;
            x++;
        }else{
            ans[y].push_back(ite + 1);
            a[ite]--;
            x--;
        }

        if(a[ite] == 0) ite++;
    }

    for(int i = 0; i < h; i++){
        if(i & 1) reverse(ALL(ans[i]));
        for(int j = 0; j < w; j++){
            if(j != w - 1) cout << ans[i][j] << " ";
            else cout << ans[i][j] << endl;
        }
    }
}
