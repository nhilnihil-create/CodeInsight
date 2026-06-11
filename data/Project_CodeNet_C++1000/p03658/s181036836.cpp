#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back
#define vi vector<int>
#define vp vector<pair<int, int>>
#define vll vector<long long>
#define inf 1000000100
#define infll 1LL << 50

int main()
{
    int n, k;
    cin >> n >> k;
    vi data;
    for(int i = 0; i < n; ++i)
    {
        int l;
        cin >> l;
        data.pb(l);
    }
    sort(data.rbegin(), data.rend());
    int ans = 0;
    for(int i = 0; i < k; ++i)
    {
        ans += data[i];
    }
    cout << ans << endl;
}
