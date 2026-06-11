#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> a;

set<int> zs;
vector<int> z;

vector<int> acc;

int main()
{
    cin >> N;
    a.resize(N);
    for (auto &v : a)
    {
        cin >> v;
        zs.insert(v);
    }
    z.resize(1, 0);

    for (auto v : zs) z.push_back(v);

    acc.resize(z.size());
    for (auto v : a)
    {
        acc[lower_bound(z.begin(), z.end(), v) - z.begin()]++;
    }
    for (int i=acc.size()-2; i>=1; i--) acc[i] += acc[i+1];


    int maxa_tmp = 0;
    for (int i=0; i<N; i++)
    {
        if (a[i] <= maxa_tmp)
        {
            cout << 0 << endl;
            continue;
        }
        long long ans = 0;
        int j = lower_bound(z.begin(), z.end(), a[i]) - z.begin();
        for (; z[j] > maxa_tmp; j--) ans += (long long)acc[j] * (z[j] - z[j-1]);
        cout  << ans << endl;
        maxa_tmp = a[i];
    }
}
