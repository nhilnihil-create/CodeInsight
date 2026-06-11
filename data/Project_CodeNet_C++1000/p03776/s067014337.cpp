#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back
#define vi vector<int>
#define inf 1000000100

ll ncr(int n, int r)
{
    ll ret = 1;
    if(r > n - r) r = n - r;
    for(int i = 1; i <= r; i++)
    {
        ret *= n-r+i;
        ret /= i;
    }
    return ret;
}


int main()
{
    int a, b, n;
    cin >> n >> a >> b;
    vector<long long> num;
    for(int i = 0; i < n ; i++)
    {
        ll v;
        cin >> v;
        num.pb(v);
    }
    sort(num.begin(), num.end());
    ll avg = 0;
    int c = 0;
    for(int i = n-1; i >= n-a; i--)
    {
        avg += num[i];
        if(num[i] == num[n-a])
        {
            c++;
        }
    }
    double ans = avg/(double)a;
    int ct = c;

    for(int i = n-a-1; i >= 0; i--)
    {
        if(num[i] == num[n-a])
        {
            ct++;
        }
        else
        {
            break;
        }
    }

    ll ways = 0;
    if(ans != num[n-a])
    {
        ways = ncr(ct, c);
    }
    else
    {
        for(int i = 0; i <= b-a && c+i <= ct; i++)
        {
            ways += ncr(ct, c+i);
        }

    }

    cout << fixed << setprecision(6) << ans << endl;
    cout << ways << endl;

}