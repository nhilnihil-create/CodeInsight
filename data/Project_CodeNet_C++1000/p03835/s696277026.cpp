#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, start, n) for (int i = (int)(start); i < (int)(n); ++i)
static const int INFTY = (1 << 30);
int K, S;
void func()
{
    cin >> K >> S;
    int ans(0);
    rep(i, 0, K + 1)
    {
        rep(j, 0, K + 1)
        {
            if (S - i - j >= 0 && S - i - j <= K)
                ++ans;
        }
    }
    cout << ans << endl;
}
int main()
{
    func();
}