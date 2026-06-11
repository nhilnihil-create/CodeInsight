#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;



int main() {

    int n; cin >> n;
    vector<ll> a(n);
    int ans = 1;
    rep(i,n) cin >> a[i];

    if(n == 1 || n == 2) cout << 1;
    else{
        vector<ll> b;
        rep(i,n-1){
            if(a[i+1]-a[i] > 0) b.push_back(1);
            if(a[i+1]-a[i] < 0) b.push_back(-1);
        }
        rep(i,b.size()-1){
            if(b[i]!= b[i+1]){
                ans ++;
                i ++;
            }
        }
        cout << ans;
    }



    return 0;
}









