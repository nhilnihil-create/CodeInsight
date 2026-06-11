#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N;
    long K;
    cin >> N >> K;

    vector<int> A(N);
    vector<int> B(N);

    vector<pair<int, int>> P(N);

    int a;
    int b;
    rep(i, N)
    {
        cin >> a >> b;
        P.at(i) = pair<int, int>(a, b);
    }

    sort(P.begin(), P.end());

    long cnt = 0;

    int ans = 0;
    rep(i, N)
    {
        pair<int, int> p = P.at(i);
        cnt += p.second;
        if (cnt >= K)
        {
            ans = p.first;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}