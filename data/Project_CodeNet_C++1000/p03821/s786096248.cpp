#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i] >> B[i];
    }

    long long Ans = 0;

    for (int i = 0; i < N; i++)
    {
        int j = N - i - 1;
        if ((A[j] + Ans) % B[j] != 0)
            Ans += B[j] - ((A[j] + Ans) % B[j]);
    }

    cout << Ans << endl;
}