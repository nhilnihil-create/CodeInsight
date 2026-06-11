#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

int main(){
    int n, m;
    ll k;
    cin >> n;
    VL x(n);
    REP(i,n) scanf("%lld", &x[i]);
    cin >> m >> k;
    VL y(n-1);
    REP(i,n-1) y[i] = x[i+1] - x[i];
    VI s(n-1), a(n-1);
    REP(i,n-1) a[i] = s[i] = i;
    REP(i,m){
        int d;
        scanf("%d", &d);
        d--;
        swap(s[d-1], s[d]);
    }
 
    VI so(s);
    REP(i,n-1) s[so[i]] = i;
 
    while (k){
        if (k & 1LL){
            REP(i,n-1) a[i] = s[a[i]];
        }
        VI so(s);
        REP(i,n-1) s[i] = so[s[i]];
        k /= 2;
    }
 
    VI ao(a);
    REP(i,n-1) a[ao[i]] = i;
 
    ll ans = x[0];
    cout << ans << endl;
    REP(i,n-1){
        ans += y[a[i]];
        printf("%lld\n",ans);
    }
 

    return 0;
}