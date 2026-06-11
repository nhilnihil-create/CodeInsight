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
    string s, t;
    cin >> s >> t;

    vector<int> s_sumA(s.size()+1, 0), s_sumB(s.size()+1, 0);
    vector<int> t_sumA(t.size()+1, 0), t_sumB(t.size()+1, 0);

    REP(i, s.size()) {
        if(s[i] == 'A') s_sumA[i+1] = s_sumA[i] + 1, s_sumB[i+1] = s_sumB[i]; 
        else s_sumA[i+1] = s_sumA[i], s_sumB[i+1] = s_sumB[i] + 1;
    }

    REP(i, t.size()) {
        if(t[i] == 'A') t_sumA[i+1] = t_sumA[i] + 1, t_sumB[i+1] = t_sumB[i]; 
        else t_sumA[i+1] = t_sumA[i], t_sumB[i+1] = t_sumB[i] + 1;
    }

    int q;
    cin >> q;
    REP(query, q) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--, c--;

        int sA, sB, tA, tB;
        sA = s_sumA[b] - s_sumA[a];
        sB = s_sumB[b] - s_sumB[a];
        tA = t_sumA[d] - t_sumA[c];
        tB = t_sumB[d] - t_sumB[c];

        sA %= 3, sB %= 3, tA %= 3, tB %= 3;

        int tmp = min(sA, sB);
        sA -= tmp, sB -= tmp;
        tmp = min(tA, tB);
        tA -= tmp, tB -= tmp;

        if(sA == tA && sB == tB) {
            cout << "YES" << endl;
        } else if ((sA + tB) % 3 == 0 && (sB + tA) % 3 == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}