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
    int n;
    ll T;
    cin >> n >> T;
    vector<ll> t(n);
    rep(i, n) cin >> t[i];

    ll sum = 0;
    for (int i=0;i<n-1;++i) {
        sum += min(T, t[i + 1] - t[i]);
    }
    sum += T;

    cout << sum << endl;
}