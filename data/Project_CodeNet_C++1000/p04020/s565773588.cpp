#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

//ここから。
int main(){
    int N;
    cin >> N;
    vector<int> a(N+1,0);
    rep(i,N) cin >> a[i];
    ll ans = 0;
    rep(i,N){
        ans += a[i]/2;
        a[i] %= 2;
        if(a[i] & (a[i + 1]>0)){
            ans++;
            a[i+1]--;
        }
    }
    cout << ans << endl;
}