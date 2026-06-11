#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int N; cin >> N;
    long long T[1005], A[1005];
    for (int n = 1; n <= N; n++)
    {
        cin >> T[n] >> A[n];
    }

    for (int i = 1; i <= N - 1; i++)
    {
        long long T_1 = T[i], A_1 = A[i];
        long long T_2 = T[i + 1], A_2 = A[i + 1];

        if (T_1 <= T_2 && A_1 <= A_2) continue;
        else if (T_1 > T_2 && A_1 <= A_2)
        {
            long long x = ((T_1 - 1) / T_2) + 1;
            T_2 *= x;
            A_2 *= x;
        }
        else if (T_1 <= T_2 && A_1 > A_2)
        {
            long long x = ((A_1 - 1) / A_2) + 1;
            T_2 *= x;
            A_2 *= x;
        }
        else // (T_1 > T_2 && A_1 > A_2)
        {
            long long x = max( ((T_1 - 1) / T_2) + 1, ((A_1 - 1) / A_2) + 1 );
            T_2 *= x;
            A_2 *= x;
        }

        T[i + 1] = T_2;
        A[i + 1] = A_2;
    }

    cout << T[N] + A[N] << endl;
    return 0;
}