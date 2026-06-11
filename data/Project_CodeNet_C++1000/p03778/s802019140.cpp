#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int w, a, b;
    cin >> w >> a >> b;
    if(abs(a-b)<=w) { cout << 0 << endl; return 0;}
    int ans = abs(a-b)-w;
    cout << ans << endl;
    return 0;
}