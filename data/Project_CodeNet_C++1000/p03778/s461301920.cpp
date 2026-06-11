#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    int w, a, b;
    cin >> w >> a >> b;
    if(b > a + w) cout << b - a - w << endl;
    else if(b + w < a) cout << a - b - w << endl;
    else cout << 0 << endl;
    return 0;
}