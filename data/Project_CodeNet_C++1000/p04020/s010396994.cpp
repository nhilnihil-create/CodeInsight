#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const ll INF = 1e12;
const int MOD = 1000000007;


int main() {
        int n;
        cin >> n;
        vector<ll> a(n);
        rep(i,n) cin >> a.at(i);
        ll ans = 0;
        int before = 0;
        rep(i,n){
                if( before == 1 && a[i] > 0) {ans ++; a[i] --;}
                ans += a[i]/2;
                before = a[i]%2;
        }
        cout << ans << endl;
        return 0;
}