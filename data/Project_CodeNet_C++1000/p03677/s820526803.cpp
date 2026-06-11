#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<lint> imos1(m * 2 + 1), imos2(m * 2 + 1);

    int a, anew;
    cin >> a;
    a %= m;
    lint sum_normal = 0;

    for (int i = 0; i < n - 1; i++)
    {
        cin >> anew;
        if (anew < a) anew += m;
        imos2[a+2]++;
        imos2[anew + 1] -= 1;
        imos1[anew + 1] -= anew - a - 1;

        sum_normal += anew - a;

        a = anew % m;
    }
    for (int i = 1; i < m * 2 + 1; i++) imos1[i] += imos1[i-1];
    for (int i = 1; i < m * 2 + 1; i++) imos2[i] += imos2[i-1];
    for (int i = 1; i < m * 2 + 1; i++) imos2[i] += imos2[i-1];

    // for (int i = 0; i < m * 2 + 1; i++)
    // {
    //     cout << imos1[i] << " " << imos2[i] << " " << imos1[i] + imos2[i] << endl;
    // }
    // cout << sum_normal << endl;

    lint maxtmp = 0;
    for (int i = 0; i < m; i++)
    {
        maxtmp = max(maxtmp, imos1[i] + imos2[i] + imos1[i+m] + imos2[i+m]);
    }
    cout << sum_normal - maxtmp << endl;
    return 0;
}