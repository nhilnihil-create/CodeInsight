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
    int n,k;
    cin >> n >> k;
    int a[k];
    int max1 = 0;
    REP(i,k){
        cin >> a[i];
        max1 = max(a[i],max1);
    }
    if (n-2*max1>0)COUT(0);
    else COUT(2*max1-n-1);
    return 0;
} 
