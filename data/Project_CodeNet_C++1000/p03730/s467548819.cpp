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
    int a, b, c;
    cin >> a >> b >> c;
    int i;
    for(i=1;i<1e5;i++)
        if( abs(a*i-c)%b == 0 )
            break;
    i==1e5? cout << "NO" : cout << "YES";
}