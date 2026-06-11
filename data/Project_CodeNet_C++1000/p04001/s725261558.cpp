#include<bits/stdc++.h>
using namespace std;
#define arep(i,x,n) for(int i=int(x);i<(int)(n);i++)
#define rep(i,n) for(long long i = 0;i < n;++i)
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9+7  
using ll = long long;
using P = pair<int, int>;
using lP = pair<ll, ll>;
using fP = pair<double, double>;
ll const mod = 998244353;
const ll MAX = 300000;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int>num(n);
    rep(i, n)num[i] = s[i] - '0';
    ll sum = 0;
    rep(i, 1 << (n-1)) {
        
        ll div = num[0];
        rep(j, n-1) {
            if (i >> j & 1) {
                sum += div;
                div = num[j + 1];
            }
            else div = div * 10 + num[j + 1];
        }
        sum += div;
    }
    cout << sum << endl;
    return 0;
}