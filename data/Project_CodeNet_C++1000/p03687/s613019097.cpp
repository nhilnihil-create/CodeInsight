#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (ll (i) = 0 ; (i) < (ll)(n) ; ++(i))
#define REPN(i, m, n) for (ll (i) = m ; (i) < (ll)(n) ; ++(i))
#define REP_REV(i, n) for (ll (i) = (ll)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (ll (i) = (ll)(n) - 1 ; (i) >= m ; --(i))

#define INF 2e9
#define INF_LL 1LL<<60
#define ll long long

#define MAX_V 105

int main(){
    string s;
    cin >> s;
    vector<int> distance_;

    int min_ = 200;
    REP(i, 26) {
        int cnt = 0;
        distance_.resize(0);
        REP(j, s.size()) {
            if(s[j] - 'a' == i) {
                distance_.push_back(cnt);
                cnt = 0;
            } else {
                cnt++;
            }
        }
        distance_.push_back(cnt);
        sort(distance_.begin(), distance_.end());
        min_ = min(min_, distance_[distance_.size() - 1]);
    }

    cout << min_ << endl;

    return 0;
}
