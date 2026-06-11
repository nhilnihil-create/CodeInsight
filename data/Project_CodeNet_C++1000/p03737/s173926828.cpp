#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
#define all(v) v.begin(), v.end()
using ll = long long;
using P = pair<int, int>;
const int inf = 1000000000; //10^9
const ll MOD = 1e9 + 7;
//加算代入演算子は+=！！！！！
//int 2^31 10^9まで
int main()
{
    string a, b, c;
    cin >> a >> b >> c;
    a[0] = toupper(a[0]);
    b[0] = toupper(b[0]);
    c[0] = toupper(c[0]);
    cout << a[0] << b[0] << c[0] << endl;
    return 0;
}