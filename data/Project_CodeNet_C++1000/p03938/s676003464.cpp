#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
const ll inf = (1 << 30) - 1;
const ll infll = (1LL << 61) - 1;

int N;

int main()
{
    cin >> N;
    vector<int> p(N), A(N), B(N);
    for (int i = 0; i < N; i++)
    {
        cin >> p[i];
        p[i]--;
        B[p[i]] += i + 1;
        A[i] = 30000 * (i + 1);
        B[i] += 30000 * (N - i - 1);
    }
    for (int i = 0; i < N; i++)
        cout << A[i] << (i == N - 1 ? '\n' : ' ');
    for (int i = 0; i < N; i++)
        cout << B[i] << (i == N - 1 ? '\n' : ' ');
}