#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
ll A, B, C, ans = 0;
ll aa, bb, cc;
int main()
{
    cin >> A >> B >> C;
    while (A % 2 == 0 && B % 2 == 0 && C % 2 == 0)
    {

        if (A == B && B == C)
        {
            ans = -1;
            cout << ans << endl;
            return 0;
        }
        aa = A / 2;
        bb = B / 2;
        cc = C / 2;
        A = bb + cc;
        B = aa + cc;
        C = bb + aa;
        // cout << A << "," << B << "," << C << endl;

        ans++;
    }
    cout << ans << endl;

    return 0;
}
