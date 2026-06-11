#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back
#define vi vector<int>
#define inf 1000000100

int main()
{
    int n;
    cin >> n;
    vi time;
    ll totaltime = 0;
    while(n--)
    {
        int t;
        cin >> t;
        time.pb(t);
        totaltime += t;
    }
    int m;
    cin >> m;
    while(m--)
    {
        int p, x;
        cin >> p >> x;
        cout << totaltime - (time[p-1] - x) << endl;
    }
}