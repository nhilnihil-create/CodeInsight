#include <bits/stdc++.h>
using namespace std;

int main() {
    string S, T;
    cin >> S >> T;

    vector<int> C(S.size() + 1, 0), D(T.size() + 1, 0);
    for(int i=0; i<S.size(); ++i) {
        if(S[i] == 'A') C[i + 1] = (C[i] + 1) % 3;
        else C[i + 1] = (C[i] + 2) % 3;
    }
    for(int i=0; i<T.size(); ++i) {
        if(T[i] == 'A') D[i + 1] = (D[i] + 1) % 3;
        else D[i + 1] = (D[i] + 2) % 3;
    }

    int q;
    cin >> q;
    for(int i=0; i<q; ++i) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        if((C[b] - C[a - 1] + 3) % 3 == (D[d] - D[c - 1] + 3) % 3) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}