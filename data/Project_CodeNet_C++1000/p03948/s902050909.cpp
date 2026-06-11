#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
const int inf = (1 << 30) - 1;
const ll infll = (1LL << 61) - 1;

int N, a, minv = inf, ans;

int main()
{
    cin >> N >> a;
    vector<int> val;
    for (int i = 0; i < N; i++)
    {
        cin >> a;
        if (a < minv)
            minv = a;
        else
            val.push_back(a - minv);
    }
    sort(val.rbegin(), val.rend());
    for (int i = 0; i < val.size(); i++)
        ans += val[0] == val[i];
    cout << ans << endl;
}