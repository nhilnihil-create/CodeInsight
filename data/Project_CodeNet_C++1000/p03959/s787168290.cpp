#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MOD 1000000007

signed main(){
    int n;
    cin >> n;

    int a[100010];
    int b[100010];
    for(int i = 0;i < n;i++) cin >> a[i];
    for(int i = 0;i < n;i++) cin >> b[i];

    int c[100010] = {};
    c[0] = 1;

    for(int i = 1;i < n;i++){
        if(a[i] != a[i-1]){
            c[i] = 1;
        }
    }

    if(b[0] != a[n-1]){
        cout << 0 << endl;
        return 0;
    }

    c[n-1] = 1;

    for(int i = n-2;i >= 0;i--){
        if(b[i] != b[i+1]){
            if(b[i] > a[i]){
                cout << 0 << endl;
                return 0;
            }else{
                c[i] = 1;
            }
        }else{
            if(c[i] == 0){
                c[i] = min(a[i], b[i]);
            }
        }
    }

    int ans = 1;
    for(int i = 0;i < n;i++){
        ans = (ans * c[i]) % MOD;
    }

    cout << ans << endl;
    return 0;
}