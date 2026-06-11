#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define all(obj) (obj).begin(), (obj).end()
#define rall(obj) (obj).rbegin(), (obj).rend()
#define collect(arr, size) rep(i,size) cin >> arr[i];
#define int long long

int x_flip[] = {0,1,0,1};
int y_flip[] = {0,0,1,1};

signed main(){
    int x, y; cin >> x >> y;
    int ans = INT_MAX;
    rep(i, 4){
        int tx = x_flip[i] ? -x : x;
        int ty = y_flip[i] ? -y : y;
        int btn = ty - tx + x_flip[i] + y_flip[i];
        if(btn > 0) ans = min(ans, btn);
    }
    cout << ans << endl;
    return 0;
}