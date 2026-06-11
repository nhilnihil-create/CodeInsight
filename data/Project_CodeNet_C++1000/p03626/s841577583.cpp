#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define MOD 1000000007

typedef long long ll;

using namespace std;
int main()
{
    int N;
    cin >> N;
    string S1, S2;
    cin >> S1 >> S2;

    ll ans;
    // 前のマスの状態を記憶しておく
    // 1 : 縦に1つのドミノがある場合
    // 2 : 横に2つのドミノが並んでいる場合
    int prevState;
    REP(i, N)
    {
        // 初期状態
        if (i == 0)
        {
            if (S1[i] == S2[i])
            {
                ans = 3;
                prevState = 1;
            }
            else
            {
                ans = 6;
                prevState = 2;
                // 横に2マス並んでいるのでi を1増やす
                i++;
            }
        }
        else
        {
            if (S1[i] == S2[i])
            {
                if (prevState == 1)
                {
                    ans = ans * 2 % MOD;
                }
                else
                {
                    ans = ans;
                }
                prevState = 1;
            }
            else
            {
                if (prevState == 1)
                {
                    ans = ans * 2 % MOD;
                }
                else
                {
                    ans = ans * 3 % MOD;
                }
                prevState = 2;
                // 横に2マス並んでいるのでi を1増やす
                i++;
            }
        }
    }

    cout << ans << endl;
}
