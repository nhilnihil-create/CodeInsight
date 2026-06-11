#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,c) for (int i = 0; i < (int)c; i++)
#define all(v) v.begin(), v.end()
const int inf = 1000000000; //10^9
using ll = long long;
using P = pair<int,int>;
//加算代入演算子は+=！！！！！


int main() {
    int a, b, h;
    cin >> a >> b >> h;
    int ans;
    ans = ((a + b) * h) / 2;
    cout << ans << endl;
}