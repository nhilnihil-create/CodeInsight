#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;
const ll MOD = 1000000007;
// const ll INF = 1000000000000000000LL;


int main(){
    ll a,b,x;
    cin >> a >> b >> x;
    ll ans;
    ans = b/x-a/x;
    if(a%x==0)
        ans++;
    cout << ans << endl;
}
