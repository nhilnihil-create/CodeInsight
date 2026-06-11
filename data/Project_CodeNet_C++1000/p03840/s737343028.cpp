#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007LL;
const int INF = LLONG_MAX;

signed main(){
    
    int a, b, c, d, e, f, g; cin >> a >> b >> c >> d >> e >> f >> g;
    int ans = 0;

    if(a >= 1 && d >= 1 && e >= 1){
        int aa = a - 1;
        int dd = d - 1;
        int ee = e - 1;
        int tmp = b + 3 + (aa / 2) * 2 + (dd / 2) * 2 + (ee / 2) * 2;
        ans = max(ans, tmp);
    }
    
    int tmp = b + (a / 2) * 2 + (d / 2) * 2 + (e / 2) * 2;    
    ans = max(ans, tmp);
    cout << ans << endl;
    return 0;
}