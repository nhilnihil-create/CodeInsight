#include <bits/stdc++.h>
using namespace std;

int A[100005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    int N, x;
    cin >> N >> x;

    long long ans = 0;

    for(int i=1; i<=N; i++)
        cin >> A[i];

    for(int i=1; i<=N; i++)
    {
        int k = max(0, A[i] + A[i-1] - x);
        ans += k;
        A[i] -= k;
    }

    cout << ans << "\n";
    return 0;
}
