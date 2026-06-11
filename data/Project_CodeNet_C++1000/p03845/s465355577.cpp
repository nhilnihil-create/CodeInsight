#include <bits/stdc++.h>
#define pii pair<int,int>
#define eb emplace_back
#define MOD 1000000007
#define int long long
using namespace std;
#define s second
#define f first

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    int a[n];
    int sum = 0;
    for(auto& x:a)
    {
        cin >> x;
        sum += x;
    }
    int m;  cin>> m;
    pii b[m];
    for(auto& x:b)  cin >> x.f >> x.s;

    for(int i=0;i<m;i++)
    {
        cout << sum - a[b[i].f-1] + b[i].s << '\n';
    }
}