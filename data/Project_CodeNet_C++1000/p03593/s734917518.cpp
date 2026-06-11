#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (ll (i) = 0 ; (i) < (ll)(n) ; ++(i))
#define REPN(i, m, n) for (ll (i) = m ; (i) < (ll)(n) ; ++(i))
#define REP_REV(i, n) for (ll (i) = (ll)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (ll (i) = (ll)(n) - 1 ; (i) >= m ; --(i))

#define INF             2e9
#define INF_LL          1LL<<60
#define ll              long long
#define Ceil(x, n)      (((((x))+((n)-1))/n))
#define CeilN(x, n)     (((((x))+((n)-1))/n)*n)
#define FloorN(x, n)    ((x)-(x)%(n))
#define ALL(x)          (x).begin(),(x).end()
typedef pair<ll, ll>    P;

int main() {
    int h, w;
    cin >> h >> w;
    vector<int> cnt(26, 0);
    REP(i, h) {
        string s;
        cin >> s;
        REP(j, s.size()) {
            cnt[s[j]-'a']++;
        }
    }   

    int tmp = 0;
    int tmp2 = 0;
    REP(i, 26) {
        tmp += cnt[i] / 4;
        cnt[i] -= cnt[i] / 4 * 4;
        tmp2 += cnt[i] / 2;
    }

    /* 上下埋めていく */
    REP(i, h/2) {
        tmp -= (w/2);
        if(w % 2 == 1) {
            tmp2--;
        }
    } 
    //cout << tmp << endl;

    if(h % 2 == 1) {
        tmp2 -= w/2;
    }
    //cout << tmp << endl;

    if(tmp < 0) {
        cout << "No" << endl;
        return 0;
    }

    if(tmp*2 + tmp2 < 0) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }

    return 0;
}