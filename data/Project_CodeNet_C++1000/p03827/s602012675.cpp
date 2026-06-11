#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; i++)
using namespace std;

int main()
{
    int n, x = 0, mx = 0;
    string s;
    cin >> n >> s;
    rep(i, n) {
        if (s[i] == 'I') {
            x++;
            mx = max(mx, x);
        }
        else 
            x--;
    }
    cout << mx << endl;
    return 0;
}
