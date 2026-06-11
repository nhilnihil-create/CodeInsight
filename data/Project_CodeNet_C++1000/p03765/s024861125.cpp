#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    string S, T;
    cin >> S >> T;
    int N, M;
    N = (int)S.size();
    M = (int)S.size();
    vector<int> SA(N+1, 0), TA(M+1, 0);
    for (int i = 1; i <= N; i++) {
        if (S[i-1] == 'A') SA[i] = SA[i-1]+1;
        else SA[i] = SA[i-1];
    }
    for (int i = 1; i <= M; i++) {
        if (T[i-1] == 'A') TA[i] = TA[i-1]+1;
        else TA[i] = TA[i-1];
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int sp, tp;
        sp = (b-a+1) + SA[b] - SA[a-1];
        tp = (d-c+1) + TA[d] - TA[c-1];
        if ((sp-tp) % 3 == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}