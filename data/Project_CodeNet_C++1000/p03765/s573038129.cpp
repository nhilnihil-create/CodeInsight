#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    string S, T;
    cin >> S;
    cin >> T;
    int q;
    cin >> q;
    vector<int> a(q), b(q), c(q), d(q);
    REP(i, q) cin >> a[i] >> b[i] >> c[i] >> d[i];

    int n = S.size(), m = T.size();
    vector<int> num_S(n+1), num_T(m+1);
    FOR(i, 1, n+1){
        num_S[i] += num_S[i-1];
        if(S[i-1] == 'A') num_S[i] += 1;
        if(S[i-1] == 'B') num_S[i] += 2;
    }
    FOR(i, 1, m+1){
        num_T[i] += num_T[i-1];
        if(T[i-1] == 'A') num_T[i] += 1;
        if(T[i-1] == 'B') num_T[i] += 2;
    }

    REP(i, q){
        if((num_S[b[i]]-num_S[a[i]-1])%3 == (num_T[d[i]]-num_T[c[i]-1])%3) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}