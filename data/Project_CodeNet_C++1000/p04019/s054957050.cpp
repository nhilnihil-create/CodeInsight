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
    string s;
    cin >> s;
    int a = 0, b = 0, c = 0, d = 0;
    REP(i, s.size()) {
        if(s[i] == 'S') a++;
        else if(s[i] == 'N') b++;
        else if(s[i] == 'W') c++;
        else d++; 
    }

    bool ue;
    if(a == 0) {
        if(b == 0) ue = true;
        else ue = false;
    } else {
        if(b == 0) ue = false;
        else ue = true;
    }

    bool shita;
    if(c == 0) {
        if(d == 0) shita = true;
        else shita = false;
    } else {
        if(d == 0) shita = false;
        else shita = true;
    }

    //cout << ue << " " << shita << endl;

    if(shita && ue) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}