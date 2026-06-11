// #include <bits/stdc++.h>

// using namespace std;
// typedef long long ll;

// #define rep(i, n) for (int i = 0; i < (n); i++)
// #define rep2(i, a, b) for (int i = (a); i < (b); ++i)
// #define all(a) (a).begin(), (a).end()
// #define all2(a, b) (a).begin(), (a).begin() + (b)
// #define debug(vari) cerr << #vari << " = " << (vari) << endl;

// int main()
// {
//     int N;
//     cin >> N;

//     vector<int> vec(N);
//     rep(i, N) cin >> vec[i];

//     bool flag = true;
//     rep(i, N)
//     {
//         if (vec[i] % 2 == 0)
//         {
//             if (vec[i] % 3 != 0 || vec[i] % 5 != 0)
//             {
//                 flag = false;
//             }
//         }
//     }

//     cout << (flag ? "APPROVED" : "DENIED") << endl;

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main()
{
    int w, h, n;
    cin >> w >> h >> n;

    vector<int> x(n), y(n), a(n);
    rep(i, n) cin >> x[i] >> y[i] >> a[i];

    int x_min = 0, y_min = 0, x_max = w, y_max = h;

    rep(i, n)
    {
        if (a[i] == 1)
        {
            x_min = max(x_min, x[i]);
        }
        else if (a[i] == 2)
        {
            x_max = min(x_max, x[i]);
        }
        else if (a[i] == 3)
        {
            y_min = max(y_min, y[i]);
        }
        else
        {
            y_max = min(y_max, y[i]);
        }
    }

    int ans;
    if (x_min >= x_max || y_min >= y_max)
    {
        ans = 0;
    }
    else
    {
        ans = (x_max - x_min) * (y_max - y_min);
    }

    cout << ans << endl;

    return 0;
}