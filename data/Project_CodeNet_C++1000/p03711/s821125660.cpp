#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
    int x, y;
    cin >> x >> y;
    vector<int> a = {1, 3, 5, 7, 8, 10, 12};

    if (x == 2 || y == 2)
    {
        cout << "No" << '\n';
        return 0;
    }

    bool is_x = false, is_y = false;
    rep(i, a.size())
    {
        if (x == a[i])
        {
            is_x = true;
        }
        if (y == a[i])
        {
            is_y = true;
        }
    }

    cout << (is_x == is_y ? "Yes" : "No") << '\n';

    return 0;
}
