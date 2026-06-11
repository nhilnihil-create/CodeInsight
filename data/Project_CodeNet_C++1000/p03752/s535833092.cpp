#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<long long> height(N);
    for (int i=0; i<N; i++) cin >> height[i];
    
    long long ans = 100000000000;
    // 最終的に見えるようにする建物を選択する
    // 選択されてない建物が見えないとは限らないが.....
    // 余計に伸ばした場合最適解に駆逐されるのでかまわない
    for (int i=0; i<pow(2, N); i++)
    {
        long long cost=0;
        vector<long long> tmp_height(N);
        copy(height.begin(), height.end(), tmp_height.begin());
        if (__builtin_popcount(i)>=K)
        {
            long long h=0; //j-1本目までに見える建物の高さの最大値
            for (int j=0; j<N; j++) //j番目の建物に行う操作
            {
                if (i&(1<<j)) //見えるべきかどうか
                {
                    if (tmp_height[j]<=h) //見えてないならお金払って伸ばす
                    {
                        cost += h-tmp_height[j]+1;
                        tmp_height[j] = h+1;
                    }
                }
                h = max(h, tmp_height[j]);
            }
            //cout << cost << endl;
            ans = min(ans, cost);
        }
    }
    cout << ans << endl;

}