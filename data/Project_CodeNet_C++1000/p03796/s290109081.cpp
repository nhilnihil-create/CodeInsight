
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;



int main(){
    int n;
    cin >> n;
    const ll mod=1e9+7;

    ll ans=1;
    for(int i=1; i<=n; i++){
        ans = ans*i%mod;
    }
   cout << ans << endl;

}