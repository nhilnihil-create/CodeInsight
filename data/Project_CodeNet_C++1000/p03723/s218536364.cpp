#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int cookieEx(ll a, ll b, ll c, ll ret) {
    if (a%2==1 || b%2==1 || c%2==1) return ret;
    ll A, B, C;
    A = b / 2 + c / 2;
    B = a / 2 + c / 2;
    C = a / 2 + b / 2;
    ret++;
    return cookieEx(A, B, C, ret);
}

int main(void)
{
    ll a, b, c;
    cin >> a >> b >> c;
    if (a == b && b == c && c == a)  {
        if (a%2!=0) {
            cout << 0 << endl;
            return (0);
        }
        cout << -1 <<endl;
        return (0);
    }
    ll ret = 0;
    ret = cookieEx(a, b, c, ret);
    cout << ret << endl;
}
