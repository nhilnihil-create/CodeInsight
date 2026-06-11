#include <bits/stdc++.h>
using intl = long long;
using ld = long double;
using namespace std;
#define rep(i, n) for(intl i = 0; i < (intl)(n); i++)
#define repd(i, n) for(intl i = (intl)(n); i >= 0; i--)
#define repi(i, a, b) for(intl i = (intl)(a); i < (intl)(b); i++)
#define repid(i, a, b) for(intl i = (intl)(a); i >= (intl)(b); i--)
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define all(x) (x).begin,(x).end()
#define m0(x) memset(x,0,sizeof(x))
#define fill(x,y) memset(x,y,sizeof(x))
#define length(a) (sizeof(a) / sizeof(a[0]))
#define cin(i, a) rep(i, length(a))cin >> a[i]
#define ccin(i, j, a) rep(i, length(a))rep(j, length(a[i]))cin >> a[i][j]
#define debug(x) cout << #x << ":" << x << endl
#define sqrtl sqrt
#define pb push_back
#define mp make_pair
const intl INF = 1e9;
const intl MOD = 1e9+7;
const ld eps = 1.0e-14;//-9
void fp(bool flag){
    if(flag)cout << "Yes" << endl;
    else cout << "No" << endl;
}
int main(){
    intl n;
    cin >> n;
    if(n >= 1200)cout << "ARC" << endl;
    else cout <<"ABC" << endl;
    return 0;
}