#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N;
    cin >> N;

    vector<int> A(N);
    rep(i, N) cin >> A.at(i);
    vector<int> C(100001);

    rep(i, N)
    {
        int a = A.at(i);
        C.at(a)++;
        C.at(a + 1)++;
        if (a > 0)
        {
            C.at(a - 1)++;
        }
    }

    int ans = 0;
    rep(i, C.size())
    {
        ans = max(ans, C.at(i));
    }

    cout << ans << endl;
    return 0;
}