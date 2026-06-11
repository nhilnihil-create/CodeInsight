#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 100100;

int N;
pair <int, int> event[MAXN];
ll ans[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> event[i].first;
        event[i].first = -event[i].first;
        event[i].second = i;
    }

    sort (event, event + N);
    int clo = N;
    ll csum = 0;
    for (int i = 0; i < N; i++)
    {
        ll xv = -event[i].first;
        int ind = event[i].second;

        if (ind < clo)
        {
            ans[clo] += csum - i * xv;
            csum = i * xv;
            clo = ind;
        }

        csum += xv;
    }
    ans[clo] += csum;

    for (int i = 0; i < N; i++)
    {
        cout << ans[i] << "\n";
    }
}