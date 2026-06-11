#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N, M;
    cin >> N >> M;

    vector<string> A(N);
    vector<string> B(M);
    rep(i, N) cin >> A.at(i);
    rep(i, M) cin >> B.at(i);

    bool ans = false;
    for (int i = 0; i <= N - M; i++)
    {
        for (int j = 0; j <= N - M; j++)
        {
            ans = true;
            for (int k = 0; k < M; k++)
            {
                if (A.at(i + k).substr(j, M) != B.at(k))
                {
                    ans = false;
                    break;
                }
            }

            if (ans)
            {
                break;
            }
        }

        if (ans)
        {
            break;
        }
    }

    cout << (ans ? "Yes" : "No") << endl;
    return 0;
}