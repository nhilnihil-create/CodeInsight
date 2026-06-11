#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

vector<ll> A;
bool ok(int m)
{
    ll tmp = 0;
    for (int i = 0; i <= m; i++)
        tmp += A[i];
    for (int i = m + 1; i < A.size(); i++)
    {
        if (tmp * 2 < A[i])
            return false;
        tmp += A[i];
    }
    return true;
}

int main()
{
    ll n;
    cin >> n;
    A.resize(n);
    rep(i, n) cin >> A[i];
    sort(A.begin(), A.end());

    //にぶたん
    int l = -1;
    int r = n;
    while (r - l > 1)
    {
        int m = l + (r - l) / 2;
        if (ok(m))
            r = m;
        else
            l = m;
    }

    cout << n - r << endl;
}