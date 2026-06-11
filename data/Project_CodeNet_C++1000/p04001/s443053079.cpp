#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    string S;
    cin >> S;
    int N = S.size();
    ll res = 0;
    for (int bit = 0; bit < (1<<(N-1)); ++bit) {
        ll tmp = 0;
        for (int i = 0; i < N-1; ++i) {
            tmp *= 10;
            tmp += S[i] - '0'; //文字列を整数にしている。
            if (bit & (1<<i)) res += tmp, tmp = 0;
        }
        tmp *= 10;
        tmp += S.back() - '0';
        res += tmp;
    }

    cout << res << endl;

}

//bit全探索で数字のどこに＋が入るかを決める
// 前から順に見ていって、「数字があるたびに現在の値を 10 倍して今書いてある数字
//だけ足す」「‘+(’ が出てきたら現在の値が ‘+(’ の直前の整数に等しいので、それを答え
//に足す」「最後は ‘+(’ が登場せずに数式が終わるので、そこは別に足す」とすると、新し
//く出来た式の値を求めることができます。