#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    int mx = 0;
    rep(i,n){
        cin >> a[i];
        mx = max(mx,a[i]);
    }
    int g=a[0];
    for(int i = 1;i<=n-1;i++) g = __gcd(g,a[i]);

    if((mx-k)%g == 0 && k<=mx) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;
}
