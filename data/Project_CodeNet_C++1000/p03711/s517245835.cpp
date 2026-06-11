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
    int x, y; cin >> x >> y;
    set<int> a, b, c;
    a.insert(1); a.insert(3); a.insert(5); a.insert(7);
    a.insert(8); a.insert(10); a.insert(12);
    b.insert(4); b.insert(6); b.insert(9); b.insert(11);
    c.insert(2);
    if((a.count(x) && a.count(y)) || (b.count(x) && b.count(y)) || (c.count(x) && c.count(y))) cout << "Yes" << endl;
    else cout << "No" << endl; 
    return 0;
}