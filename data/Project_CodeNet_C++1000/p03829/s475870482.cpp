#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using pint = pair<int,int>;
ll mod = 1000000007,mod2 = 998244353;

void chmin(long long &a, long long b) { if (a > b) a = b; }
void chmax(long long &a, long long b) { if (a < b) a = b; }
const long long INF = 1LL<<60;
ll gcd(ll a,ll b){
    if(b == 0) return a;
    else return gcd(b,a%b);
}

int main() {
    ll n,a,b,ans = 0;
    cin >> n >> a >> b;
    vector<ll> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    for (int i = 0; i < n-1; ++i) {
        ans += min(a*(x[i+1]-x[i]),b);
    }
    cout << ans << endl;
    return 0;
}