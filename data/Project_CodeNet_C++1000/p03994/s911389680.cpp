#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    string S; cin >> S;
    int N = S.size();
    int K; cin  >> K;
    string T = S;

    rep(i,N) {
        if (S[i] == 'a') continue;
        int toa = 'z' + 1 - S[i];
        if (toa <= K) K-=toa, S[i] = 'a';
    }

    if (S[N-1] != 'a') {
        int toa = 'z' + 1 - S[N-1];
        if (toa <= K) K-=toa, S[N-1] = 'a';
        else {
            S[N-1] += K;
            K = 0;
        }
    }
    K = K % 26;
    S[N-1] += K;

    cout << S << endl;
}
