#include <bits/stdc++.h>
using namespace std;

int main(){
    string S, T;
    cin >> S >> T;
    int N = S.size(), M = T.size();
    vector<int> SS(N+1), TT(M+1);
    for(int i=0; i<N; i++) SS[i+1] = SS[i] + S[i] - 'A' + 1;
    for(int i=0; i<M; i++) TT[i+1] = TT[i] + T[i] - 'A' + 1;
    int Q;
    cin >> Q;
    for(int i=0; i<Q; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--; c--;
        int s = SS[b] - SS[a] - TT[d] + TT[c];
        cout << (s%3 ? "NO" : "YES") << endl;
    }
}
