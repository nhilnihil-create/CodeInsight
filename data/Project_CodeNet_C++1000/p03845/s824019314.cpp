#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
int main()
{
    int N, M;
    cin >> N;
    vector<int> T(N);
    rep(i, N)
    {
        cin >> T[i];
    }
    cin >> M;
    vector<int> P(M), X(M);
    rep(i, M)
    {
        cin >> P[i] >> X[i];
    }
    int sum = 0;
    rep(i, M)
    {
        sum = 0;
        rep(j, N)
        {
            if (j + 1 == P[i])
            {
                sum += X[i];
            }
            else
            {
                sum += T[j];
            }
        }
        cout << sum << endl;
    }
 
    return 0;
}