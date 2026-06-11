#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
    int N, ans = 0;
    cin >> N;
    vector<int> A(N + 1);
    rep(i, N) cin >> A[i];

    bool up = false;
    bool down = false;

    rep(i, N - 1)
    {
        if (A[i] < A[i + 1])
        {
            up = true;
        }
        else if (A[i] > A[i + 1])
        {
            down = true;
        }
        else
        {
            continue;
        }

        if (up && down)
        {
            ans += 1;
            up = false;
            down = false;
        }
    }
    cout << ans + 1 << endl;

    return 0;
}
