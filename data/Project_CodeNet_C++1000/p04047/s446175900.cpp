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
#define COUT(x) cout<<(x)<<endl

int main(){
    int n;
    cin >> n;
    int a[2*n];
    REP(i,2*n){
        cin >> a[i];
    }
    sort(a,a+2*n);
    int ans = 0;
    for(int i=0;i<2*n;i+=2){
        ans += a[i];
    }
    COUT(ans);
    return 0;
} 