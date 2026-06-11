#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a > d || b < c) cout << 0 << endl;
    else if (a >= c) {
        if(b <= d) cout << b - a << endl;
        else cout << d - a << endl;
    } 
    else {
        if(b <= d) cout << b - c << endl;
        else cout << d - c << endl;
    }
    return 0;
}