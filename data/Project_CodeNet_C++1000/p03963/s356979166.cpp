#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, k;
    cin >> n >> k;
    if(n==1) {cout << k << endl; return 0;}
    ll ans = k;
    rep(i,n-1){
        ans*=(k-1);
    }
    cout << ans << endl;
    return 0;
}