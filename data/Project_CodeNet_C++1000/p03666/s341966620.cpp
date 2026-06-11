#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i < n; i++)
#define elif else if
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll MOD2 = 998244353;
const ll INF = 1e15;

int main(){
    ll N, A, B, C, D, x, s, c, d;
    cin >> N >> A >> B >> C >> D;
    x = max(A-B, B-A);
    s = C + D;
    c = x + (N-1)*C;
    d = x + (N-1)*D;
    bool able = false;
    if(c%s == 0){
        if(c <= (N-1)*s) able = true;
    }
    else{
        if(c/s < d/s && c < (N-1)*s) able = true;
    }
    if(able) cout << "YES" << endl;
    else cout << "NO" << endl;
}