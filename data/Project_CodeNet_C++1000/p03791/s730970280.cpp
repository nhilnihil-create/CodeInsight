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
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

#define MOD 1000000007

int main() {
    int n;
    cin >> n;
    VI x(n), f(200100);
    VL a(n);
    REP(i,n){
        scanf("%d", &x[i]);
        x[i]--;
    }
    x[0] = 0;
    FOR(i,1,n-1){
        if (x[i-1] < x[i] - 1) x[i] = x[i-1] + 2;
    }
    REP(i,n) f[x[i]] = 1;
    // REP(i,2*n) cout << f[i];
    // cout << endl;
    int p = 0, q = 0;
    a[0] = 1;
    FOR(i,1,n-1){
        a[p]++;
        if (x[i-1] < x[i] - 2)
            x[i] -= q;
        else
            q = 0;
        // REP(j,n) cout << x[j] << " ";
        // cout << "   " << i << endl;
        if (x[i-1] == x[i] - 1){
            p++;
            q++;
            x[i]--;
        }
    }
    ll ans = 1, s = 0;
    REP(i,n){
        s += a[i];
        ans = (ans * s) % MOD;
        s--;
    }
    // REP(i,n) cout << a[i];
    // cout << endl;
    cout << ans << endl;

    return 0;
}