#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long ;
int main(){
    int n;
    ll ans=1;
    cin >> n;
    for(int i=1; i<=n; i++){
        ans = ans*i%1000000007;
    }
    cout << ans << endl;
}