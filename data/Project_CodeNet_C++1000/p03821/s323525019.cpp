#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    ll cnt = 0;
    rep(i,n) cin >> a[i] >> b[i];
    for(int i = n-1; i >= 0; --i){
        a[i]+=cnt;
        if(a[i]%b[i]==0) continue;
        cnt += b[i]- a[i]%b[i];
        a[i] += cnt;
    }
    cout << cnt << endl;
    return 0;
}