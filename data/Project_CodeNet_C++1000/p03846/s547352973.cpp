#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

const int mod = 1000000007;
int main() {
    int n;
    cin >> n;
    map<int,int>mp;
    rep(i,n) {
        int a;
        cin >> a;
        mp[a]++;
    }
    if(n%2==1) {
        if(mp[0]>1) {
            cout << 0 << endl;
            return 0;
        }
    }
    if(n%2==0) {
        if(mp[0] > 0) {
            cout << 0 << endl;
            return 0;
        }
    }
    rep(i,100005) {
        if(mp[i] > 2) {
            cout << 0 << endl;
            return 0;
        }
    }
    ll ans = 1;
    for(int i = 1;i<=100000;i++) {
        if(mp[i] > 0) {
            ans *= mp[i];
            ans %= mod;
        }
    }
    cout << ans << endl;
}