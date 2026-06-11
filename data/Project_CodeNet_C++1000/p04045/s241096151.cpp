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
    int K, N;
    cin >> N >> K;
    v<int> D(K, -1), R;
    for (int i = 0; i < 10; i++)
        R.push_back(i);

    for (int i = 0; i < K; i++)
    {
        int a;
        cin >> a;
        D[i] = a;
        R[a] = -1;
    }
    int ans = 0;
    int i = 0;

    for (int i = N; i < N * 10; i++)
    {
        int G = i;
        bool f = true;
        while (G >= 1)
        {
            int mod = G % 10;
            G = G / 10;
            if (find(ALL(D), mod) != D.end())
                f = false;
        }

        if (f)
        {
            ans = i;
            break;
        }
    }

    cout << ans << endl;
    return 0;
}