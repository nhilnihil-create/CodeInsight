#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    int mx=0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mx=max(a[i],mx);
    }

    int g=a[0];
    for(int i = 1; i < n; i++) {
        g=__gcd(a[i],g);
    }

    if(k>mx){
        cout << "IMPOSSIBLE" << "\n";
        return 0;
    }
    if((mx-k)%g==0) cout << "POSSIBLE" << "\n";
    else            cout << "IMPOSSIBLE" << "\n";

    return 0;
}