#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
typedef long long ll;
int main(){
    int n,t; cin >> n >> t;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int mini = 1e9+7;
    int diff_maxi = -1e9-7;
    int ans = 0;
    rep(i,n-1){
        mini = min(mini, a[i]);
        int diff = a[i+1] - mini;
        if(diff_maxi < diff){
            ans = 1;
            diff_maxi = diff;
        }
        else if(diff_maxi == diff) ans++;
    }
    cout << ans << endl;
}

