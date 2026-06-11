#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
    int i, j;
    int n;

    cin >> n;
    vector<int> v(n);

    rep(i, n) cin >> v[i];
    int average = round(accumulate(v.begin(), v.end(), 0) / (float)n);

    int answer = 0;
    rep(i, n) answer += (int)pow(v[i] - average, 2);

    cout << answer << endl;

    return 0;
}