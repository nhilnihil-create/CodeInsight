// A_i に C_iを加えて A_i + C_i にする。
// このとき、B_iの倍数にするので、 C_i = (B_i - A_i%B_i) + B_i * k (0 <= k)
// 以上のCiを並べると、
// C_0 >= C_1 >= C_2 >= C_3 >= .... >= C_(N-1)
// を満たせば良くて、ボタンを押す回数は、
// (C_0 - C_1) + (C_1 - C_2) + (C_2 + C_3) + ... + (C_(N-2) - C_(N-1)) + C_(N-1)
// = C_0
// この値を最小にする
// C_(N-1)から貪欲に決めていける？
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N,0),B(N,0);
    for (int i = N - 1; i >= 0; i--)
    {
        cin >> A[i] >> B[i];
    }

    vector<long long> C(N+1,0);
    // C[i] := A[i-1]に加える数
    C[0] = 0;
    for(int i = 0; i < N; ++i) {
        A[i] += C[i];
        long long amari = A[i] % B[i];
        long long need = 0;
        if (amari != 0) need = B[i] - amari;
        C[i+1] = C[i] + need;
    }
    cout << C[N] << endl;
    return 0;
}