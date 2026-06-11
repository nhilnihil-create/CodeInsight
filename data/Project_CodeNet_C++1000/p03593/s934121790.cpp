#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;


int main(){
    int h, w;
    cin >> h >> w;
    
    vector<int> a(26);
    rep(i, h*w){
        char c; cin >> c;
        a[c-'a']++;
    }

    int p = 0, q = 0;
    rep(i, 26){
        if (a[i] % 4 != 0) p++;
        if (a[i] % 2 != 0) q++;
    }

    int t = ((h%2) * w + (w%2) * h) / 2;

    if (q <= 1 & p <= t) cout << "Yes" << endl;
    else cout << "No" << endl;
    

    return 0;
}
