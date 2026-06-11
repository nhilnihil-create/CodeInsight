#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long int ll;
typedef pair<int, int> P;

int n, a[101010];

int main()
{
    cin >> n;
    rep(i, n) cin >> a[i];

    int p = 0;
    ll res = 0;
    rep(i, n)
    {
        if(p && a[i])
        {
            p = 0;
            a[i]--;
            res++;
        }
        res += a[i] / 2;
        p = a[i] % 2;
    }
    cout << res << endl;

    return 0;
}