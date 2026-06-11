#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
template <class T>
using v = vector<T>;
template <class T>
using vv = v<v<T>>;
#define ALL(c) (c).begin(), (c).end()

int main()
{
    int N, L;
    cin >> N >> L;
    v<string> S(N);
    for (int i = 0; i < N; i++)
        cin >> S[i];

    sort(ALL(S));

    for (int i = 0; i < N; i++)
        cout << S[i];

    return 0;
}