#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i < (n+1); ++i)
using namespace std;
using ll = long long;
const int INF = +100100100;
typedef pair<ll,ll> P;
const ll MO = 1000000007;

int main(){
    ll n,m;
    cin >> n >>m;
    ll ans=0;
    if(2*n>=m){
        ans = m/2;
    }else{
        ans += n;
        m-=2*n;
        ans+=m/4;
    }
    cout << ans << endl;
    return 0;
}