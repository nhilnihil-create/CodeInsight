#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;
const ll INF = 1001001001;
const ll MOD = 1000000007;

ll n, a, b, c, d, ans=0, tmp=0;
vector<ll> A, negp, posp;

signed main(){
    cin >> n >> a >> b >> c >> d;
    b -= a;
    for(int i=0;i<n;i++) {
        negp.push_back(-n+1+i);
        posp.push_back(i);
    }
    for(int i=0;i<n;i++) {
        ll num1 = negp[i]*c+posp[i]*d;
        ll num2 = negp[i]*d+posp[i]*c;
        if(num2<=b&&num1>=b) tmp++;
        //cout << num1 << " <= " << b << " <= " << num2 << endl;
    }
    if(tmp>0) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}