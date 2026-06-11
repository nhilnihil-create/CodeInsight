#include<bits/stdc++.h>
// #define int long long
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
#define MOD 1000000007
using namespace std;
using ll = long long;
typedef vector<int> vi;

signed main() {
    int a, b, c;
    bool isOK = false;
    cin >> a >> b >> c;
    rep(i, 100){
        if(a*(i+1) % b == c) isOK = true;
    }
    if(isOK) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}