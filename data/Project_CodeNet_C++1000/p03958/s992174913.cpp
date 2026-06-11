#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, T;
    cin >> n >> T;
    int mx = 0;
    for(register int i = 1; i <= T; ++i)
    {
        int x;
        cin >> x;
        mx = max(mx, x);
    }
    cout << max(mx - 1 - (n - mx), 0) << endl;
} 