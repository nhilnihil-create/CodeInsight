#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

int main()
{
    int n;
    cin >> n;
    vector<ll> A(n);
    rep(i, n) cin >> A[i];

    int ans = 0;
    int s = 0; //1は増加中,2は減少中
    rep(i, n - 1)
    {
        if (s == 1 && A[i + 1] < A[i])
        {
            s = 0;
            ans++;
        }
        else if (s == 2 && A[i + 1] > A[i])
        {
            s = 0;
            ans++;
        }
        else if (s == 0)
        {
            if (A[i] < A[i + 1])
                s = 1;
            if (A[i] > A[i + 1])
                s = 2;
        }
    }

    cout << ans + 1 << endl;
}