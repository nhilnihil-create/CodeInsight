#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
int N;
string s, t;
int main()
{
    cin >> N >> s >> t;
    int ans = 2 * N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (s.substr(i, (N - i)) == t.substr(j, (N - i)))
            {
                ans -= N - i;
                cout << ans << endl;
                return 0;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
