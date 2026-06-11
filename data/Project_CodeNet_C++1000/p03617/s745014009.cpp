#include <bits/stdc++.h>
using namespace std;

int main()
{

        int Q, H, S, D;
        cin >> Q >> H >> S >> D;
        int N;
        cin >> N;

        int s_min = std::min(Q*4, H*2);
        s_min = std::min(S, s_min);
        int d_min = std::min(D, Q*8);
        d_min = std::min(d_min, H*4);
        d_min = std::min(d_min, S*2);

        long long ans = 0;
        long long  dd = N / 2;
        long long  ss = N % 2;
        ans = dd * d_min + ss * s_min;
        cout << ans << endl;
}
