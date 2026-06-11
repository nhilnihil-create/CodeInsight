#include<bits/stdc++.h>
 
#define rep(i,n) for(ll i = 0;i < n;++i)
#define all(v) v.begin(),v.end()
using namespace std;
using ll = long long;
typedef pair<int,int> P;
 
const int INF = 1001001001;
const long double PI = (acos(-1));
const int mod = 1e9+7;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,k;
    cin >> n >> k;
    ll ans;
    ans = k;
    ll aa = pow(k-1,n-1);
    ans *= aa;
    cout << ans << endl;

    cout << endl;
    return 0;
}
