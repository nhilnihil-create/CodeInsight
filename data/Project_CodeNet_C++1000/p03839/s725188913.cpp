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
    vector<ll> T, S;
    T.push_back(0);
    S.push_back(0);

    for (int i = 0; i < N; i++)
    {
        cin >> a;
        T.push_back(T.back() + a);
        S.push_back(S.back() + max(0LL, a));
    }

    for (int i = K; i <= N; i++)
        ans = max((S[N] - S[i]) + S[i - K] + max(0LL, T[i] - T[i - K]), ans);

    cout << ans << "\n";
}