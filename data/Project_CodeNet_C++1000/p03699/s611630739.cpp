#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int(i) = 0; (i) < (n); (i)++)
typedef long long ll;

int main()
{
    int N;

    cin >> N;
    vector<int> s(N);
    ll sum = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> s[i];
        sum += s[i];
    }
    if (sum % 10 != 0)
    {
        cout << sum << endl;
        return 0;
    }
    sort(s.begin(), s.end());
    for (auto t : s)
    {
        if (t % 10 != 0)
        {
            cout << sum - t << endl;
            return 0;
        }
    }
    cout << 0 << endl;

    return 0;
}