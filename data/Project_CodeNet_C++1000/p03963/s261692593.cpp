#include <bits/stdc++.h>
using namespace std;

/*
N個のボールをK色の色で塗る場合の数の問題。
最初のボールはK色から選べる。あとのボールはK-1色から。
答えの桁数に注意
2^31-1以下なのが条件としてあるので8bite(32bit)のlongを使う
*/

int main() {
    int N, K;
    cin >> N >> K;
    long comb = 1;
    for (int i = 0; i < N; i++)
    {
        if (i == 0)
        {
            comb *= K;
        }
        else
        {
            comb *= K - 1;
        }
    }

    cout << comb << endl;
}