#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int g = a[0];
    rep(i,n) {
        cin >> a[i];
        g = __gcd(g, a[i]);
    }
    sort(all(a));
    if(k > a[n-1]){ cout << "IMPOSSIBLE" << endl; return 0;}
    if(k%g==0) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;
    return 0;
}