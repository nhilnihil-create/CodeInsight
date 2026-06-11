#include <bits/stdc++.h>
using namespace std;

long long A[100010];
long long B[100010];

int main(void)
{
    long long N;
    cin >> N;
    for(long long i=1;i<=N;++i)
    {
        cin >> A[i] >> B[i];
    }

    long long ans = 0;
    for(long long i=N;i>0;--i)
    {
        if (((A[i] + ans) % B[i]) == 0)
            ans += (((A[i] + ans) / B[i])) * B[i] - (A[i] + ans);
        else
            ans += (((A[i] + ans) / B[i]) + 1) * B[i] - (A[i] + ans);
    }

    cout << ans << endl;

    return 0;
}
