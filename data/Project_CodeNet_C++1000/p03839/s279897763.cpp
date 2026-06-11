#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int n, k;
    cin >> n >> k;
    int a[100010];
    int sei[100010] = {};
    int wa[100010] = {};

    for(int i = 0;i < n;i++){
        cin >> a[i];
        wa[i+1] = wa[i] + a[i];
        if(a[i] > 0){
            sei[i+1] = a[i];
        }
        sei[i+1] += sei[i];
    }

    int ans = LLONG_MIN;

    for(int i = 0;i <= n-k;i++){
        int a1 = sei[i]+wa[i+k]-wa[i]+sei[n]-sei[i+k];
        int a2 = sei[n]-sei[i+k]+sei[i];
        ans = max(ans, max(a1, a2));
    }
    cout << ans << endl;
    return 0;
}
