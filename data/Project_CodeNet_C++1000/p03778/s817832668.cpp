#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int main() {
    int w, a, b; cin >> w >> a >> b;
    int ans = 0;
    if(a+w < b) ans = b - a - w;
    else if(b+w < a) ans = a - b - w;
    cout << ans;
}
