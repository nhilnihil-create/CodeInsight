#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
const int inf = (1 << 30) - 1;
const ll infll = (1LL << 61) - 1;

int N, T, minv = inf, ans;

int main()
{
    cin >> N >> T;
    vector<int> A(N), val;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        if (A[i] < minv)
            minv = A[i];
        else
        {
            val.push_back(A[i] - minv);
        }
    }
    sort(val.rbegin(), val.rend());
    for (int i = 0; i < val.size(); i++)
    {
        if (val[0] == val[i])
            ans++;
    }
    cout << ans << endl;
}