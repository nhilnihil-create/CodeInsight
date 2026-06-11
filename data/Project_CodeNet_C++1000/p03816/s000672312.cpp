/* 北さん参考 */
#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (ll (i) = 0 ; (i) < (ll)(n) ; ++(i))
#define REPN(i, m, n) for (ll (i) = m ; (i) < (ll)(n) ; ++(i))
#define REP_REV(i, n) for (ll (i) = (ll)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (ll (i) = (ll)(n) - 1 ; (i) >= m ; --(i))

#define INF 2e9
#define INF_LL 1LL<<60
#define ll long long

typedef pair<ll, ll> P;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> st;
    REP(i, n) {
        cin >> a[i];
        st.insert(a[i]);
    }
    int ans = st.size();
    sort(a.begin(), a.end());

    int p = a[0], cnt = 1;
    int gusu = 0;

    REPN(i, 1, n) {
        if(p == a[i]) {
            cnt++;
        } else {
            if(cnt % 2 == 0) gusu++;
            cnt = 1, p = a[i];
        }
    }

    if(cnt % 2 == 0) gusu++;

    //cout << ans << endl;

    if(gusu % 2 == 0) {
        cout << ans << endl;
    } else {
        cout << ans-1 << endl;
    }


    return 0;
}
