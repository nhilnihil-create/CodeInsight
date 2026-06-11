#include "bits/stdc++.h"

using namespace std;

using ll = long long;

template <typename T>
vector<T> apply(const vector<T> &a, const vector<int> &s)
{
    int n = s.size();
    vector<T> b(n);
    for (int i = 0; i < n; i++)
        b[i] = a[s[i]];
    return b;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, M, K;
    cin >> N;
    vector<ll> x(N);
    for (int i = 0; i < N; i++)
        cin >> x[i];
    cin >> M >> K;
    vector<ll> a(M);
    for (int i = 0; i < M; i++)
    {
        cin >> a[i];
        a[i]--;
    }
    vector<ll> dx(N - 1);
    for (int i = 0; i < N - 1; i++)
        dx[i] = x[i + 1] - x[i];
    // 置換
    vector<int> s(N - 1);
    for (int i = 0; i < N - 1; i++)
        s[i] = i;
    for (int i = 0; i < M; i++)
        swap(s[a[i] - 1], s[a[i]]);
    for (ll i = 1; i <= K; i *= 2)
    {
        if (K & i)
            dx = apply(dx, s);
        s = apply(s, s);
    }
    vector<ll> y(N);
    y[0] = x[0];
    for (int i = 0; i < N - 1; i++)
        y[i + 1] = y[i] + dx[i];
    for (int i = 0; i < N; i++)
        cout << y[i] << endl;
    return 0;
}
