#include <bits/stdc++.h>
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define per(i, n, s) for (int i = (n-1); i >= (int)(s); i--)
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<x<<endl
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;
const ll LINF = LLONG_MAX;
const int INF = INT_MAX;

int main(){
    int n; cin>>n;
    string s,t; cin>>s>>t;
    int ans=-1;
    rep(i,0,n){
        if(s.substr(i,n-i) == t.substr(0,n-i)){
            ans=n+i;
            break;
        }
    }
    if(ans==-1) ans=2*n;
    cout<<ans<<endl;
}