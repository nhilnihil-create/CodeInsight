#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, a, b) for(int i = a, i##_len = (b); i < i##_len; ++i)

const int mod = 'z' - 'a' + 1;

char next_alphabet(char p, int step) {
    return char((p -'a' + step)%mod + 'a');
}

int distance(char a, char b) { // a -> bまでの距離(剰余環)
    return (b - a + mod)%mod;
}

int main()
{
    string S;
    int K;
    cin >> S >> K;
    // 大きいビットから、'a'にする余力があるのなら'a'にしていく
    // さらに余力(K)が余ったら、最下位ビットに全振りする
    for(int i = 0, i_len = S.size(); i < i_len; ++i) {
        int dist = distance(S[i], 'a');
        if(K < dist) { continue; }
        K -= dist;
        S[i] = next_alphabet(S[i], dist);
    }
    S[S.size()-1] = next_alphabet(S[S.size()-1], K);
    cout << S << endl;
    return 0;
}