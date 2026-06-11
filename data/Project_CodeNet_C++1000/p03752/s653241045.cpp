#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main(){
    int n, k, first;
    cin >> n >> k >> first;
    vector<int> a(n-1);
    rep(i,n-1) cin >> a[i];
    ll ans = 1e18;
    rep(i,1<<(n-1)){
        vector<int> b(n-1);
        b = a;
        ll sum = 0;
        if(__builtin_popcount(i)!=k-1) continue;
        int temp = first;
        rep(j,n){
            if(i>>j & 1){
                if(temp >= b[j]){
                    sum += temp - b[j] + 1;
                    b[j] = temp + 1;
                }
                temp = b[j];
            }
            temp = max(b[j], temp);
            
        }
        ans = min(ans, sum);
    }
    cout << ans << endl;
    return 0;
}