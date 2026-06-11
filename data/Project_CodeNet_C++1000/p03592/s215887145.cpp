// すべての操作は独立していて、順番は関係ない
// また、おなじ操作を二回以上行う必要はなく、それらは0回/1回の操作と等しい
// よって、0<=i<=N, 0<=j<=Mの全ての(i,j)に対して、
// i行をフリップ、j列をフリップさせたときの黒マスの数を調べ、それがKに等しくなるかどうか調べる
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M, K;
int black(int i, int j) {
    return (N-i)*j + i*(M-j);
}

int main()
{
    cin >> N >> M >> K;
    for(int i = 0; i <= N; ++i) {
        for(int j = 0; j <= M; ++j) {
            if(black(i,j)==K) { cout << "Yes" << endl; return 0; }
        }
    }
    cout << "No" << endl;
    return 0;
}