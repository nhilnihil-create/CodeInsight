#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, c;
    cin >> a >> b >> c;

    string ans = "NO";
    for(int i=0; i<=b; i++)
    {
        if(a*i%b == c) ans = "YES";
    }
    cout << ans << endl;

    return 0;
}
