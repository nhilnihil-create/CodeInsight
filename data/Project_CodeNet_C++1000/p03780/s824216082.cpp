#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define ull unsigned long long

#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (int &x : v)
        cin >> x;

    sort(v.begin(), v.end());
    ll sum = 0;
    int res = n;
    for (int i = n - 1; i >= 0; --i)
    {
        if (sum + v[i] < k)
            sum += v[i];
        else
            res = min(res, i);
    }

    cout << res << '\n';

    return 0;
}