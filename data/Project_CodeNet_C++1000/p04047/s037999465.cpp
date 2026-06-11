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
    vector<int> l(2*n);
    rep(i,0,2*n) cin>>l[i];
    sort(all(l));
    int ans=0;
    for(int i=0; i<2*n; i+=2){
        ans+=l[i];
        // debug(i);
    }
    cout<<ans<<endl;
}