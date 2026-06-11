#include <bits/stdc++.h>
#include <math.h>
#define rep(i,n) for (int i=0;i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    ll tmp = 0;
    ll ans = 1e9;
    rep(i,n){
        cin >> a[i];
    }
    sort(ALL(a));
    for(int i = -100;i<=100;i++){
        tmp = 0;
        rep(j,n){
            tmp += (a[j]-i)*(a[j]-i);
        }
        ans = min(tmp,ans);
    }
    cout << ans << endl;
}