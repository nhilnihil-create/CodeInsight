#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (ll (i) = 0 ; (i) < (ll)(n) ; ++(i))
#define REPN(i, m, n) for (ll (i) = m ; (i) < (ll)(n) ; ++(i))
#define REP_REV(i, n) for (ll (i) = (ll)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (ll (i) = (ll)(n) - 1 ; (i) >= m ; --(i))

#define INF 2e9
#define INF_LL 1LL<<60
#define ll long long

typedef pair<int, int> P;

int main(){
    int n, k;
    cin >> n >> k;
    int ans = n;
    vector<int> a(n);
    REP(i, n) cin >> a[i];

    sort(a.begin(), a.end());

    int tmp = 0;
    REP_REV(i, n) {
        tmp += a[i];
        if(tmp >= k) {
            ans = i;
            int tmpp = tmp - a[i];
            while(i > 0) {
                if(tmpp + a[i-1] >= k) {
                    ans = i-1;
                    i--;
                } else {
                    tmp = tmpp;
                    break;
                }
            }
            //tmp = 0;
        }
    }

    cout << ans << endl;

    return 0;
}