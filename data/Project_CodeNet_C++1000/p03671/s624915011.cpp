#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<vector<int>> Graph;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

int main() {
    int a, b, c; cin >> a >> b >> c;
    if(min(min(a, b), c) == a) cout << a + min(b, c) << endl;
    else if(min(min(a, b), c) == b) cout << b + min(a, c) << endl;
    else cout << c + min(a, b) << endl;    
    return 0;
}