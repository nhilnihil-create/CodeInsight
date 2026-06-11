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
    vi a(n);
    rep(i, n) cin >> a[i];

    int cnt = 0;
    rep(i, n){
        if(a[a[i]-1] == i+1) cnt++;
    }
    cout << cnt / 2 << endl;
}