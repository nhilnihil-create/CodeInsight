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

typedef pair<int, int> P; 


int main(){
    string s;
    cin >> s;
    int top_per = 0, top_guu = 0;
    int possible_per = s.length() / 2;

    REP(i, s.length()) {
        if(s[i] == 'g') {
            top_guu++;
        } else {
            top_per++;
        }
    }

    cout << possible_per - top_per;

    return 0;
}
