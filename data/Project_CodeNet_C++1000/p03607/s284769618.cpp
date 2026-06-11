#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    rep(i, n) cin >> a.at(i);

    map<int, int> counter;
    int ans = 0;
    rep(i, n)
    {
        if (counter[a.at(i)] > 0)
        {
            counter[a.at(i)] = 0;
            ans--;
        }
        else
        {
            counter[a.at(i)]++;
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}