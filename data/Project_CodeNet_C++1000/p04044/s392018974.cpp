#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
template <class T>
using v = vector<T>;
template <class T>
using vv = v<v<T>>;

int main()
{
    int N, L;
    cin >> N >> L;
    v<string> S(N);
    for (int i = 0; i < N; i++)
        cin >> S[i];

    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < N - 1; j++)
        {
            for (int k = j + 1; k < N; k++)
            {
                string s;
                bool f = true;
                for (int l = 0; l < i; l++)
                {
                    if (S[j][l] != S[k][l])
                        f = false;
                }
                if (S[j][i] > S[k][i] && f)
                {
                    s = S[j];
                    S[j] = S[k];
                    S[k] = s;
                }
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        cout << S[i];
    }

    return 0;
}