#include <bits/stdc++.h>
using namespace std;
#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define sqrep(i,cc,n) for(long long i=cc;i*i<=n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    deque<ll>ans;
    rep(i, 0, n){
        ll a;
        cin >> a;
        if(i%2==0)ans.push_back(a);
        else ans.push_front(a);
    }
    if(n%2==0){
        rep(i, 0, n){
            cout << ans[i] << " ";
        }
        cout << endl; 
    }else{
        reverse(ans.begin(), ans.end());
        rep(i, 0, n){
            cout << ans[i] << " ";
        }
        cout << endl; 
    }
}