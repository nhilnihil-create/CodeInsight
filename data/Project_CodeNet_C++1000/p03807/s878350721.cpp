#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n)
    {
        int x;
        cin >> x;
        if (x % 2 == 0)
            a[i] = 0;
        else
            a[i] = 1;
    }
    int sum = 0;
    rep(i, n) sum += a[i];
    if (sum % 2 == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}