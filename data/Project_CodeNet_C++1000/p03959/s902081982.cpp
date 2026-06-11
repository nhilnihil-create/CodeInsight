#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
const int inf = (1 << 30) - 1;
const ll infll = (1LL << 61) - 1;

int N;
ll ans = 1;

int main()
{
    cin >> N;
    vector<ll> T(N), A(N), com(N);
    for (int i = 0; i < N; i++)
        cin >> T[i];
    for (int i = 0; i < N; i++)
        cin >> A[i];

    bool flag = 1;

    for (int i = 0; i < N; i++)
    {
        if (i == 0 && T[i] > A[i])
            flag = false;
        if (i != 0 && T[i] != T[i - 1] && T[i] > A[i])
            flag = false;

        if (i == 0 && A[N - i - 1] > T[N - i - 1])
            flag = false;
        if (i != 0 && A[N - i - 1] != A[N - i] && A[N - i - 1] > T[N - i - 1])
            flag = false;
    }

    if (flag == false)
    {
        puts("0");
        return 0;
    }

    com[0] = 1LL, com[N - 1] = 1LL;
    for (int i = 1; i + 1 < N; i++)
    {
        if (T[i - 1] != T[i] || A[i + 1] != A[i])
            com[i] = 1LL;
        else
            com[i] = min(T[i], A[i]);

        ans *= com[i];
        ans %= mod;
    }
    cout << ans % mod << endl;
}
