#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define COUT(x) cout<<(x)<<"\n"

int main(){
    int n,a,b;
    cin >> n >> a >> b;
    vector<int> x(n);
    REP(i,n) cin >> x[i];
    ll ans = 0;
    for(int i=1;i<n;i++){
        ll num = x[i]-x[i-1];
        if(num*a>=b){
            ans += b;
        }
        else ans += num*a;
    }
    COUT(ans);
    return 0;
}