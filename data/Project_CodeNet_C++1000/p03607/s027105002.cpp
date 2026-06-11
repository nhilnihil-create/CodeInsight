#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int(i) = 0; (i) < (n); (i)++)
typedef long long ll;

int main()
{
    ll N;
    cin >> N;
    vector<bool> A(1000000010, false);
    for (int i = 0; i < N; ++i)
    {
        ll temp;
        cin >> temp;
        A[temp] = !A[temp];
    }
    ll ans = 0;
    for (auto t : A)
    {
        if (t)
        {
            ++ans;
        }
    }
    cout << ans << endl;
}