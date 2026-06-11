#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define all(x) (x).begin(),(x).end()

using namespace std;
using ll = long long;
using P = pair<int, int>;

const int INF = 1001001001;
const vector<int> di = {-1,  0, 1, 0};
const vector<int> dj = { 0, -1, 0, 1};

void chmin(int &a, int b) { if (a > b) a = b; }

ll GCD(ll a, ll b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}
ll LCM(ll a, ll b) { return a * b / GCD(a, b); }


int main(){
    ll x;
    cin >> x;

    ll ans = 0;
 
    if (x % 11 > 6) {
        ans = (x / 11) * 2 + 2;
    } else if (x % 11 > 0) {
        ans = (x / 11) * 2 + 1;
    } else {
        ans = (x / 11) * 2;
    }

    cout << ans << endl;
}