#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    string S, T;
    cin >> S >> T;
    ll Q, a,b,c,d;
    cin >> Q;

    vector<int> sm(S.size()+1), tm(T.size()+1);
    sm[0] = 0;
    for ( int i = 0; i < S.size(); i++ ) {
        int d = S[i] == 'A' ? 1 : 2;
        sm[i+1] = (sm[i] + d) % 3;
    }
    tm[0] = 0;
    for ( int i = 0; i < T.size(); i++ ) {
        int d = T[i] == 'A' ? 1 : 2;
        tm[i+1] = (tm[i] + d) % 3;
    }

    vector<bool> ans;
    for ( int q = 0; q < Q; q++ ) {
        cin >> a >> b >> c >> d;
        int sd = (sm[b] + 3 - sm[a-1]) % 3;
        int td = (tm[d] + 3 - tm[c-1]) % 3;
        ans.push_back(sd == td);
    }
    
    for ( int q = 0; q < Q; q++ ) {
        string s = ans[q] ? "YES" : "NO";
        cout << s << "\n";
    }
    return 0;
}

int main() {
    solve();
    return 0;
}