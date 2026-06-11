#include<bits/stdc++.h>
#define rep(i,n,m) for(int i = (n); i <(m); i++)
#define rrep(i,n,m) for(int i = (n) - 1; i >=(m); i--)
using namespace std;
using ll = long long;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> A(n), B(n);

    rep(i, 0, n)
        cin >> A[i] >> B[i];

    ll value = 0;
    rep(i, 0, n)
        if ((k|A[i]) == k)
            value += (ll)B[i];

    int base = 1 << 30;
    while (base)
    {
        if ((base & k) == 0)
        {
            base >>= 1;
            continue;
        }

        int mask = (k - base) | (base - 1);
        ll now_value = 0;
        rep(i, 0, n)
            if ((mask|A[i]) == mask)
                now_value += (ll)B[i];

        value = max(value, now_value);
        // cout << now_value << endl;
        base >>= 1;
    }
    cout << value << endl;
    return 0;
}