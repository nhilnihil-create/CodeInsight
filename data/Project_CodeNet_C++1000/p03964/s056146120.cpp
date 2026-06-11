#include <bits/stdc++.h>
#define ll long long int
#define mod_ceil(a, b) (a % b) ? a / b + 1 : a / b
using namespace std;
int main()
{
    // cout << (ll)ceilf128(1000000000000.262) << endl;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, l = 1, r = 1, l1, r1, tmp, l_tmp, r_tmp;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> l1 >> r1;
        // if (l1 >= l and r1 >= r)
        // {
        //     l = l1;
        //     r = r1;
        // }
        // else
        // {
        l_tmp = mod_ceil(l, l1);
        r_tmp = mod_ceil(r, r1);
        // l_tmp = (l % l1) ? l / l1 + 1 : l / l1;
        // r_tmp = (r % r1) ? r / r1 + 1 : r / r1;
        tmp = max(l_tmp, r_tmp);
        l = tmp * l1;
        r = tmp * r1;
        // }
    }
    tmp = l + r;
    cout << tmp << endl;
}