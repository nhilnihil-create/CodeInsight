#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int main() {
    int n;
    ll k;
    cin >> n >> k;
    map<int,ll> mp;
    rep(i,n) {
        int a,b;
        cin >> a >> b;
        mp[a] += b;
    }
    ll sum = 0;
    int ans = 0;
    rep(i,100001) {
        sum += mp[i];
        if(sum >= k) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
    
}