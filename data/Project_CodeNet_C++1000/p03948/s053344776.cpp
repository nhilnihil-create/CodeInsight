#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000007;

int N, T, ans, minv = mod, maxg = 0;

int main()
{
    cin >> N >> T;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        if (A[i] <= minv) //min
            minv = A[i];
        if (maxg < A[i] - minv) //sale
        {
            maxg = A[i] - minv;
            ans = 1;
        }
        else if (maxg == A[i] - minv)
            ans++;
    }
    cout << ans << endl;
}