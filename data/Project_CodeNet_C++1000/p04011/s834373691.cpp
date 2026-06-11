#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()

int main(){
    int n, k, x, y;
    cin >> n >> k >> x >> y;

    int ans = 0;
    ans += x * min(n, k);
    if(n - k > 0){
        ans += y * (n - k);
    }

    cout << ans << endl;
    return 0;
}