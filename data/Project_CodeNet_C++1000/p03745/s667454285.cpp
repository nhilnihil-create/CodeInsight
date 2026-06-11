#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int pos = 0;
    int ans = 0;
    while(pos < n)
    {
        while(pos+1 < n && a[pos] == a[pos+1]) pos++;
        if(pos == n-1)
        {
            ans++;
            break;
        }
        bool inc = false;
        if(a[pos] < a[pos+1]) inc = true;
        if(inc)
        {
            while(pos+1 < n && a[pos] <= a[pos+1]) pos++;
        }
        else
        {
            while(pos+1 < n && a[pos] >= a[pos+1]) pos++;
        }
        if(pos == n-1)
        {
            ans++;
            break;
        }
        pos++;
        ans++;
    }
    cout << ans << endl;
}

