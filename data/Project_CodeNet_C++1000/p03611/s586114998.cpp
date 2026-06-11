#include<bits/stdc++.h>
// #define int long long
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
#define MOD 1000000007
using namespace std;
using ll = long long;
typedef vector<int> vi;

signed main() {
    int n;
    cin >> n;
    vi a(100000);
    rep(i, n){
        int tmp;
        cin >> tmp;
        a[tmp]++;
        a[tmp+1]++;
        if(tmp > 0)a[tmp-1]++;
    }

    int ans = 1;
    for(int i = 0; i <= 100000; i++){
        ans = max(ans, a[i]);
    }

    cout << ans << endl;


    return 0;
}