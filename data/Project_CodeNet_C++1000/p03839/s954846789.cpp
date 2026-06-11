#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
const ll inf = (1 << 30) - 1;
const ll infll = (1LL << 61) - 1;

int N, K, s;
ll sum, ans, a;

int main()
{
    cin >> N >> K;
    vector<ll> Sa(N + 1), S(N + 1);
    for (int i = 0; i < N; i++)
    {
        cin >> a;
        Sa[i + 1] += Sa[i] + a;
        S[i + 1] += S[i] + max(0LL, a);
    }

    for (int i = K; i <= N; i++)
    {
        ans = max((S[N] - S[i]) + S[i - K] + max(0LL, Sa[i] - Sa[i - K]), ans);
    }

    cout << ans << endl;
}