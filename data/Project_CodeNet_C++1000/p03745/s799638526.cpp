#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    bool inc = false, dec = false, keep = true;
    int cmp = a[0];
    int ans = 1;
    rep(i,n){
        if(keep){
            if(a[i] == cmp) continue;
            if(a[i] < cmp) dec = true;
            else inc = true;
            keep = false;
        }
        else if(inc){
            if(a[i] < cmp){
                inc = false;
                keep = true;
                ++ans;
            }
        }
        else{
            if(a[i] > cmp){
                dec = false;
                keep = true;
                ++ans;
            }
        }
        cmp = a[i];
    }
    cout << ans << endl;
    return 0;
}
