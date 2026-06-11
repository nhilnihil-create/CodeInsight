#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
int INF = 1e9+10;
int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    vector<ll> sum(n+1, 0);
    for(int i = 0; i < n; i++) sum[i+1] = sum[i] + a[i];
    int h = n-1;
    int l = -1;
    while(h - l > 1)
    {
        int mid = (h + l) >> 1;
        ll s = sum[mid+1];
        bool flag = true;
        for(int i = mid+1; i < n; i++)
        {
            if(2 * s >= a[i])
            {
                s += a[i];
            }
            else
            {
                flag = false;
                break;
            }
        }
        if(flag) h = mid;
        else l = mid;
    }
    cout << n - h << endl;
}
