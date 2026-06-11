#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main()

{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll ans = a[0]-1;
    int high = 2;
    for(int i = 1; i < n; i++)
    {
        int cand = a[i];
        if(cand < high)
        {
            continue;
        }
        else if(cand == high)
        {
            high++;
            continue;
        }
        else
        {
            int count = cand / high;
            if(cand % high == 0)
            {
                count--;
            }
            ans += count;
        }
    }
    cout << ans << endl;
}
