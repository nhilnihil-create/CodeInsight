#include <bits/stdc++.h>
using namespace std;

int main()
{

        int Q, H, S, D;
        cin >> Q >> H >> S >> D;
        long long N;
        cin >> N;
        long long n = N * 8;

        int q_min = Q;
        int h_min = 0;
        if (Q*2 < H) {
                h_min = Q*2;
        }
        else {
                h_min = H;
        }
        int s_min = 0;
        if (Q*4 < H*2) {
                s_min = Q*4;
        }
        else {
                s_min = H*2;
        }
        if (s_min > S) {
                s_min = S;
        }
        int d_min = D;
        if (D > Q*8) {
                d_min = Q*8;
        }
        if (d_min > H*4) {
                d_min = H*4;
        }
        if (d_min > S*2) {
                d_min = S*2;
        }
//      cout << "n= " << n << endl;
//      cout << "q_min= " << q_min << endl;
//      cout << "h_min= " << h_min << endl;
//      cout << "s_min= " << s_min << endl;
//      cout << "d_min= " << d_min << endl;

        long long ans = 0;

        long long  dd = n/16;
        long long dda = n % 16;
        long long  ss = dda / 8;
        long long ssa = dda % 8;
        long long  hh = ssa / 2;
        long long  hha = ssa % 2;
        long long  qq = hha / 1;
        ans = dd * d_min + (ss * s_min) + (hh * h_min) + (qq * q_min);
        cout << ans << endl;
}
