#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int a, b;
    cin >> a >> b;
    int ans = a + b;
    if(ans >= 24) ans-=24;
    cout << ans << endl;
    return 0;
}