#include <bits/stdc++.h>
#define MAXN 100100
#define pii  pair<int, int>
#define pll  pair<long long, long long>
#define ss second
#define ff first
 
using ll = long long;
using namespace std;
const int mod = 1e9 + 7;

int main(){
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    x = abs(a - x);
    y = abs(b - y);
    string ans;
    ans.append(x, 'R');
    ans.append(y, 'U');
    ans.append(x, 'L');
    ans.append(y, 'D');
    ans.append(1, 'D');
    ans.append(x + 1, 'R');
    ans.append(y+1, 'U');
    ans.append(1, 'L');
    ans.append(1, 'U');
    ans.append(x + 1, 'L');
    ans.append(y + 1, 'D');
    ans.append(1, 'R');

    cout << ans << endl;
    return 0;
}