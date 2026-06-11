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
#include <deque>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef vector<VI> VVI;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

int main() {
    int n;
    cin >> n;
    VL a(n);
    vector<char> c(n-1);
    REP(i,n){
        scanf("%lld", &a[i]);
        if (i < n-1) cin >> c[i];
    }
    VL cumsum(n+1), sum(n+1);
    REP(i,n) cumsum[i+1] = cumsum[i] + a[i];
    sum[0] = a[0];
    REP(i,n-1){
        if (c[i] == '+') sum[i+1] = sum[i] + a[i+1];
        else sum[i+1] = sum[i] - a[i+1];
    }
    ll ans = sum[n-1];
    // cout << ans << endl;
    VI neg;
    REP(i,n-1) if (c[i] == '-') neg.push_back(i);
    // cout << neg.size() << endl;
    REP(k,(int)neg.size()-1){
        int x = neg[k], y = neg[k+1];
        // cout << x << " " << y << endl;
        ll tmp = sum[x] - (cumsum[y+1] - cumsum[x+1]) + cumsum[n] - cumsum[y+1];
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}