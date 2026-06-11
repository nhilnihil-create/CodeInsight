#include <bits/stdc++.h>

using ll = long long;
using namespace std;
int main()
{
    int N;
    cin >> N;
    vector<ll> A(N);
    for (ll i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    ll res = 0;
    for (ll i = 0; i < N; i++)
    {
        while (i + 1 < N && A[i + 1] == A[i])
            i++;
        if (A[i + 1] >= A[i])
        {
            while (i + 1 < N && A[i + 1] >= A[i])
            {
                i++;
            }
        }
        else
        {
            while (i + 1 < N && A[i + 1] <= A[i])
            {
                i++;
            }
        }
        res++;
    }
    cout << res << endl;
}