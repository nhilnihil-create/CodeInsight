#include <bits/stdc++.h>
using namespace std;

int64_t MOD = 1000000007;
int64_t MAX = 9223372036854775807;
double PI = 3.141592653589793;

int main()
{
    int N, tmp;
    cin >> N;
    vector<int64_t> A(N), B(N);
    for (int i = 0; i < N; i++)
        cin >> A[i] >> B[i];
    int64_t ans = 0;
    for (int i = N - 1; i >= 0; i--)
    {
        tmp = B[i] - A[i] % B[i];
        if (tmp == B[i])
            tmp = 0;
        ans += tmp;
        if (i != 0)
            A[i - 1] += ans;
    }
    cout << ans;
}