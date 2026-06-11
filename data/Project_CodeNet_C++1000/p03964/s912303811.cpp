#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
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
        // l_tmp = (ll)ceill(l / (l1 + .0));
        // r_tmp = (ll)ceill(r / (r1 + .0));
        l_tmp = (l % l1) ? l / l1 + 1 : l / l1;
        r_tmp = (r % r1) ? r / r1 + 1 : r / r1;
        tmp = max(l_tmp, r_tmp);
        l = tmp * l1;
        r = tmp * r1;
        // }
    }
    tmp = l + r;
    cout << tmp << endl;
}