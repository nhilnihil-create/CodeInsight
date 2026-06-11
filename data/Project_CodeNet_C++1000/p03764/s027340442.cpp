#include<bits/stdc++.h>
#define EM 100000000
using namespace std;
using LL = long long;
using P = pair<LL, LL>;
LL LINF = 1e18;
int INF = 1e9;
using vint = vector<int>;
using vLL = vector<LL>;

int main(){
    LL n, m;
    cin >> n >> m;
    vector<LL> x(n), y(m);
    for(int i = 0; i < n;i++)   cin >> x[i];
    for(int i = 0; i < m;i++)   cin >> y[i];
    LL mod = 1e9+7;
    LL ans1 = 0;
    for(int i = 0;i < n;i++){
        ans1 += i*x[i]-(n-i-1)*x[i];
        ans1 %= mod;
    }
    LL ans2 = 0;
    for(int i = 0;i < m;i++){
        ans2 += i*y[i]-(m-i-1)*y[i];
        ans2 %= mod;
    }
    LL ans = ans1*ans2%mod;
    cout << ans << endl;
}