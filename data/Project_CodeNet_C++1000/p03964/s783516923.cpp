#include <bits/stdc++.h>
using namespace std;

int main()
{
        int N;
        cin >> N;
        int T[N];
        int A[N];
        for (int i = 0; i < N; ++i) {
                cin >> T[i] >> A[i];
        }
        long long tc = 0;
        long long ac = 0;
        int tLast = 0;
        int aLast = 0;
        for (int i = 0; i < N; ++i) {
                if (tLast == T[i] && aLast == A[i]) continue;
                if (tc < T[i] && ac < A[i]) {
                        tc = T[i];
                        ac = A[i];
                }
                else {
                        long long tmp1 = tc / T[i];
                        if (tc % T[i]) tmp1++;
                        long long tmp2 = ac / A[i];
                        if (ac % A[i]) tmp2++;
                        long long tmp = (tmp1 > tmp2) ? tmp1 : tmp2;
                        tc = (long long)T[i] * tmp;
                        ac = (long long)A[i] * tmp;
                }
                tLast = T[i];
                aLast = A[i];
        }
        cout << tc + ac << endl;
}
