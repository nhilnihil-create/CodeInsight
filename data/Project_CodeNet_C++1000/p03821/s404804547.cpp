#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define ALL(v) (v.begin(),v.end())
#define COUT(x) cout<<(x)<<'\n'

int main(){
    int n;
    cin >> n;
    ll a[n],b[n];
    ll count = 0;
    REP(i,n)cin >> a[i] >> b[i];
    for(int i=n-1;i>=0;i--){
        a[i] += count;
        ll num = b[i]-(a[i]%b[i]);
        if(num==b[i])num=0;
        count += num;
    }
    COUT(count);
    return 0;
}
