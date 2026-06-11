#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int n, x;
    cin >> n >> x;
    int ans = n;

    int a = n-x;
    int b = x;
    while(1){
        ans += (a/b) * b * 2;
        a %= b;
        if(a == 0){
            ans -= b;
            break;
        }
        int tmp = b;
        b = a;
        a = tmp;
    }

    cout << ans << endl;
    return 0;
}