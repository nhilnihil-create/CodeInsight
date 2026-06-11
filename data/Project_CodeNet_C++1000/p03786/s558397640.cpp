#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<ll> cum(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(),a.end());
    rep(i,n){
        if(i == 0){
            cum[i] = a[i];
            continue;
        }
        cum[i] = cum[i-1] + a[i];
    }
    // rep(i,n) cout << a[i] <<endl;
    // rep(i,n) cout << cum[i] <<endl;
    int cnt = 1;
    for(int i = n-2;i >= 0;i--){
        //cout << cum[i] << " " << a[i+1] << endl;
        if(cum[i]*2 < a[i+1]) break;
        // cout << cnt << endl;
        // cout << " " << cum[i] << endl;
        cnt++;
    }

    cout << cnt << endl;
}
